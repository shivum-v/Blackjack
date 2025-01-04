#ifndef Table_H
#define Table_H
#include "dealer.h"
#include "human.h"
#include "subject.h"
#include <iostream>

class Table : public Subject {
        Dealer dealer;
        Human human;
        Deck cards;
    public:
        Table(Dealer&, Human&);
        void printHand(Player&);
        void dealCard(Player&);
        void openingCards();
        void humanTurn(int&);
        void computerTurn();
        int calculateResult(int&);
        bool humanAce();
        bool dealerAce();
        Human& getHuman();
        Dealer& getDealer();
        Deck& getDeck();
};

#endif