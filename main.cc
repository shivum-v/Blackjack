#include <iostream>
#include <memory>
#include <vector>
#include <stack>
#include <string>
#include "table.h"
#include "player.h"
#include "human.h"
#include "dealer.h"
#include "deck.h"
#include "card.h"
#include "observer.h"
#include "textdisplay.h"
using namespace std;

int simulateRound(Table& t, int bet, bool split) {
    // Play turns
    t.humanTurn(bet);
    t.computerTurn();

    // Calculate result
    int result = t.calculateResult(bet);

    // Resetting Table
    t.getDealer().eraseHand();
    t.getHuman().eraseHand();

    return result;
}

void gameHandler(Table& t, Dealer& d, Human& h) {
    while (true) {
        string action;

        if (h.getChips() == 0) {
            cout << "No more chips" << endl; 
            break;
        }

        cin >> action;

        if (action == "end") {
            cout << "Exited game" << endl;
            break;
        } else if (action == "bet") {
            int amount;
            cin >> amount;
            if (amount <= 0) {
                cout << "Invalid bet" << endl;
            } else if (amount > h.getChips()) {
                cout << "Not enough chips" << endl;
            } else { // Game is started && betting with x chips
                t.openingCards();
                bool b = t.getHuman().canSplit();
                h.updateChips(simulateRound(t, amount, b));
            }

            continue;
        }
    }
}

int main() {
    string command;

    while (cin >> command) {
        if (command == "game") {
            int chips;
            cin >> chips;
            if (chips < 0 || chips > 1001) {
                cout << "Invalid number of chips" << endl;
            } else {
                Dealer d;
                Human h(chips);
                Table t(d, h);
                TextDisplay td{t};

                gameHandler(t, d, h);
            }

            continue;
        } else if (command == "q") {
            cout << "Ending game" << endl;
            break;
        }
    }
}   