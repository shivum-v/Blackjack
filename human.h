#ifndef Human_H
#define Human_H
#include <iostream>
#include "player.h"

class Human : public Player {
        int chips; 
    public:
        Human(int);
        int getChips();
        bool canSplit();
        void updateChips(int);
};

#endif