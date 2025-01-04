#ifndef Player_H
#define Player_H
#include <vector>
#include <memory>
#include <iostream>
#include "subject.h"
#include "deck.h"

class Player {
    protected:
        std::vector<Card> hand;     
    public: 
        void addCard(Card&);
        void printHand();
        void eraseHand();
        int calculateScore();
        bool hasAce();
        int finalScore();
};

#endif