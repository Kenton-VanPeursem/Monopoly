#pragma once

#include "Base.hpp"
#include <string>

class Railroad : public Base
{
  public:
    Railroad(long location);
    ~Railroad();

    long GetRent();
};