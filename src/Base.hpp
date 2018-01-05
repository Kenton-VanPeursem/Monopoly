#pragma once

#include "Defines.hpp"
#include <string>

class Player;

class Base {
  protected:
    enum e_family family;
    long housePrice, mortgagePrice, price;
    bool mortgaged;
    Player *owner;
    long rent[6];
    std::string title;

  public:
    Base(long location);
    virtual ~Base();

    virtual long GetMortgagePrice() {return mortgagePrice;};
    virtual long GetPrice() {return price;};
    virtual std::string GetTitle() {return title;};
    virtual bool IsMortgaged() {return mortgaged;};
    virtual long GetRent() {return 0;};

    virtual void SetMortgage(bool value);
    virtual void SetOwner(Player *newOwner);
    virtual Player* GetOwner();
};