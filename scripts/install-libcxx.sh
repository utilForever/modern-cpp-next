#!/bin/bash
#
#   Author  : github.com/luncliff (luncliff@gmail.com)
#
branch=${1:-"release_90"}
install_prefix=$(realpath ${2:-"/usr"})

echo "----------------------------------------------------------------------"
echo "                                                                      "
echo " Build/Install libcxx & libcxxabi                                     "
echo "  - http://libcxx.llvm.org/docs/BuildingLibcxx.html                   "
echo "                                                                      "
echo "  - Branch   : ${branch}                                              "
echo "  - Path     : ${install_prefix}/{include, lib}                       "
echo "                                                                      "
echo "----------------------------------------------------------------------"

provider="https://github.com/llvm-mirror"

pushd /tmp
# get the packages with specified version
for repo in "llvm" "libcxx" "libcxxabi"
do
    uri="${provider}/${repo}/archive/${branch}.zip"
    wget -q -O "${repo}.zip" ${uri} &
done
# wait for background downloads
for pid in $(jobs -p); do
    wait $pid
done

for repo in "llvm" "libcxx" "libcxxabi"
do
    unzip -u -q "${repo}.zip"
    mv "${repo}-${branch}" "${repo}"
done

mkdir -p llvm-build && pushd llvm-build
cmake ../llvm \
    -DLLVM_ENABLE_PROJECTS="libcxx;libcxxabi" \
    -DCMAKE_INSTALL_PREFIX="${install_prefix}"
 
# too many logs. make silent ...
make -j4 cxx    2>err-libcxx.txt
make install-cxx
make -j4 cxxabi 2>err-libcxxabi.txt
make install-cxxabi

popd # leave /tmp/llvm-build
popd # leave /tmp
