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
