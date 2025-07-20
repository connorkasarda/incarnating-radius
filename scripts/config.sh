#!/usr/bin/env bash

# Find repository's root-level directory
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT_DIR="$(cd "$SCRIPT_DIR/.." && pwd)"

# Change working directory to root-level directory of repo
pushd "$ROOT_DIR" > /dev/null

# Define defaults for options
SOURCE_PATH="."
BUILD_PATH="build"
SHOW_WDEV=false
WERROR_DEV=false
TRACE=false
LOG_LEVEL=""
CMAKE_DEFS=()

# Display help message function
print_usage()
{
    echo "Usage: $(basename "$0") [OPTIONS]"
    echo ""
    echo "Description: This script configures the build pipeline."
    echo ""
    echo "Options:"
    echo "  -s, --src-dir [PATH]        Specify where root-level CMake script is located (default: .)"
    echo "  -b, --build-loc [PATH]      Specify the build folder path (default: build)"
    echo "  -w, --wdev                  Enable CMake's developer warnings"
    echo "  -e, --werror-dev            Render developer warnings as errors"
    echo "  -t, --trace                 Print out every executed line of CMake code"
    echo "  -l, --log-level [LEVEL]     Specify which CMake messages are displayed (e.g. VERBOSE, NOTICE, STATUS, WARNING, ...)"
    echo "  -d, --cmake-def [DEF]       Define a CMake definition (e.g. CMAKE_BUILD_TYPE=\"Debug\")"
    echo "  -h, --help                  Prints usage message for tis configure script"
    exit 0;
}

# Parse arguments passed in for build system configure step
while [[ $# -gt 0 ]]; do
    case "$1" in
        -s|--src-dir) SOURCE_PATH="$2"; shift 2 ;;
        -b|--build-loc) BUILD_PATH="$2"; shift 2 ;;
        -w|--wdev) SHOW_WDEV=true; shift ;;
        -e|--werror-dev) WERROR_DEV=true; shift ;;
        -t|--trace) TRACE=true; shift ;;
        -l|--log-level) LOG_LEVEL="$2"; shift 2 ;;
        -d|--cmake-def) CMAKE_DEFS+=("-D$2"); shift 2 ;;
        -h|--help) print_usage ;;
        --) shift; break ;;
        -*) echo "Unknown option: $1"; print_usage; exit 1 ;;
    esac
done

# TODO Run safety checks on options passed in


# Construct cmake's configure run
mkdir -p "$BUILD_PATH"
ABS_BUILD_PATH="$(cd "$BUILD_PATH" && pwd)"
ABS_SOURCE_PATH="$(cd "$SOURCE_PATH" && pwd)"
cmd=(cmake -B "$ABS_BUILD_PATH" -S "$ABS_SOURCE_PATH")
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
if [ ${#CMAKE_DEFS[@]} -gt 0 ]; then
    cmd+=("${CMAKE_DEFS[@]}")
    CMAKE_DEFS_MSG="${CMAKE_DEFS[@]}"
else
    CMAKE_DEFS_MSG="None"
fi

# Expose accepted options
echo "executing $(basename "$0") from $(cd "$ROOT_DIR" && pwd)"
echo "  source directory:               $ABS_SOURCE_PATH"
echo "  build path:                     $ABS_BUILD_PATH"
echo "  developer warnings:             $CMAKE_DEV_WARN_MSG"
echo "  developer warnings as errors:   $CMAKE_WARN_ERR_MSG"
echo "  trace:                          $CMAKE_TRACE_MSG"
echo "  log level:                      $CMAKE_LOG_LVL_MSG"
echo "  cmake definitions:              $CMAKE_DEFS_MSG"

# Execute
"${cmd[@]}"

# Leave the root-level directory
popd > /dev/null
