#!/usr/bin/env bash

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT_DIR="$(cd "$SCRIPT_DIR/.." && pwd)"

SOURCE_PATH="$ROOT_DIR"
BUILD_PATH="build"
SHOW_WDEV=false
WERROR_DEV=false
TRACE=false
LOG_LEVEL=""
CMAKE_DEFS=()

print_usage()
{
    echo "Usage: $(basename "$0") [options]"
}

# Parse arguments passed in for build system configure step
while [[ $# -gt 0 ]]; do
    case "$1" in
        -s|--src-path) SOURCE_PATH="$2"; shift 2 ;;
        -b|--build-path) BUILD_PATH="$2"; shift 2 ;;
        -w|--wdev) SHOW_WDEV=true; shift ;;
        -e|--werror-dev) WERROR_DEV=true; shift ;;
        -t|--trace) TRACE=true; shift ;;
        -l|--log-level) LOG_LEVEL="$2"; shift 2 ;;
        -d|--cmake-defs) CMAKE_DEFS+=("-D$2"); shift 2 ;;
        -h|--help) print_usage; exit 1 ;;
        --) shift; break ;;
        -*) echo "Unknown option: $1"; print_usage; exit 1 ;;
    esac
done

# TODO Run safety checks on options passed in


# Execute cmake's configure step
cmd=(cmake -B "$BUILD_PATH" -S "$SOURCE_PATH")
$SHOW_WDEV && cmd+=(-Wdev)
$WERROR_DEV && cmd+=(-Werror=dev)
$TRACE && cmd+=(--trace)
[[ -n "$LOV_LEVEL" ]] && cmd+=(--log-level="$LOG_LEVEL")
[[ ${#CMAKE_DEFS[@]} -gt 0 ]] && cmd+=("${CMAKE_DEFS[@]}")
"${cmd[@]}"
