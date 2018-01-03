#include "Defines.hpp"

bool Roll(long &dice)
{
    bool doubles = false;
    long die1, die2;

    do
    {
        die1 = rand() % 7;
    } while (die1 == 0);

    do
    {
        die2 = rand() % 7;
    } while (die2 == 0);

    if (die1 == die2) doubles = true;

    dice = die1 + die2;

    return doubles;
}