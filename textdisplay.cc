#include "textdisplay.h"
using namespace std;

TextDisplay::TextDisplay(Table& t) : table{t} {
    table.attach(this);
}

TextDisplay::~TextDisplay() {
    table.detach(this);
}

void TextDisplay::notify(bool h, bool d) {
    int hscore = table.getHuman().calculateScore();
    int dscore = table.getDealer().calculateScore();
    for (int i = 0; i < 45; ++i) cout << '-';
    cout << endl << "Human Hand - Score: " << hscore;
    if (h && (hscore + 10) < 21) cout << " / " << hscore + 10;
    cout << endl; 

    table.printHand(table.getHuman());

    cout << endl << "Dealer Hand - Score: " << dscore;
    if (d && (dscore + 10) < 21) cout << " / " << dscore + 10;
    cout << endl;

    table.printHand(table.getDealer());

    for (int i = 0; i < 45; ++i) cout << '-';
    cout << endl;   
}
