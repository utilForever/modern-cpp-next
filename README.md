# Modern C++ Cookbook

###### Documentation and source code for Modern C++ Cookbook

<img src="https://github.com/utilForever/ModernCppCookbook/blob/master/Logo.png" width="256" height="256" align="center" />

## The Book

C++ is one of the most widely used programming languages. Fast, efficient, and flexible, it is used to solve many problems. The latest versions of C++ have seen programmers change the way they code, giving up on the old-fashioned C-style programming and adopting modern C++ instead.

Beginning with the modern language features, each recipe addresses a specific problem, with a discussion that explains the solution and offers insight into how it works. You will learn major concepts about the core programming language as well as common tasks faced while building a wide variety of software. You will learn about concepts such as concurrency, performance, meta-programming, lambda expressions, regular expressions, testing, and many more in the form of recipes. These recipes will ensure you can make your applications robust and fast.

By the end of the book, you will understand the newer aspects of C++11/14/17 and will be able to overcome tasks that are time-consuming or would break your stride while developing.

- Get to know about the new core language features and the problems they were intended to solve
- Understand the standard support for threading and concurrency and know how to put them on work for daily basic tasks
- Leverage C++’s features to get increased robustness and performance
- Explore the widely-used testing frameworks for C++ and implement various useful patterns and idioms
- Work with various types of strings and look at the various aspects of compilation
- Explore functions and callable objects with a focus on modern features
- Leverage the standard library and work with containers, algorithms, and iterators
- Use regular expressions for find and replace string operations
- Take advantage of the new filesystem library to work with files and directories
- Use the new utility additions to the standard library to solve common problems developers encounter including string_view, any , optional and variant types

## Contents

- [Chapter 1: 시작하기](https://github.com/utilForever/ModernCppCookbook/blob/master/Chapter%201%20-%20Get%20Started.md)
    - 1.1 들어가며
    - 1.2 C++ 언어 소개
    - 1.3 설치하기
        - 1.3.1 Visual C++
        - 1.3.2 g++
        - 1.3.3 clang
    - 1.4 사용법 익혀보기
        - 1.4.1 Visual C++
        - 1.4.2 g++
        - 1.4.3 clang
    - 1.5 첫번째 프로그램 : Hello, World
    - 1.6 정리
    - 1.7 연습문제
- [Chapter 2: C++ 기초]
    - 2.1 들어가며
    - 2.2 함수
        - 2.2.1 main 함수
        - 2.2.2 인수
        - 2.2.3 리턴 타입
        - 2.2.4 인라인
        - 2.2.5 오버로딩
    - 2.3 변수와 상수
        - 2.3.1 타입
            - 2.3.1.1 auto
            - 2.3.1.2 decltype
        - 2.3.2 변수
        - 2.3.3 상수
        - 2.3.4 리터럴
        - 2.3.5 타입 변환
            - 2.3.5.1 명시적 변환
                - static_cast
                - dynamic_cast
                - const_cast
                - reinterpret_cast
            - 2.3.5.2 묵시적 변환
            - 2.3.5.3 축소(Narrowing)
        - 2.3.6 범위(Scope)
        - 2.3.7 선언(Declaration)과 정의(Definition)
        - 2.3.8 값의 종류
            - 2.3.8.1 Lvalue
            - 2.3.8.2 Rvalue
    - 2.4 연산자
        - 2.4.1 수치 연산자
        - 2.4.2 논리 연산자
        - 2.4.3 비트 연산자
        - 2.4.4 할당 연산자
        - 2.4.5 비교 연산자
        - 2.4.6 멤버 접근 연산자
        - 2.4.7 기타 연산자
        - 2.4.8 오버로딩
        - 2.4.9 연산자 우선 순위(Precedence)와 결합성(Associativity)
    - 2.5 표현식과 문장
        - 2.5.1 표현식
        - 2.5.2 문장
        - 2.5.3 분기문
            - 2.5.3.1 if
            - 2.5.3.2 switch-case
        - 2.5.4 반복문
            - 2.5.4.1 while
            - 2.5.4.2 do-while
            - 2.5.4.3 for
            - 2.5.4.4 continue, break
        - 2.5.5 goto
    - 2.6 입출력
        - 2.6.1 스트림
        - 2.6.2 표준 출력
        - 2.6.3 표준 입력
        - 2.6.4 파일 입출력
        - 2.6.5 형식 지정
    - 2.7 오류 처리
        - 2.7.1 단정문
        - 2.7.2 예외
            - 2.7.2.1 try
            - 2.7.2.2 catch
            - 2.7.2.3 throw
            - 2.7.2.4 스택 풀기(Stack unwinding)
        - 2.7.3 static_assert
    - 2.8 배열, 포인터, 레퍼런스
        - 2.8.1 배열
        - 2.8.2 포인터
        - 2.8.3 스마트 포인터
            - 2.8.3.1 unique_ptr
            - 2.8.3.2 shared_ptr
            - 2.8.3.3 weak_ptr
        - 2.8.4 레퍼런스
            - 2.8.4.1 Lvalue 레퍼런스
            - 2.8.4.2 Rvalue 레퍼런스
        - 2.8.5 포인터와 레퍼런스의 차이
        - 2.8.6 배열, 포인터, 레퍼런스의 상관 관계
    - 2.9 정리
    - 2.10 연습문제

## License

<img align="right" src="http://opensource.org/trademarks/opensource/OSI-Approved-License-100x137.png">

The class is licensed under the [MIT License](http://opensource.org/licenses/MIT):

Copyright &copy; 2017 [Chris Ohk](http://www.github.com/utilForever).

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.