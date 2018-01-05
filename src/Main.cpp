#include "Board.hpp"
#include <iostream>

using namespace std;

int main() {
    Board Mono;

    Mono.AddPlayer("Kent");
    Mono.AddPlayer("David");

    while (1) {
        Mono.Turn("Kent");
        std::cout << std::endl;
        Mono.Turn("David");
        std::cout << std::endl;
    }

    return 0;
}