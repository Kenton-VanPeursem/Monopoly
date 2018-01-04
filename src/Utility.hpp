#pragma once

#include "Base.hpp"
#include <string>

class Utility : public Base {
  public:
    Utility(long location);
    ~Utility();

    long GetRent();
};