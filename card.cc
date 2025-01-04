#include "card.h"
using namespace std;

Card::Card(char s, int r) : suit{s}, rank{r} {}
Card::~Card() {}

string Card::getSuit() const {
    if (suit == 'H') {
        return "Hearts";
    } else if (suit == 'D') {
        return "Diamonds";
    } else if (suit == 'S') {
        return "Spades";
    } else {
        return "Clubs";
    }
}

string Card::getRank() const {
    if (rank == 1) {
        return "A";
    } else if (rank == 10) {
        return "10";
    } else if (rank == 11) {
        return "J";
    } else if (rank == 12) {
        return "Q";
    } else if (rank == 13) {
        return "K";
    } else {
        return (to_string(rank));
    }
}

void Card::printCard() const {
    string s;

    s += getRank();
    s += " of ";
    s += getSuit();

    cout << s;
}

int Card::calculateRank() const {
    return ((rank > 10) ? 10 : rank);
}
