#ifndef Card_H
#define Card_H
#include <iostream>
#include <string>

class Card {
        char suit;
        int rank;
    public:
        Card(char, int);
        ~Card();
        std::string getSuit() const;
        std::string getRank() const;
        void printCard() const;
        int calculateRank() const;
};

#endif