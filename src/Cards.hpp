#pragma once

#include <string>
#include <queue>
#include "Defines.hpp"

extern const long stack_size;

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

    void Shuffle();
    void GetCard(card *it);

    private:
    card stack[stack_size];
    std::queue<card*> pile;
};