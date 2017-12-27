#include "Board.hpp"
#include <stdio.h>
#include <vector>

Board::Board() : fpTotal(0)
{
    for (long i = 0; i < 40; ++i)
        spot.push_back(std::make_pair(PROPERTY, 0));

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
    spot[38].first = LUXURY_TAX;
}

Board::~Board()
{
    // long i;

    // for (i = 0; i < players.size(); ++i)
    //     delete players.at(i);

    // for (i = 0; i < 40; ++i)
    //     delete spot[i].second;
}

void Board::AddPlayer(std::string name)
{
    players.insert(std::pair<std::string, Player*>(name, new Player(name)));
}

void Board::Turn(std::string name)
{
    auto it = players.find(name);
    curPlayer = it->second;
    // curPlayer = players.find(name);

    curLocation = curPlayer->GetLocation();
    curLocation += Roll();

    if (curLocation >= 40)
    { // Handle passing Go and getting $200
        curPlayer->AdjustWallet(200);
        curLocation -= 40;
    }

    curPlayer->SetLocation(curLocation);

    switch (spot[curLocation].first)
    {
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
        // Action;
        break;
    }
    case COMMUNITY_CHEST:
    {
        // Action;
        break;
    }
    case INCOME_TAX:
    {
        if (curPlayer->GetWalletAmount() < 200)
        {
            // Handle
        }
        else
        {
            curPlayer->AdjustWallet(-200);
        }
        fpTotal += 200;
        break;
    }
    case LUXURY_TAX:
    {
        if (curPlayer->GetWalletAmount() < 75)
        {
            // Handle
        }
        else
        {
            curPlayer->AdjustWallet(-75);
        }
        fpTotal += 75;
        break;
    }
    case PROPERTY:
    {
        if (&(spot[curLocation].second))
        {
            Property *prop = new Property(curLocation);
            long price = prop->GetPrice();
            std::string name = prop->GetName();
            printf("\nDo you want to buy %s for $i?\n");
            char response = getchar();
            if ((response == 'Y') || (response == 'y'))
            {
                curPlayer->AdjustWallet(-price);
                curPlayer->family[prop->GetFamily()]++;
                prop->SetOwner(*curPlayer);
                spot[curLocation].second = *prop;
            }
            else
            {
                delete prop;
            }
        }
        break;
    }
    }
}
