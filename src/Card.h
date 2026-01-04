#ifndef CARD_H
#define CARD_H

#include <string>
using namespace std;

class Card{
private:
  string rank;
  string suit;
  int value;

public:
  Card(string r, string s, int v);
  int getValue() const;
  string toString() const;
}

#endif
