#include "Board.hpp"
#include <iostream>

using namespace std;

int main()
{
    Board Mono;

    Mono.AddPlayer("Kent");
    Mono.AddPlayer("David");

    while (1)
    {
        Mono.Turn("Kent");
        Mono.Turn("David");
    }

    return 0;
}