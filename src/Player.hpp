#pragma once

#include "Defines.hpp"
#include "Property.hpp"
#include <string>
#include <vector>

class Player
  {
  public:
  Player(std::string name);
  virtual ~Player() {;};

  void AddProperty(Property prop);
  long FamilyCount(enum e_family fam);
  void SetLocation(long loc);
  long GetLocation();
  void AdjustWallet(long amount);
  void SetInJail(bool jail);
  bool HasJailFreeCard();
  void SetJailFreeCard(bool jail);
  long GetWalletAmount();
  std::string &GetName();

  std::vector<long> family;

  private:
  std::string name;
  long wallet, location;
  bool inJail, hasJailFree;
  std::vector<Property> properties;
  };
