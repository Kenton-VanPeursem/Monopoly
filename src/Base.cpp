#include "Base.hpp"

Base::Base(long location) {
    long index = -1;
    owner = 0;

    FILE* fp;
    char name[50];

    fp = fopen("/Users/ksvanpeu/kProjects/Monopoly/db/monopoly.txt", "r");

    while(location != index) {
        fscanf(fp, "%li %s %li %li %li %li %li %li %li %li %li %li", &index,
            name, &price, &mortgagePrice, &family, &rent[0], &rent[1],
            &rent[2], &rent[3], &rent[4], &rent[5], &housePrice);
    }
    fclose(fp);

    title = std::string(name);
}

void Base::SetMortgage(bool value) {
    mortgaged = value;
}

void Base::SetOwner(Player &newOwner) {
    owner = &newOwner;
}

Base::~Base() {}