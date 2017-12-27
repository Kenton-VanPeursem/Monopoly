#include "Defines.hpp"

long Roll()
{
    long ret;

    do
    {
        ret = rand() % 13;
    } while (ret < 2);

    return ret;
}