### References

* https://stackoverflow.com/questions/33307657/how-do-i-use-c-modules-in-clang
* https://vector-of-bool.github.io/2019/03/10/modules-1.html
* https://vector-of-bool.github.io/2019/03/31/modules-2.html
* https://vector-of-bool.github.io/2019/10/07/modules-3.html
* https://quuxplusone.github.io/blog/2019/11/07/modular-hello-world/


## Note

### Clang

* Version: 9.0.0+

#### module partitions are not yet supported

Given

```cpp
// module_part_1.cpp
module;
#include <cstdint>

// change to next's purview
module next:impl;
```

When

```makefile
CFLAGS 	= -std=c++2a -fmodules-ts
LDFLAGS	= -lstdc++

next_part_1: module_part_1.cpp
	clang-9 -o module_part_1.o $(CFLAGS) $(LDFLAGS) \
		-c $?
```

Then

```console
user@host:~/examples$ make next_part_1
clang-9 -o module_part_1.o -std=c++2a -fmodules-ts -lstdc++ \
        -c module_part_1.cpp
clang: warning: -Z-reserved-lib-stdc++: 'linker' input unused [-Wunused-command-line-argument]
module_part_1.cpp:6:12: error: sorry, module partitions are not yet supported
module next:impl;
           ^~~~~
module_part_1.cpp:6:1: error: definition of module 'next' is not available; use -fmodule-file= to specify path to precompiled module interface
module next:impl;
^
2 errors generated.
Makefile:9: recipe for target 'next_part_1' failed
make: *** [next_part_1] Error 1
```

#### definition of module 'next' is not available

Given

```cpp
// module_part_1.cpp
module; // implement in global module fragment
#include <system_error>

#include <netdb.h>
#include <netinet/in.h>

auto make_system_error(uint32_t ec) noexcept -> std::system_error {
    const auto code = static_cast<int>(ec);
    const auto msg = ::gai_strerror(ec);
    return {code, std::system_category(), msg};
}

uint32_t lookup(const addrinfo& hint, //
                const char* name, const char* serv) noexcept {
    addrinfo* list = nullptr;
    if (auto ec = ::getaddrinfo(name, serv, &hint, &list))
        return ec;
    ::freeaddrinfo(list);
    for (addrinfo* it = list; it != nullptr; it = it->ai_next) {
        // ...
    }
    return 0;
}

module next; // change to next's purview

// nothing
```

When

```makefile
CFLAGS 	= -std=c++2a -fmodules-ts
LDFLAGS	= -lstdc++

next_impl_1: module_impl_1.cpp
	clang-9 -o next_impl.o $(CFLAGS) $(LDFLAGS) \
		-c $?
```

Then

```console
user@host:~/examples$ make next_impl_1
clang-9 -o next_impl.o -std=c++2a -fmodules-ts -lstdc++ \
        -c module_impl_1.cpp
clang: warning: -Z-reserved-lib-stdc++: 'linker' input unused [-Wunused-command-line-argument]
module_impl_1.cpp:44:1: error: definition of module 'next' is not available; use -fmodule-file= to specify path to precompiled module interface
module next;
^
1 error generated.
Makefile:13: recipe for target 'next_impl_1' failed
make: *** [next_impl_1] Error 1
```

#### successful

Given

```cpp
// module_ifc.cpp

/// @see https://en.cppreference.com/w/cpp/preprocessor/replace
#if not defined(__cpp_modules)
#warning "'__cpp_modules' not defined"
#endif

export module next;

#include <cstdint>

/**
 * @brief IP v6 address. 128 bit
 */
export union address_t final {
    uint8_t _u8[16];
    uint16_t _u16[8];
    uint32_t _u32[4];
};

/**
 * @brief IP v6 address + port : 28 byte
 * Values are stored in Host Byte order.
 *
 * @see https://tools.ietf.org/html/rfc5952
 */
export struct endpoint_t final {
    uint16_t family;   // AF_INET6.
    uint16_t port;     // Transport level port number.
    uint32_t flowinfo; // IPv6 flow information.
    address_t addr;    // IPv6 address.
    uint32_t scope_id; // Set of interfaces for a scope.
};

export uint32_t lookup(endpoint_t* base, uint16_t count, //
                       const char* hostname,             //
                       const char* servname) noexcept;

```

