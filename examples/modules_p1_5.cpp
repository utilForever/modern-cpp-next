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
