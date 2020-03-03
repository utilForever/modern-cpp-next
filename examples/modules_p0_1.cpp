#include <cstdio>

int main(int argc, char* argv[]) {
    for (auto i = 0; i < argc; ++i)
        fputs(argv[i], stdout);
    return 0;
}
