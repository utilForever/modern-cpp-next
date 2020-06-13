
## LLVM 프로젝트(libc++, Clang ...)

### 설치방법

You can remove the `clang` if you don't want to install it.
Normally just `libcxx` and `libcxxabi` will be fine.

```bash hl_lines="8 19 23"
#!/bin/bash
branch=${1:-"master"}
install_prefix=$(realpath ${2:-"/usr"})
provider="https://github.com/llvm-mirror"

pushd /tmp
    # get the packages with specified version
    for repo in "llvm" "libcxx" "libcxxabi" "clang"
    do
        # download + unzip one by one
        uri="${provider}/${repo}/archive/${branch}.zip"
        wget -q -O "${repo}.zip" ${uri}
        unzip -u -q "${repo}.zip"
        mv "${repo}-${branch}" "${repo}"
    done

    mkdir -p llvm-build && pushd llvm-build
        cmake ../llvm \
            -DLLVM_ENABLE_PROJECTS="libcxx;libcxxabi;clang" \
            -DCMAKE_INSTALL_PREFIX="${install_prefix}"

        # too many logs. make silent ...
        make -j4 install-clang  2>err-clang.txt
        make -j4 install-cxx    2>err-libcxx.txt
        make -j4 install-cxxabi 2>err-libcxxabi.txt
    popd # leave /tmp/llvm-build
popd # leave /tmp
```

## Ubuntu 환경에서의 컴파일러 설치

> TBA
