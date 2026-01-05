#include "Hand.h"
using namespace std;
void Hand::addCard(const Card& card) {
    cards.push_back(card);
}

int Hand::getTotal() const {
    int total = 0;
    int aceCount = 0;

    for (const Card& card : cards) {
        total += card.getValue();
        if (card.getValue() == 11) {
            aceCount++;
        }
    }

    // Adjust Aces from 11 to 1 as needed to avoid busting
    while (total > 21 && aceCount > 0) {
        total -= 10;   // turning an Ace from 11 to 1 reduces total by 10
        aceCount--;
    }

    return total;
}

string Hand::toString(bool hideFirstCard) const {
   string result;

    for (size_t i = 0; i < cards.size(); i++) {
        if (hideFirstCard && i == 0) {
            result += "[Hidden Card]\n";
        } else {
            result += cards[i].toString() + "\n";
        }
    }

    return result;
}

void Hand::clear() {
    cards.clear();
}
