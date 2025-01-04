#ifndef Deck_H
#define Deck_H
#include <vector>
#include <algorithm>
#include <random>
#include "card.h"

const int ranks = 13;

class Deck {
        std::vector<Card> deck;
    public:
        Deck();
        ~Deck();
        void shuffleDeck();
        Card drawCard();
};

#endif