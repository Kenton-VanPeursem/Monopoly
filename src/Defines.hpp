#pragma once

#include <stdlib.h>

enum e_family
{
    DARK_PURPLE,
    LIGHT_BLUE,
    LIGHT_PURPLE,
    ORANGE,
    RED,
    YELLOW,
    GREEN,
    DARK_BLUE,
    BLACK,
    WHITE,
    SIZE
};

// extern long completeness[e_family::SIZE] = {2, 3, 3, 3, 3, 3, 3, 2, 4, 2};

enum e_type
{
    GO,
    JAIL,
    FREE_PARKING,
    GOTO_JAIL,
    CHANCE,
    COMMUNITY_CHEST,
    INCOME_TAX,
    LUXURY_TAX,
    PROPERTY
};

enum e_card
{
    MOVE,
    COLLECT,
    PAY,
    JAIL_FREE
};

long Roll();