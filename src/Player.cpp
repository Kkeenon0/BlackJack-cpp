#include "Player.h"
using namespace std;

Player::Player(const string& n) : name(n) {}

string Player::getName() const{
    return name;
}

Hand& Player::getHand(){
    return hand;
}
const Hand& Player::getHand() const{
    return hand;
      }

void Player::clearHand(){
    hand.clear(); 
}
