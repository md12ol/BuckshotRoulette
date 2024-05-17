#ifndef BUCKSHOTROULETTE_PLAYER_H
#define BUCKSHOTROULETTE_PLAYER_H

#include <string>
#include <vector>
#include <utility>
#include "Item.h"

using namespace std;

class Player {
public:
    explicit Player(string name, int health, vector<Item> items = {});
    int increaseHealth();
    int decreaseHealth();
    /*
     * This would mean that we would need a list of items and to select the specific item object we want to use
     * then send it to this method.
     * TODO: Determine if this functionality makes sense.
     */
    int useItem(const string& itemName);
    int acquireItem(Item item);
    vector<Item> getItems();
    int setHealth(int h);
    int getHealth() const;
    int setName(string n);
    string getName();

private:
    int health;
    string name;
    vector<Item> items;

};


#endif //BUCKSHOTROULETTE_PLAYER_H
