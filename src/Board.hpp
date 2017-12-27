#pragma once

#include <string>
#include <vector>
#include <map>
#include <utility>
#include "Player.hpp"
#include "Property.hpp"

class Board
{
  public:
    Board();
    virtual ~Board();

    void AddPlayer(std::string name);
    void Turn(std::string name);

  private:
    std::vector<std::pair<e_type, Property*> > spot;
    std::map<std::string, Player*> players;
    long fpTotal, curLocation;
    Player *curPlayer;
};
