#!/bin/bash
set -e
set -v

RUN_LOG="$PWD/run.log"
GDB_BT_SCRIPT=`dirname "$PWD/$0"`/gdb_bt_script

exec &> >(tee "${RUN_LOG}")

mkdir -p build
pushd build > /dev/null

cmake .. -DCMAKE_VERBOSE_MAKEFILE=ON
make

popd > /dev/null

export ASAN_OPTIONS=detect_leaks=0
gdb -n -batch -x "${GDB_BT_SCRIPT}" --args ./build/snu_graphics
