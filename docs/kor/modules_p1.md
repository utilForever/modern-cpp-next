# C++ Modules 에서 해결하려는 문제

지금 설명하는 주제에 관심이 있는 분이라면 이미 알고 계시겠지만, 컴파일 언어인 C++에서 프로그램은 1개 이상의 소스코드 파일로 구성됩니다.
소스 코드란, 아래와 같이 C++ 문법에 맞춰 작성한 텍스트를 가리키는 것이구요.

```c++
/// @file examples/modules_p1_1.cpp
#include <cstdio>

int main(int argc, char* argv[]){
    for(auto i = 0; i < argc; ++i)
        fputs(argv[i], stdout);
    return 0;
}
```

```bash
clang -std=c++2a ./modules_p0_1.cpp
```

위와 같이 컴파일러를 호출해서 프로그램을 만들 수 있습니다.
전통에 따라 a.out파일이 만들어질텐데요.
프로그램이란 (천공카드처럼) 일련의 비트이긴 하지만, 소스코드의 의미을 반영하여 Text와 Data로 그 영역이 구분되어 있습니다.

```console
user@host:~/examples $ objdump -syms ./a.out 

./a.out:        file format Mach-O 64-bit x86-64

SYMBOL TABLE:
0000000100002008 l     O __DATA,__data  __dyld_private
0000000100000000 g     F __TEXT,__text  __mh_execute_header
0000000100000f30 g     F __TEXT,__text  _main
0000000000000000         *UND*  ___stdoutp
0000000000000000         *UND*  _fputs
0000000000000000         *UND*  dyld_stub_binder
```

출력 내용을 보면 `a.out`만으로는 알 수 없는 부분도 있지만, 소스코드에 있었던 `main`, `fputs`, `stdout`이 모두 나타난 것을 볼 수 있습니다. (이름이 약간 다른 것 같지만 개의치 마세요!)
컴파일러가 프로그래머의 의도를 (아마도) 잘 해석했다는 것을 짐작할 수 있는 부분입니다.

방금 사용한 `-syms`옵션의 이름처럼, 프로그램은 비트로 만들어져있고, 비트 묶음에는 부호(symbol, 어떠한 뜻을 나타내기 위하여 정한 기호)가 부여됩니다. 부호에 담긴 의미로는 TEXT, DATA 등등이 있는 것이죠.

그리고 컴파일러가 그 부호를 만들기 위해 필요로 하는 것이 바로 선언(Declaration)입니다.
C++ 코드를 구성하는 것 중 가장 많은 부분을 차지하는 부분이죠...

### 전처리 (Preprocessing)

그런데 소스코드마다 필요한 선언들을 작성하고, 이들의 정합(consistency)을 유지해주는 것은 상당히 번거롭기 때문에, 전처리기(Preprocessor)가 사용됩니다.
`#include`와 같은 지시(directive)를 써서 파일의 내용을 복사-붙여넣기 한다거나, `#define`을 써서 특정 문자열을 치환하는 일을 합니다.

좀 전의 코드가 전처리기를 거치면 어떻게 되는지 바로 확인해보도록 하죠. (`-E` 옵션)
전처리기의 동작만 확인할 목적으로 파일을 만들기엔 번거로우니 Pipe를 써서(`|`) 표준 입력으로 소스코드를 제공해보겠습니다. (`-` 옵션)
좀 더 친절하게, 무슨 프로그래밍 언어인지도 알려주도록 하죠. (`-x c++` 옵션)

제 기억에 libc++에서 가장 간단한 헤더는 `<__nullptr>`였던 것 같습니다.

```
user@host:~/examples $ echo "#include <__nullptr>" | clang -x c++ -E -
# 1 "<stdin>"
...
# 18 "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/../include/c++/v1/__nullptr" 3

namespace std { inline namespace __1 {

struct __attribute__ ((__type_visibility__("default"))) nullptr_t
{
    void* __lx;
    // ...
};

inline __attribute__ ((__visibility__("hidden"))) __attribute__ ((internal_linkage)) nullptr_t __get_nullptr_t() {return nullptr_t(0);}

} }
# 2 "<stdin>" 2
```

`std::nullptr_t`가 사실은 `struct`라는 것을 알게된 기쁨(?)은 제쳐두고, 전처리기가 코드를 잘 정리해서 하나의 소스파일로 만들어준다는 것을 알 수 있었습니다.
C++ 에서는 위처럼 **전처리를 거친 소스파일을 Translation Unit이라 합니다**. (편의상 이후로는 TU라고 하겠습니다.)
즉, 이때부터 소스코드가 컴파일(Translation)이 되어 이진(binary) 형태로 바뀌는 것이죠.

