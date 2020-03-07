# C++ Modules

아직 C++ Modules의 모든 내용을 시험해볼 수 있는 것은 아니지만, 대략적인 내용을 확인하는 것은 어렵지 않습니다.

### 준비

* Clang 컴파일러 (LLVM 9.0+, AppleClang 11.0+)
* [GNU Make](https://www.gnu.org/software/make/manual/make.html): http://wiki.kldp.org/KoreanDoc/html/GNU-Make/GNU-Make.html

## Overview

### Modules에서 해결하려는 문제는 무엇일까? (Why)

#### 컴파일 속도 개선

컴파일 속도가 느려진 원인은 전처리 결과로 생성된 소스코드(Translation Unit)이 그만큼 커졌기 때문이다.
이러한 코드 증가는 전처리기(`#include`)에 의한 코드 복제가 널리 사용될수록 영향이 커진다.

### Modules의 접근법은 무엇일까? (What)

#### 코드 복제의 대안(Alternative) 제시

전처리기를 사용해 소스코드를 복제했던 이유는 선언(Declaration)을 재사용하기 위함이었으므로, 
Modules에서는 소스코드 없이도 선언을 재사용할 수 있는 방법을 제공한다.

### Modules는 어떻게 사용할 수 있을까? (How)

Modules의 목표(?)는 선언을 재사용할 수 있도록 하는 것이므로, 다음의 3가지를 지원한다.

* 재사용할 수 있는 선언을 구분할 수 있어야 한다: `export`
* 선언을 집단화 할 수 있어야 한다: `module`
* 원하는 선언(혹은 그 집합)을 가져올 수 있어야 한다: `import`

#### Module Unit

* `module` 선언이 있으면 이후(Purview)의 선언들은 해당 module에 속한다.
* `export module` 선언이 있으면 _Module Interface Unit_ 이 되며, 그 외에는 _Module Implementation Unit_ 이 된다.
* 같은 module에서만 사용할 수 있는 unit을 _module partition_ 이라고 한다.

#### Global Module

* `module`선언이 없는 _Translation Unit_ 들은 Global Module Fragment에 속한다.
* _Global Module_ 은 모든 Global Module Framgmentd의 집합이다.

#### Reachability

* 임의의 모듈을 `import`하면, 해당 모듈의 선언들과 그 선언들에 필요한 다른 모듈들의 선언을 사용할 수 있다(Reachable).

## References

### C++ Standard

[N4835](https://github.com/cplusplus/draft/tree/master/papers)를 기반으로 작성되었습니다. [https://github.com/cplusplus/draft](https://github.com/cplusplus/draft) 에서 다른 문서를 확인하실 수 있습니다.

* ...

### Web

* https://stackoverflow.com/questions/33307657/how-do-i-use-c-modules-in-clang
* https://vector-of-bool.github.io/2019/03/10/modules-1.html
* https://vector-of-bool.github.io/2019/03/31/modules-2.html
* https://vector-of-bool.github.io/2019/10/07/modules-3.html
* https://quuxplusone.github.io/blog/2019/11/07/modular-hello-world/

### Video

* CppCon 2019: Gabriel Dos Reis ["Programming with C++ Modules: Guide for the Working"](https://www.youtube.com/watch?v=tjSuKOz5HK4)
* ...

