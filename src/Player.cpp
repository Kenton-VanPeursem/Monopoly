#include "Player.hpp"

Player::Player(std::string name) : name(name), wallet(1500), inJail(false), location(0)
{
    for (long i=0; i<e_family::SIZE; ++i)
      family.push_back(0);
};

long Player::FamilyCount(enum e_family fam)
{
    return family[fam];
}

long Player::GetLocation() {
    return location;
}
void Player::SetLocation(long loc)
{
    location = loc;
}

void Player::AdjustWallet(long amount)
{
    wallet += amount;
}

void Player::SetInJail(bool jail)
{
    inJail = jail;
}

long Player::GetWalletAmount()
{
    return wallet;
}
std::string &Player::GetName()
{
    return name;
}
