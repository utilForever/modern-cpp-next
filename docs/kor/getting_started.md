
# C++ 20 시작하기

이 페이지에서는 C++ 20을 사용하기 위해 필요한 것들에 대해 다룹니다.

### Minimal Executable Example

이 저장소의 **실행가능한 코드들은** 다음의 서비스들을 사용해서 용례를 보입니다.

* https://wandbox.org/
* https://godbolt.org/

### Platform

알려진 CI 서비스들에서 제공하는 환경들과 복잡한 절차 없이 설치 가능한 환경을 상정하였습니다.

* Ubuntu Linux 18.04 x86_64 (4.4, 4.15)
* Windows 10 x64 (10.0.18362)
* ...

> TODO: CI 서비스들의 MacOS 버전정보 확인 필요함

### Compiler

특별히 명시되지 않는한, 예제 코드들은 아래의 컴파일러들을 사용합니다. (2020년 1월 기준)

* GCC 9.2.1 (20191102)
* Clang 9.0.0 (20191211)
* MSVC 19.24 x64 (v142, VS 2019)
* AppleClang 11 ([XCode 11](https://developer.apple.com/documentation/xcode_release_notes/xcode_11_release_notes))

#### Standard Library

* `libc++`/`libc++abi`의 버전은 컴파일러와 마찬가지로 [LLVM 의 배포 버전](http://releases.llvm.org/download.html)을 따릅니다.


### Build System

저자들이 사용한 빌드 관련 도구들의 버전은 다음과 같습니다.

* GNU Make 4.1
* CMake 3.12+ 
    * `CXX_STANDARD`에 20을 설정 가능한 최소 버전
* ...
