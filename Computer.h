#ifndef BUCKSHOTROULETTE_COMPUTER_H
#define BUCKSHOTROULETTE_COMPUTER_H

#include "Player.h"

// TODO: Check to make sure public is the correct access modifier.
class Computer : public Player{
public:
    // TODO: Should this method have arguments and what should it return?
    string doTheAI();
};

#endif //BUCKSHOTROULETTE_COMPUTER_H
