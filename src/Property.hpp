#pragma once

#include "Base.hpp"
#include <string>
#include <vector>

class Property : public Base {
  private:
    long numHouses;

  public:
    Property(long location);
    ~Property();

    void BuyHouse(long num);
    long GetRent();
    void SellHouse(long num);
};