* 함께 보기: C++ Standard: 5. Lexical Conventions

### 전처리의 양면성 

#### 밝은 부분

전처리기를 사용해서 얻는 장점은 명확합니다. 

* 소스코드 재작성을 자동화: 선언을 모아놓은 파일(header)의 내용을 복사하도록 함으로써 다시 작성해줄 필요가 없음
* 일률적임: header 파일은 일반적인 소스파일처럼 관리가 가능
* 제어가 가능함: 소스파일을 변경하지 않으면서 TU를 변경할 수 있음(부분적인 활성화/비활성화 등)

헤더 파일을 사용하기 위해선 해당 파일을 찾기 위한 경로를 제공해야 하지만, `/usr/include`와 같이 묵시적으로 사용되는 경로라면 생략이 가능합니다. 컴파일러를 위한 복잡한 옵션이 필요하진 않은 것이죠.
무엇보다 소스파일 내에서서 읽을 수 있는 형태로 드러나기 때문에 프로그래머에게 주는 전달력 또한 상당하다는 점을 들 수 있습니다.

예컨대, 아래의 코드는 별다른 설명 없이도 그 내용을 짐작할 수 있습니다.
그 내용이란, 이 소스파일이 `openssl`이라는 라이브러리의 선언을 사용하며, 선언 중에 `SHA_CTX`, `SHA1_Init`등의 존재를 확인할 수 있다는 의미입니다.

```c++
#include <cstddef>  // C++17 byte
#include <array>    // C++11 array

#include <openssl/sha.h>

using namespace std;

int digest_sha1(FILE* fin, 
                array<byte, SHA_DIGEST_LENGTH>& digest){
    SHA_CTX ctx{};
    SHA1_Init(&ctx);

    auto& buffer = digest; // alias for readability
    while(auto count = fread(buffer.data(), buffer.size(), fin))
        SHA1_Update(&ctx, buffer.data(), count);

    return SHA1_Final(digest.data(), &ctx);
}
```

#### 어두운 부분

하지만 모든 프로그램이 위와 같이 단순하지는 않습니다. 어려움이 발생하는 근본적인 원인으로 2가지를 들 수 있는데,
첫째는 대부분의 프로젝트는 수많은 파일을 사용해 상당한 수의 TU를 생성한다는 것입니다.

...  
결과적으로 소스코드의 양이 늘어나기 때문에 전체 컴파일 시간(즉, 빌드 시간)은 길어지게 될 것입니다.

두번째는 이 TU들의 컴파일 시점이 다를 수 있다는 것입니다.
다음과 같은 상황이 발생한다면 어떨까요?

1. 라이브러리를 개발할 때 의도한 헤더들의 include 순서는 A-B-C 였는데,  
  이를 사용하는 코드에서는 B-A-C 순서로 include 하도록 헤더를 수정하였다.
2. A 헤더에서 `#ifdef` 조건을 사용하고 있었는데,  
  새로 B 헤더가 그 앞에 include 되면서 조건이 반전되었다 (false 였다면 true로 변함. 혹은 그 반대)

위 두 상황이 시사하는 점은, 선언을 모아놓은 헤더 파일은 **변경될 수 있으며(mutable)**, 이것이 전처리기와 같이 **헤더파일에서 제어할 수 없는 요인에 의해 발생할 수 있다**는 것입니다.

전처리기의 장점을 되짚어보면 C++ 프로젝트의 규모가 커지고 의존성이 복잡해질 수록 이같은 문제로 인한 위험이 더 커진다는 것을 예상할 수 있습니다.
물론 오늘날 많은 C++ 라이브러리들은 이 문제를 위한 최소한의 방어법을 적용하고 있습니다.

매크로를 `constexpr` 혹은 `if constexpr`로 대체하면서 전처리기 의존을 낮추고, 사용하게 되더라도 매크로 조건이 충돌하거나 의도한 범위를 넘어서 영향을 주지않도록(`#undef`) 설계하며, 미리 정해진 순서로 부분 헤더파일을 include하는 헤더파일을 제공하기도 합니다. 
하지만 전처리기에 의존하는 이상 이런 문제들은 계속 발생할 수 밖에 없기 때문에 복잡성은 계속 증가하게 됩니다.