```cpp
// module_impl_2.cpp
module; // implement in global module fragment

#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

uint32_t lookup(const addrinfo& hint, //
                const char* name, const char* serv) noexcept {
    addrinfo* list = nullptr;
    if (auto ec = ::getaddrinfo(name, serv, &hint, &list)) {
        ::gai_strerror(ec);
        return ec;
    }
    ::freeaddrinfo(list);
    for (addrinfo* it = list; it != nullptr; it = it->ai_next) {
        // ...
    }
    return 0;
}

// change to next's purview
module next;

uint32_t lookup(endpoint_t* base, uint16_t count, //
                const char* hostname, const char* servname) noexcept {
    addrinfo hint{};
    return lookup(hint, hostname, servname);
}

```


When

```makefile
CFLAGS 	= -std=c++2a -fmodules-ts
LDFLAGS	= -lstdc++

next.pcm:
	clang-9 -o $@ $(LDFLAGS) $(CFLAGS) \
		--precompile -x c++-module module_ifc.cpp

next_impl_2: module_impl_2.cpp
    make next.pcm
	clang-9 $(CFLAGS) $(LDFLAGS) \
	 	-fmodule-file=next.pcm \
		-o next_impl_2.o -c $?
	nm ./next_impl_2.o

	clang-9 $(CFLAGS) $(LDFLAGS) \
		-o main.o -c main.cpp \
		-fprebuilt-module-path=. \
		-fmodule-file=next.pcm
	clang-9 $(CFLAGS) $(LDFLAGS) \
		-o main main.o next_impl_2.o
	nm --demangle ./main | grep endpoint_t 
```

Then

```console
user@host:~/examples$ make next_impl_2
make next.pcm
make[1]: Entering directory '/mnt/c/Users/luncl/source/modern-cpp-next/examples'
clang-9 -lstdc++ -std=c++2a -fmodules-ts \
        -o next.pcm \
        --precompile -x c++-module module_ifc.cpp
clang: warning: -Z-reserved-lib-stdc++: 'linker' input unused [-Wunused-command-line-argument]
module_ifc.cpp:4:2: warning: __cpp_modules not defined" [-W#warnings]
#warning __cpp_modules not defined"
 ^
1 warning generated.
make[1]: Leaving directory '/mnt/c/Users/luncl/source/modern-cpp-next/examples'
clang-9 -std=c++2a -fmodules-ts -lstdc++ \
        -fmodule-file=next.pcm \
        -o next_impl_2.o -c module_impl_2.cpp
clang: warning: -Z-reserved-lib-stdc++: 'linker' input unused [-Wunused-command-line-argument]
nm ./next_impl_2.o
0000000000000000 r GCC_except_table0
00000000000000b0 T _Z6lookupP10endpoint_ttPKcS2_
0000000000000000 T _Z6lookupRK8addrinfoPKcS3_
                 U _ZSt9terminatev
0000000000000000 W __clang_call_terminate
                 U __cxa_begin_catch
                 U __gxx_personality_v0
                 U freeaddrinfo
                 U gai_strerror
                 U getaddrinfo
                 U memset
clang-9 -std=c++2a -fmodules-ts -lstdc++ \
        -o main.o -c main.cpp \
        -fprebuilt-module-path=. \
        -fmodule-file=next.pcm
clang: warning: -Z-reserved-lib-stdc++: 'linker' input unused [-Wunused-command-line-argument]
clang-9 -std=c++2a -fmodules-ts -lstdc++ \
        -o main main.o next_impl_2.o
nm --demangle ./main | grep endpoint_t 
0000000000400b10 T lookup(endpoint_t*, unsigned short, char const*, char const*)
```