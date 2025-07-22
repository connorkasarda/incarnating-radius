#!/usr/bin/env bash

# Find repository's root-level directory
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT_DIR="$(cd "$SCRIPT_DIR/.." && pwd)"

# Load modules
source "$SCRIPT_DIR/logging.sh"

# Change working directory to root-level directory of repo
pushd "$ROOT_DIR" > /dev/null

# Define defaults for options
SOURCE_PATH="."
BUILD_PATH="build"
CONFIG="Debug"
SHOW_WDEV=false
WERROR_DEV=false
TRACE=false
LOG_LEVEL="STATUS"

# Display help message function
print_usage()
{
    echo "Usage: $(basename "$0") [OPTIONS]"
    echo ""
    echo "Description: This script configures the build pipeline using CMake."
    echo ""
    echo "Options:"
    echo "  -s, --src-dir [PATH]        Specify where root-level CMake script is located (default: .)"
    echo "  -b, --build-loc [PATH]      Specify the build folder path (default: build)"
    echo "  -c, --config [BUILD TYPE]   Configure the build type for pipeline (e.g. Debug, Release, RelWithDebInfo, MinSizeRel)"
    echo "  -w, --wdev                  Enable CMake's developer warnings"
    echo "  -e, --werror-dev            Render developer warnings as errors"
    echo "  -t, --trace                 Print out every executed line of CMake code"
    echo "  -l, --log-level [LEVEL]     Specify which CMake messages are displayed (e.g. ERROR, WARNING, NOTICE, STATUS, VERBOSE, DEBUG, TRACE)"
    echo "  -d, --debug                 Enable debug log messages for script run"
    echo "  -h, --help                  Prints usage message for tis configure script"
    exit 0;
}

# Parse arguments passed in for build system configure step
while [[ $# -gt 0 ]]; do
    case "$1" in
        -s|--src-dir) SOURCE_PATH="$2"; shift 2 ;;
        -b|--build-loc) BUILD_PATH="$2"; shift 2 ;;
        -c|--config) CONFIG="$2"; shift 2 ;; 
        -w|--wdev) SHOW_WDEV=true; shift ;;
        -e|--werror-dev) WERROR_DEV=true; shift ;;
        -t|--trace) TRACE=true; shift ;;
        -l|--log-level) LOG_LEVEL="$2"; shift 2 ;;
        -d|--debug) DEBUG=true; shift ;;
        -h|--help) print_usage ;;
        --) shift; break ;;
        -*) log_error "Unknown option: $1"; print_usage; exit 1 ;;
    esac
done

# Run safety checks on options passed in
log_debug "Parsed options:"
log_debug "  Source directory:           $SOURCE_PATH"
log_debug "  Build directory:            $BUILD_PATH"
log_debug "  Build configuration:        $CONFIG"
log_debug "  Developer warnings enabled: $SHOW_WDEV"
log_debug "  Treat warnings as errors:   $WERROR_DEV"
log_debug "  Trace enabled:              $TRACE"
log_debug "  Log level:                  $LOG_LEVEL"
log_debug "  Debug mode:                 $DEBUG"
# TODO validate_option() function?
if [[ "$CONFIG" != "Debug" && \
      "$CONFIG" != "Release" && \
      "$CONFIG" != "RelWithDebInfo" && \
      "$CONFIG" != "MinSizeRel" ]]; then
    log_error "Invalid CMake configuration type: $CONFIG"
    log_error "  Valid options: Debug, Release, RelWithDebInfo, MinSizeRel"
    exit 1
fi
if [[ "$LOG_LEVEL" != "ERROR" && \
      "$LOG_LEVEL" != "WARNING" && \
      "$LOG_LEVEL" != "NOTICE" && \
      "$LOG_LEVEL" != "STATUS" && \
      "$LOG_LEVEL" != "VERBOSE" && \
      "$LOG_LEVEL" != "DEBUG" && \
      "$LOG_LEVEL" != "TRACE" ]]; then
    log_error "Invalid CMake log level: $LOG_LEVEL"
    log_error "  Valid options: ERROR, WARNING, NOTICE, STATUS, VERBOSE, DEBUG, TRACE"
    exit 1
fi

# Construct cmake's configure run
mkdir -p "$BUILD_PATH"
ABS_BUILD_PATH="$(cd "$BUILD_PATH" && pwd)"
ABS_SOURCE_PATH="$(cd "$SOURCE_PATH" && pwd)"
cmd=(cmake -B "$ABS_BUILD_PATH" -S "$ABS_SOURCE_PATH" -DCMAKE_BUILD_TYPE="$CONFIG")
# TODO function?
if [ "$SHOW_WDEV" = true ]; then
    cmd+=(-Wdev)
    CMAKE_DEV_WARN_MSG="Enabled"
else
    CMAKE_DEV_WARN_MSG="Disabled"
fi
if [ "$WERROR_DEV" = true ]; then
    cmd+=(-Werror=dev)
    CMAKE_WARN_ERR_MSG="Enabled"
else
    CMAKE_WARN_ERR_MSG="Disabled"
fi
if [ "$TRACE" = true ]; then
    cmd+=(--trace)
    CMAKE_TRACE_MSG="Enabled"
else
    CMAKE_TRACE_MSG="Disabled"
fi
if [ -n "$LOG_LEVEL" ]; then
    cmd+=(--log-level="$LOG_LEVEL")
    CMAKE_LOG_LVL_MSG="$LOG_LEVEL"
else
    CMAKE_LOG_LVL_MSG="None"
fi
log_debug "Constructed cmake command: "
log_debug "  $(printf '%q ' "${cmd[@]}")"

# Expose accepted options
log_info "Running script:                                 $SCRIPT_DIR/$(basename "$0")"
log_info "  Script executing from:                        $(cd "$ROOT_DIR" && pwd)"
log_info "  Path containing source (root-level CMake):    $ABS_SOURCE_PATH"
log_info "  Build directory:                              $ABS_BUILD_PATH"
log_info "  CMake build configuration:                    $CONFIG"
log_info "  CMake developer warnings enabled:             $CMAKE_DEV_WARN_MSG"
log_info "  Treating CMake developer warnings as errors:  $CMAKE_WARN_ERR_MSG"
log_info "  CMake tracing:                                $CMAKE_TRACE_MSG"
log_info "  CMake logging level:                          $CMAKE_LOG_LVL_MSG"

# Execute
log_info "Executing CMake configuration step..."
"${cmd[@]}"

# Leave the root-level directory
popd > /dev/null
