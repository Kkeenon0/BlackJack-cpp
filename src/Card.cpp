#include "Card.h"
using namespace std;

Card::Card(string r, string s, int v)
  : rank(r), suit(s), value(v) {}

int Card::getValue() const{
  return value;
}

string Card::toString() const{
  return rank + " of " + suit;
}
