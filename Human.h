#ifndef BUCKSHOTROULETTE_HUMAN_H
#define BUCKSHOTROULETTE_HUMAN_H

#include <iostream>
#include "Player.h"

// TODO: Check to make sure public is the correct access modifier.
class Human : public Player {
public:
    // TODO: Is a constructor needed?
    // TODO: Should this method have arguments and what should it return?
    string getUserInput();

private:
    string getUserInput(const std::string &prompt, const std::vector<std::string>& acceptableInput);

};

// TODO: Not sure if this should be here.  We should check/decide.
bool strInVector(const string &check, vector<string> &vec);

#endif //BUCKSHOTROULETTE_HUMAN_H
