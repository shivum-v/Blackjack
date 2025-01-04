#include "human.h"
using namespace std;

Human::Human(int chips) : chips{chips} {}

int Human::getChips() { return chips; }

bool Human::canSplit() {
    return (hand[0].getRank() == hand[1].getRank());
}

void Human::updateChips(int c) { 
    chips += c; 
    cout << "You now have " << chips  << " chips" << endl;
}
