#include "Player.hpp"
#include "Property.hpp"
#include "Defines.hpp"
#include <string>

long completeness[e_family::SIZE] = {2, 3, 3, 3, 3, 3, 3, 2, 4, 2};

Property::Property(long location) : Base(location), numHouses(0) {
}

void Property::BuyHouse(long num) {
    if(numHouses + num > 5)
        numHouses = 5;
    else
        numHouses += num;
}

e_family Property::GetFamily() {
    return family;
}

std::string& Property::GetName() {
    return title;
}

long Property::GetRent() {
    if(numHouses > 0)
        return rent[numHouses - 1];

    if(owner->FamilyCount(family) == completeness[family])
        return rent[0] * 2;

    return rent[0];
}

void Property::SellHouse(long num) {
    if(numHouses - num < 0)
        numHouses = 0;
    else
        numHouses -= num;
}

Property::~Property() {}