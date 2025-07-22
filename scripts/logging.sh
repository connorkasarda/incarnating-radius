# Define colors for stylization
RED='\033[0;31m'
YELLOW='\033[0;33m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
MAGENTA='\033[0;35m'
CYAN='\033[0;36m'
WHITE='\033[0;37m'
BLACK='\033[0;30m'
NOCOLOR='\033[0m'

# Configurable variables that alter logs
DEBUG=false

log_timestamp()
{
    date "+%Y-%m-%d %H:%M:%S"
}

log_info()
{
    echo -e "${GREEN}[INFO] ${MAGENTA}$(log_timestamp) ${NOCOLOR}$1"
}

log_warn()
{
    echo -e "${YELLOW}[WARN] ${MAGENTA}$(log_timestamp) ${NOCOLOR}$1" >&2
}

log_error()
{
    echo -e "${RED}[ERROR] ${MAGENTA}$(log_timestamp) ${NOCOLOR}$1" >&2
}

log_debug()
{
    if [[ "$DEBUG" == true ]]; then
        echo -e "${BLUE}[DEBUG] ${MAGENTA}$(log_timestamp) ${NOCOLOR}$1"
    fi
}
