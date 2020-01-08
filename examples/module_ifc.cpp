
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
