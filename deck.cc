#include "deck.h"
using namespace std;

Deck::Deck() {
    for (int i = 1; i <= ranks; ++i) {
        deck.emplace_back(Card('H', i));
        deck.emplace_back(Card('D', i));
        deck.emplace_back(Card('S', i));
        deck.emplace_back(Card('C', i));
    }

    shuffleDeck();
}
Deck::~Deck() {}

void Deck::shuffleDeck() {
    random_device rd;
    mt19937 gen(rd());
    shuffle(deck.begin(), deck.end(), gen);
}

Card Deck::drawCard() {
    if (deck.size() == 0) *this = Deck();

    Card c = deck.back();
    deck.pop_back();
    return c;
}
