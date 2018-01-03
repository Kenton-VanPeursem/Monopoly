#pragma once

#include <string>
#include <vector>
#include "Defines.hpp"

class Player
  {
  public:
  Player(std::string name);
  virtual ~Player() {;};

  long FamilyCount(enum e_family fam);
  void SetLocation(long loc);
  long GetLocation();
  void AdjustWallet(long amount);
  void SetInJail(bool jail);
  long GetWalletAmount();
  std::string &GetName();

  std::vector<long> family;

  private:
  std::string name;
  long wallet, location;
  bool inJail;
  };
