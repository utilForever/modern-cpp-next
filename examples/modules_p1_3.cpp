/// @file examples/module_p1_3.cpp
#include <cstdint>
module m1; // `endpoint_t` becomes visible
           // since it's purview of `m1`

uint16_t lookup(endpoint_t* base, uint16_t capacity, //
                const char* hostname,                //
                const char* servname) noexcept {
    return 0;
}
