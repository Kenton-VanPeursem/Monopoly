#include "Board.hpp"

int main()
{
    long location;
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