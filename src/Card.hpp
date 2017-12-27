#pragma once

#include <string>
#include <queue>
#include "Defines.hpp"

struct card
{
    e_card type;
    long amount1;
    long amount2;
    std::string description;
    long flag;
};

class Cards
{
    public:
    Cards(e_type type);
    virtual ~Cards() {;};

    private:
    std::queue<card> stack;
};