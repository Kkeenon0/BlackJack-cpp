#ifndef HAND_H
#define HAND_H

#include <vector>
#include <string>
#include "Card.h"

using namespace std;

class Hand {
private:
    vector<Card> cards;

public:
    void addCard(const Card& card);
    int getTotal() const;
    string toString(bool hideFirstCard = false) const;
    void clear();
};

#endif
