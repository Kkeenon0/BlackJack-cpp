#include "Deck.h"
#include <algorithm>
#include <random>

using namespace std;

Deck::Deck() : currentIndex(0) {
  string suits[] = {"Hearts", "Diamonds", "Cloves", "Spades"};
  string ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
  int values[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11};

  for (const string& suit: suits){
    for(int i = 0; i < 13; i++){
      cards.emplace_back(ranks[i], suit, values[i]);
    }
  }
}

void Deck::shuffle() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cards.begin(), cards.end(), g);
    currentIndex = 0;
}

Card Deck::dealCard(){
  return cards[currentIndex++];
}
  
