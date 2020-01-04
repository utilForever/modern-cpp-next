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

// change to next's purview
module next;
