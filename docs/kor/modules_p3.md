# C++ Modules의 사용법 - 1

사용법을 다루면서 용어도 같이 짚고 넘어가야 할 것 같습니다.

## Module Unit

### Module Interface Unit

모듈을 만들고 사용하는 것은 먼저 모듈이 노출하는(`export`) 선언들이 모여있는 하나의 TU를 작성하여 컴파일하는 것으로 시작합니다.
이를 _Module Interface Unit_ 이라고 합니다. 
MIU의 작성방법은 굉장히 간단한데, 그저 `export module m1;`를 선언하면, 그 이후의 내용은 전부 `m1`에 귀속됩니다. 이렇게 **암묵적으로** 선언이 귀속되는 범위를 모듈의 _Purview_ 라고 합니다.

예를 들어, 아래 코드의 경우, `endpoint_t`와 `lookup`은 `m1`의 범위(Purview)에 있는 것이죠. 
따라서 이 선언들을 사용하려면 `m1`을 `import` 해야만 합니다.

```c++
/// @file examples/modules_p1_2.cpp
/// @see https://en.cppreference.com/w/cpp/preprocessor/replace
#if not defined(__cpp_modules)
#warning "'__cpp_modules' not defined"
#endif
#include <cstdint>
export module m1; // all following declarations will be in `m1`

export struct endpoint_t {
    uint32_t _u32[4];
};

export uint16_t lookup(endpoint_t* base, uint16_t capacity, //
                       const char* hostname,                //
                       const char* servname) noexcept;
```

모듈의 다른 소스코드를 컴파일하고, 최종적으로 라이브러리 혹은 실행파일을 만들기 위해선 위와 같은 MIU를 먼저 컴파일(precompile) 해야 합니다.

Clang의 경우, 아래와 같이 수행할 수 있습니다.

```console
user@host:~/examples $ clang -x c++-module -std=c++2a -fmodules-ts --precompile -o m1.ifc ./modules_p1_2.cpp 
./modules_p1_2.cpp:4:2: warning: "'__cpp_modules' not
      defined" [-W#warnings]
#warning "'__cpp_modules' not defined"
 ^
1 warning generated.
```

Makefile로 작성한다면 이런 형태가 되겠지요.

```makefile
CXXFLAGS	= -std=c++2a -fmodules-ts

m1.ifc: modules_p1_2.cpp
	clang $(CXXFLAGS) -x c++-module \
		 --precompile -o m1.ifc $?
```

`.ifc` 이라는 확장자는 예약된 것은 아닙니다. 당장은 미리 컴파일된 파일을 위한 임의의 확장자가 있다고 생각하시면 되겠습니다.
아마 이 파일의 규격화(즉, 컴파일러 종속적이지 않은 ifc 파일)는 C++ 20 이후 다소 시간이 지난 후에야 이루어질 수 있을 것입니다.

>
> todo:  
>   * 컴파일러 별 확장자 목록
>

현재로써는 이 파일 안에 어떤 선언들이 들어있는지 확인하는 방법이 없습니다. 하지만 실제로 사용해보면 적법한(valid) 내용이 있는지 확인하는 것은 가능합니다.

1. 구현 코드(module)를 작성해본다
2. 사용 코드(import)를 작성해본다

### Module Implementation Unit

`export` 선언은 MIU에서만 가능하기 때문에, `module m1`의 구현파일들에서는 따로 `export` 키워드를 사용할 일은 없습니다.
단지 `m1`의 범위안에서 구현을 제공하기만 하면 됩니다.
범위를 바꾸는 것은 아래 코드처럼 `module m1;`를 선언하는 것으로 충분합니다.

```c++
/// @file examples/module_p1_3.cpp
#include <cstdint>
module m1; // `endpoint_t` becomes visible
           // since it's purview of `m1`

uint16_t lookup(endpoint_t* base, uint16_t capacity, //
                const char* hostname,                //
                const char* servname) noexcept {
    return 0;
}
```

이 TU에는 `endpoint_t`에 대한 선언이 없지만, `m1`의 범위에 있기 때문에 컴파일이 가능합니다. 이를 Reachable 하다고 표현합니다.  
이는 선언(Declaration)에 대한 것이므로, Linking 과정에서 Symbol에 대한 접근을 제어하는 `-fvisibility`옵션과는 다르다는 점을 숙지할 필요가 있습니다.

