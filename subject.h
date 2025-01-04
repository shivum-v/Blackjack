#ifndef Subject_H
#define Subject_H
#include <vector>
#include <iostream>
#include "observer.h"

class Subject {
    protected:
        std::vector<Observer*> observers;
    public:
        Subject();
        void attach(Observer*);
        void detach(Observer*);
        void notifyObservers(bool, bool) const;
        virtual ~Subject() = 0;
};

#endif