#!/usr/bin/env bash

set -ueo pipefail

# reset getopts variable
OPTIND=1

#base project directory
CURRENT_DIR=`pwd`
SRC_DIR="$CURRENT_DIR/.."
BUILD_DIR="$CURRENT_DIR/../build"
OS=`uname -s`

function build() {
    cd $BUILD_DIR
    make
}

function clean() {
    cd $BUILD_DIR
    make clean
}

function clear() {
    if [ -d "$BUILD_DIR" ]; then
        printf '%s\n' "Removing directory ($BUILD_DIR)"
        rm -rf $BUILD_DIR
    fi

    CMAKE_ADDITIONAL_OPTIONS=""

    if [ "$OS" == "Darwin" ]; then
        echo "Darwin build"
        CMAKE_ADDITIONAL_OPTIONS="-DCMAKE_MODULE_PATH=/opt/local/share/cmake/Modules/"
    elif [ "$OS" == "Linux" ]; then
        echo "Linux build"
        CMAKE_ADDITIONAL_OPTIONS=""
    fi
    mkdir -p $BUILD_DIR
    cd $BUILD_DIR
    cmake $SRC_DIR $CMAKE_ADDITIONAL_OPTIONS
}

function run() {
    $BUILD_DIR"/src/"PJC
}

while getopts ":cbrxh" opt; do
    case "$opt" in
    c) clean
        ;;
    b) build
        ;;
    r) run
        ;;
    x) clear
        ;;
    t) test
        ;;
    h)  echo "HELP message"
        echo "-c clean"
        echo "-b build"
        echo "-r run with no command line parameters"
        echo "-x clear"
        ;;
    \?) echo "unknown option"
        ;;
    esac
done

shift $((OPTIND-1))
