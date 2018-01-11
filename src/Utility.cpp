#include "Player.hpp"
#include "Utility.hpp"
#include <string>

long completeness2[e_family::SIZE] = {2, 3, 3, 3, 3, 3, 3, 2, 4, 2};

Utility::Utility(long location) : Base(location) {}

long Utility::GetRent() {
    long price;
    Roll(price);
    printf("\tYou have rolled a %li\n", price);
    if(owner->FamilyCount(family) == completeness2[family]) {
        price *= 10;
    }
    else {
        price *= 4;
    }
    return price;
}

Utility::~Utility() {}