모듈 구현 유닛을 위한 컴파일 명령은 일반적인 C++ 소스코드와 유사합니다.
다만, 새로 2개의 옵션을 지정해줄 필요가 있습니다.

* `-fprebuilt-module-path`: .ifc 파일을 찾기 위한 폴더 지정 (선택적)
* `-fmodule-file`: 현재 구현중인 모듈의 .ifc 파일 이름 (필수)

```makefile
CXXFLAGS	= -std=c++2a -fmodules-ts
# ...
m1_impl_1.o: modules_p1_3.cpp
	clang $(CXXFLAGS) \
		-fprebuilt-module-path=/usr/local/include \
		-fprebuilt-module-path=. \
		-fmodule-file=m1.ifc -o m1_impl_1.o -c $?
```

명령을 보면 `-fprebuilt-module-path`는 헤더를 찾을 수 있도록 `-I`옵션을 제공했던 것과 유사합니다.
컴파일 방법을 알았으니, `mi_impl_1.o`파일에서 symbol을 확인해볼 수 있겠군요.

```console
~/examples $ make m1_impl_1.o
clang -std=c++2a -fmodules-ts \
        -fprebuilt-module-path=/usr/local/include \
        -fprebuilt-module-path=. \
        -fmodule-file=m1.ifc -o m1_impl_1.o -c modules_p1_3.cpp
~/examples $ luncliff$ nm --demangle ./m1_impl_1.o 
0000000000000000 T lookup(endpoint_t*, unsigned short, char const*, char const*)
```

> 
> * Q. `-fmodule-file`을 생략하고 컴파일 해보세요! (컴파일 옵션)
> * Q. 소스 코드에서 `module m1;`을 생략한 뒤에 컴파일 오류를 확인하세요! (purview 이해하기)
> * Q. 소스 코드에서 `module m1;`의 위치를 `lookup`함수의 정의보다 아래쪽에 배치하고 컴파일 오류를 확인하세요! (purview 이해하기)
> 

## Module Import

앞선 예제로 확인하셨겠지만, 모듈을 사용하기 시작한다고 해서 헤더파일(즉, 전처리기에 의한 `#include`)를 사용할 수 없게 되는 것은 아닙니다.
다만 컴파일된 모듈 인터페이스가 있다면, `import` 하는 것이 가능하다는 것이죠.

```c++
/// @file examples/modules_p1_5.cpp
#include <array>
#include <iostream>
import m1;

std::array<endpoint_t, 10> endpoints{};

int main(int, char*[]) {
    auto count = lookup(endpoints.data(), endpoints.size(), //
                        "releases.llvm.org", "https");

    std::cout << count << std::endl;
    for (auto i = 0u; i < count; ++i) {
        endpoints[i];
    }
    return count > 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
```

[헤더파일들이 지원하기만 한다면, 헤더파일을 `import`하는 것이 가능합니다](https://youtu.be/tjSuKOz5HK4?t=2286).
`#include`가 코드의 복제인데 반해, `import`는 헤더파일 안에 있는 코드를 한번 처리하여, 그 중간결과물을 다른 TU의 import에서 재사용합니다. 
결과적으로 처리 시간이 좀 더 줄어들게 되겠죠. (안타깝게도 아직은 지원되지 않습니다.)

```c++
import <array>;
import <iostream>;
import m1;
// ...
```

앞서 만들어놓은 `m1`의 구현 object와 함께 빌드하는 것은 아래처럼 할 수 있습니다. (편의상 `-fprebuilt-module-path`를 생략하였습니다.)

```makefile
LDFLAGS		= -lc++
CXXFLAGS	= -std=c++2a -fmodules-ts
# ...
m1_usage: m1_impl_1.o modules_p1_5.cpp
	clang $(CXXFLAGS) $(LDFLAGS) \
		-fmodule-file=m1.ifc $?
```

```console
user@host:~/examples $ make m1_usage
clang -std=c++2a -fmodules-ts -lc++ \
        -fmodule-file=m1.ifc m1_impl_1.o modules_p1_5.cpp
user@host:~/examples $ nm --demangle ./a.out 
0000000100000f6c s GCC_except_table6
                 U __Unwind_Resume
0000000100000bf0 T lookup(endpoint_t*, unsigned short, char const*, char const*)
...
0000000100000c20 T _main
...
```

> TBA
