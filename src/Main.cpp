#include "Board.hpp"
#include <iostream>

using namespace std;

int main() {
    Board Mono;

    Mono.AddPlayer("Kent");
    Mono.AddPlayer("Danielle");
    char ready;
    while (1) {
        Mono.Turn("Kent");
        // std::cout << "\tAre you done with your turn? (y/n)\t";
        // std::cin >> ready;
        // while(ready != 'y') ;
        std::cout << std::endl;

        Mono.Turn("Danielle");
        // std::cout << "\tAre you done with your turn? (y/n)\t";
        // std::cin >> ready;
        // while( ready != 'y') ;
        std::cout << std::endl;
    }

    return 0;
}