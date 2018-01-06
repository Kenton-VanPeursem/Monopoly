#include "Player.hpp"
#include <iostream>
#include <stdio.h>

Player::Player(std::string name) : name(name), wallet(1500), inJail(false), location(0), hasJailFree(false), jailCount(0) {
    for (long i = 0; i < e_family::SIZE; ++i)
        family.push_back(0);
}

void Player::AddProperty(Base *prop) {
    properties.push_back(prop);
}

long Player::FamilyCount(enum e_family fam) {
    return family[fam];
}

long Player::GetLocation() {
    return location;
}
void Player::SetLocation(long loc) {
    location = loc;
}

void Player::AdjustWallet(long amount) {
    wallet += amount;
}

void Player::SetInJail(bool jail) {
    inJail = jail;
}

bool Player::HasJailFreeCard() {
    return hasJailFree;
}

void Player::SetJailFreeCard(bool jail) {
    hasJailFree = jail;
}

long Player::GetWalletAmount() {
    return wallet;
}
std::string &Player::GetName() {
    return name;
}

void Player::TurnsInJailInc() {
    ++jailCount;
}

void Player::TurnsInJailReset() {
    jailCount = 0;
}

long Player::TurnsInJail() {
    return jailCount;
}

bool Player::InJail() {
    return inJail;
}

void Player::PrintProperties() {
    if(!properties.empty()) {
        printf("\n\tYour properties:\n");
        auto it = properties.begin();

        long colCount = 1;
        std::cout << "\t";
        while(it != properties.end()) {
            std::cout<< (*it)->GetName().c_str() << "\t\t";
            if(colCount % 4 == 0)
                std::cout << std::endl << "\t";
            it++;
            colCount++;
        }
        printf("\n");
    }
    else
        printf("\n\tYou do not own any property.\n");

    printf("\n");
}