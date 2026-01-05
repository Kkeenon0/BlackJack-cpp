#include <iostream>
using namespace std;

#include <string>

#include "Deck.h"
#include "Player.h"

void printStatus(const Player& player, const Player& dealer, bool hideDealerFirstCard) {
    cout << "\n=== Current Hands ===\n";
    cout << dealer.getName() << ":\n";
    cout << dealer.getHand().toString(hideDealerFirstCard);
    if (!hideDealerFirstCard) {
        cout << "Total: " << dealer.getHand().getTotal() << "\n";
    }
    cout << "\n" << player.getName() << ":\n";
    cout << player.getHand().toString(false);
    cout << "Total: " << player.getHand().getTotal() << "\n";
    cout << "=====================\n";
}

int main() {
    Deck deck;
    deck.shuffle();

    Player player("Player");
    Player dealer("Dealer");

    // Initial deal: 2 cards each
    player.clearHand();
    dealer.clearHand();

    player.getHand().addCard(deck.dealCard());
    dealer.getHand().addCard(deck.dealCard());
    player.getHand().addCard(deck.dealCard());
    dealer.getHand().addCard(deck.dealCard());

    // Check for initial blackjack
    int playerTotal = player.getHand().getTotal();
    int dealerTotal = dealer.getHand().getTotal();

    printStatus(player, dealer, true);

    if (playerTotal == 21 || dealerTotal == 21) {
        cout << "\n=== Final Result ===\n";
        printStatus(player, dealer, false);

        if (playerTotal == 21 && dealerTotal == 21) {
            cout << "Push! Both have Blackjack.\n";
        } else if (playerTotal == 21) {
            cout << "You win! Blackjack.\n";
        } else {
            cout << "Dealer wins with Blackjack.\n";
        }
        return 0;
    }

    // Player turn
    while (true) {
        string choice;
        cout << "\nHit or Stand? (h/s): ";
        cin >> choice;

        if (choice == "h" || choice == "H") {
            player.getHand().addCard(deck.dealCard());
            printStatus(player, dealer, true);

            if (player.getHand().getTotal() > 21) {
                cout << "\nYou busted. Dealer wins.\n";
                cout << "\n=== Final Hands ===\n";
                printStatus(player, dealer, false);
                return 0;
            }
        } else if (choice == "s" || choice == "S") {
            break;
        } else {
            cout << "Invalid input. Type 'h' or 's'.\n";
        }
    }

    // Dealer turn
    cout << "\nDealer reveals hand...\n";
    printStatus(player, dealer, false);

    while (dealer.getHand().getTotal() < 17) {
        cout << "Dealer hits.\n";
        dealer.getHand().addCard(deck.dealCard());
        printStatus(player, dealer, false);
    }

    int finalPlayer = player.getHand().getTotal();
    int finalDealer = dealer.getHand().getTotal();

    cout << "\n=== Final Result ===\n";
    if (finalDealer > 21) {
        cout << "Dealer busted. You win!\n";
    } else if (finalPlayer > finalDealer) {
        cout << "You win!\n";
    } else if (finalPlayer < finalDealer) {
        cout << "Dealer wins.\n";
    } else {
        cout << "Push (tie).\n";
    }




  
  return 0;
}
