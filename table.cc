#include "table.h"
using namespace std;

Table::Table(Dealer& d, Human& h) : dealer{d}, human{h}, cards{} {}

void Table::printHand(Player& p) {
    p.printHand();
}

void Table::dealCard(Player& p) {
    Card c = cards.drawCard();
    p.addCard(c);

    notifyObservers(humanAce(), dealerAce());
}

void Table::openingCards() {
    for (int i = 0; i < 3; ++i) {
        Card c = cards.drawCard();

        ((i % 2 == 0) ? human.addCard(c) : dealer.addCard(c));
    }

    notifyObservers(humanAce(), dealerAce());
}

void Table::humanTurn(int& bet) {
    while (true) {
        int hscore = human.calculateScore();
        if (hscore >= 21) {
            break;
        }

        cout << "Perform an action: ";
        string command;
        cin >> command;
        if (command == "hit") {
            dealCard(human);
            continue;
        } else if (command == "stick") {
            break;
        } else if (command == "ddown") {
            bet *= 2;
            dealCard(human);
            break;
        } else { // Working on split
            cout << "Invalid command" << endl;
            continue;
        }
    }
}

void Table::computerTurn() {
    if (human.finalScore() < 21) {
        while (dealer.calculateScore() < 17 || dealer.calculateScore() < human.finalScore()) {
            dealCard(dealer);
        }
    }
}

int Table::calculateResult(int& bet) {
    int human_score = human.finalScore();
    int dealer_score = dealer.finalScore();
    int result;

    if (human_score == 21 || dealer_score > 21 || ((human_score < 21) && human_score > dealer_score)) {
        result = bet;
        cout << "Player wins!" << endl;
        cout << "Adding " << result << " chips" << endl;
    } else {
        result = -1 * bet;
        cout << "Dealer wins!" << endl;
        cout << "Removing " << result << " chips" << endl;
    }

    return result;
}

bool Table::humanAce() { return human.hasAce(); }
bool Table::dealerAce() { return dealer.hasAce(); }

Human& Table::getHuman() { return human; }
Dealer& Table::getDealer() { return dealer; }
Deck& Table::getDeck() { return cards; }
