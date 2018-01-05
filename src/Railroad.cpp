#include "Player.hpp"
#include "Railroad.hpp"
#include <string>
#include <math.h>

Railroad::Railroad(long location) : Base(location) {}

long Railroad::GetRent() {
    return 25 * pow(2, owner->FamilyCount(family) - 1);
}

Railroad::~Railroad() {}