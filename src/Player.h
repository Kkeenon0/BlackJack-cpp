#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Hand.h"
using namespace std;
class Player {
private:
    string name;
    Hand hand;

public:
    Player(const string& n);

    string getName() const;

    Hand& getHand();
    const Hand& getHand() const;

    void clearHand();
};

#endif
