#pragma once

#include <string>
#include <queue>
#include "Defines.hpp"

const long stack_size = 16;

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

    void  Shuffle();
    card* GetCard();

    private:
    card stack[stack_size];
    std::queue<card*> pile;
};