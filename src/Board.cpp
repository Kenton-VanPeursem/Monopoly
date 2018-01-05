#include "Board.hpp"
#include "Player.hpp"
#include "Property.hpp"
#include "Utility.hpp"
#include "Railroad.hpp"
#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <vector>

using namespace std;

Board::Board() : fpTotal(0), Chance(CHANCE), Chest(COMMUNITY_CHEST) {
    // Seed the random number generator.
    srand(time(NULL));

    for (long i = 0; i < 40; ++i) {
        auto prop = std::make_pair(PROPERTY, nullptr);
        spot.push_back(prop);
    }

    spot[0].first = GO;
    spot[2].first = COMMUNITY_CHEST;
    spot[4].first = INCOME_TAX;
    spot[7].first = CHANCE;
    spot[10].first = JAIL;
    spot[17].first = COMMUNITY_CHEST;
    spot[20].first = FREE_PARKING;
    spot[22].first = CHANCE;
    spot[30].first = GOTO_JAIL;
    spot[33].first = COMMUNITY_CHEST;
    spot[36].first = CHANCE;
    spot[38].first = LUXURY_TAX;
}

Board::~Board() {

}

void Board::AddPlayer(std::string name) {
    players.insert(std::pair<std::string, Player*>(name, new Player(name)));
}

void Board::Turn(std::string name) {
    long dice;
    bool doubles;
    auto it = players.find(name);

    curPlayer = it->second;
    printf("%s ($%li):\n", name.c_str(), curPlayer->GetWalletAmount());

    doubles = Roll(dice);
    curLocation = curPlayer->GetLocation();
    curLocation += dice;

    printf("\tYour dice roll is %li", dice);
    if(doubles)
        printf(" (doubles)!\n");
    else
        printf(".\n");

    PassGo(); // Should be called anytime a location changes!

    ProcessLocation();

    printf("%s turn over ($%li)\n", name.c_str(), curPlayer->GetWalletAmount());
}

void Board::ProcessLocation() {
    switch (spot[curLocation].first) {
        case GO:
        {
            break;
        }
        case JAIL:
        {
            break;
        }
        case FREE_PARKING:
        {
            printf("\tYou have landed on 'Free Parking'!\n");
            curPlayer->AdjustWallet(fpTotal);
            fpTotal = 0;
            break;
        }
        case GOTO_JAIL:
        {
            curPlayer->SetLocation(10);
            curPlayer->SetInJail(true);
            break;
        }
        case CHANCE:
        {
            printf("\tChance: ");
            ProcessCard(Chance.GetCard());
            break;
        }
        case COMMUNITY_CHEST:
        {
            printf("\tCommunity Chest: ");
            ProcessCard(Chest.GetCard());
            break;
        }
        case INCOME_TAX:
        {
            printf("\tYou have landed on 'Income Tax'!\n");
            curPlayer->AdjustWallet(-200);
            fpTotal += 200;
            break;
        }
        case LUXURY_TAX:
        {
            printf("\tYou have landed on 'Luxury Tax'!\n");
            curPlayer->AdjustWallet(-75);
            fpTotal += 75;
            break;
        }
        case PROPERTY:
        {
            ProcessProperty();
            break;
        }
        default:
        {
            break;
        }
    }
}

void Board::ProcessProperty() {
    if (spot[curLocation].second == nullptr) {
        Base* prop;
        switch(curLocation) {
            case 5:
            case 15:
            case 25:
            case 35:
                prop = new Railroad(curLocation);
                break;
            case 12:
            case 28:
                prop = new Utility(curLocation);
                break;
            default:
                prop = new Property(curLocation);
                break;
        }

        printf("\tDo you want to buy %s for %li?\n",
            prop->GetName().c_str(), prop->GetPrice());

        char response;
        std::cin >> response;

        if ((response == 'Y') || (response == 'y')) {
            curPlayer->AdjustWallet(-prop->GetPrice());
            curPlayer->family[prop->GetFamily()]++;
            prop->SetOwner(curPlayer);
            spot[curLocation].second = prop;
            curPlayer->AddProperty(prop);
        }

        else
            delete prop;
    }

    else if (spot[curLocation].second->GetOwner() != curPlayer) {
        // Collect rent
        long rent = spot[curLocation].second->GetRent();
        printf("\tYou owe %d to %s!!!\n", rent, spot[curLocation].second->GetOwner()->GetName().c_str());

        spot[curLocation].second->GetOwner()->AdjustWallet(rent);
        curPlayer->AdjustWallet(-rent);
    }
}

void Board::ProcessCard(card *it) {
    printf("%s\n", it->description.c_str());
    switch (it->type) {
        case MOVE:
        {
            long move = it->amount1;
            if (move >= 0) {
                if (move > curLocation)
                    curLocation = move;
                else
                    curLocation = 40 + move;
            }
            else {
                if (move == -3) // Go back 3 spaces
                    curLocation += move;
                else if (move == -10) { // Nearest railroad
                    if (curLocation < 5)
                        curLocation = 5;
                    else if (curLocation < 15)
                        curLocation = 15;
                    else if (curLocation < 25)
                        curLocation = 25;
                    else if (curLocation < 35)
                        curLocation = 35;
                    else
                        curLocation = 40 + 5;
                }
                else if (move == -20) { // Nearest utility
                    if (curLocation < 12)
                        curLocation = 12;
                    else if (curLocation < 28)
                        curLocation = 28;
                    else
                        curLocation = 40 + 12;
                }
            }

            PassGo();

            ProcessLocation();

            break;
        }
        case COLLECT:
        {
            long collect = it->amount1;
            if (collect < 0) { // Collect from each player
                long i, size = players.size();
                auto iter = players.begin();

                for (i = 0; i < size; ++i, ++iter) {
                    if (iter->second == curPlayer)
                        continue;
                    iter->second->AdjustWallet(collect);
                    curPlayer->AdjustWallet(-collect);
                }
            }
            else
                curPlayer->AdjustWallet(collect);

            break;
        }
        case PAY:
        {
            long pay = it->amount1;

            // process houses and hotels
            if (it->amount2 > 0) {
            }

            // Pay each player
            else if (pay < 0) {
                long i, size = players.size();
                auto iter = players.begin();

                for (i = 0; i < size; ++i, ++iter) {
                    if (iter->second == curPlayer)
                        continue;
                    iter->second->AdjustWallet(-pay);
                    curPlayer->AdjustWallet(pay);
                }
            }
            else {
                curPlayer->AdjustWallet(-pay);
                fpTotal += pay;
            }
            break;
        }
        case JAIL_FREE:
        {
            curPlayer->SetJailFreeCard(true);
            break;
        }
    }
}

void Board::PassGo() {
  // This function should be called every time a location changes.
  // Two actions take place:
  //   1) The location is updated (even if not passing Go)
  //   2) The player's wallet is adjusted if Go is passed
    if (curLocation >= 40) {
        curPlayer->AdjustWallet(200);
        curLocation -= 40;
        printf("\tYou have passed 'Go', collecting $200.\n");
    }
    curPlayer->SetLocation(curLocation);
}