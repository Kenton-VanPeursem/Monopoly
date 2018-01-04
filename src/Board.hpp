#pragma once

#include "Cards.hpp"
#include "Player.hpp"
#include "Property.hpp"
#include <string>
#include <vector>
#include <map>
#include <utility>

class Board {
  public:
    Board();
    virtual ~Board();

    Cards Chance, Chest;

    void AddPlayer(std::string name);
    void Turn(std::string name);
    void ProcessCard(card *it);
    void ProcessProperty();
    void ProcessLocation();
    void PassGo();

  private:
    std::vector<std::pair<e_type, Property*> > spot;
    std::map<std::string, Player*> players;
    long fpTotal, curLocation;
    Player *curPlayer;
};
