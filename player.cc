#include "player.h"
using namespace std;

void Player::addCard(Card& c) {
    hand.emplace_back(c);
}

void Player::printHand() {
    int size = hand.size();
    for (int i = 0; i < size; ++i) {
        hand[i].printCard();

        if (i != size - 1) cout << ", ";
    }

    cout << endl;
}

void Player::eraseHand() {
    hand.erase(hand.begin(), hand.end());
}

int Player::calculateScore() {
    int score = 0;

    for (auto c : hand) {
        score += c.calculateRank();
    }

    return ((hasAce() && (score + 10 == 21)) ? 21 : score);
}

bool Player::hasAce() {
    for (auto c : hand) {
        if (c.getRank() == "A") return true;
    }

    return false;
}

int Player::finalScore() {
    int score = calculateScore();
    bool ace = hasAce();

    return ((ace && (score + 10 <= 21)) ? score + 10 : score);
}
