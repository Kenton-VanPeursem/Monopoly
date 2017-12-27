#include "Board.hpp"
#include <iostream>

using namespace std;

int main()
{
    cout << "starting main" << endl;

    long location;
    cout << "declaring board" << endl;
    Board Mono;

    cout << "adding players" << endl;
    Mono.AddPlayer("Kent");
    Mono.AddPlayer("David");

    while (1)
    {
        std::cout << "Kent's Turn:" << endl;
        Mono.Turn("Kent");
        std::cout << "David's Turn:" << endl;
        Mono.Turn("David");
    }

    return 0;
}