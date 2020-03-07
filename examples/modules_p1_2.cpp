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
