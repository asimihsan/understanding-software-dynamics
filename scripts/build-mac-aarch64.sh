#!/usr/bin/env bash

set -euo pipefail

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
pushd "${SCRIPT_DIR}"/.. > /dev/null
trap "popd > /dev/null" EXIT

mkdir -p build/aarch64
cd build/aarch64
cmake -DCMAKE_TOOLCHAIN_FILE=../../cmake/toolchains/aarch64.cmake ../..
make
make
