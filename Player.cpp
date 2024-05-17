#include "Player.h"

#include <utility>

Player::Player(string name, int health, vector<Item> items) {
    this->name = std::move(name);
    this->health = health;
    this->items = std::move(items);
}

int Player::increaseHealth() {
    health += 1;
    return health;
}

int Player::decreaseHealth() {
    health -= 1;
    return health;
}

int Player::useItem(const string& itemName) {
    for (int i = 0; i < items.size(); ++i) {
        if (items[i].getName() == itemName){
            items.erase(items.begin() + i);
            return 0;
        }
    }
    // TODO: This is an error.  We should deal with it.
    return -1;
}

int Player::acquireItem(Item item) {
    items.push_back(item);
    return 0;
}

vector<Item> Player::getItems() {
    return items;
}

int Player::setHealth(int h) {
    health = h;
    return health;
}

int Player::getHealth() const {
    return health;
}

int Player::setName(string n) {
    name = std::move(n);
    return 0;
}

string Player::getName() {
    return name;
}
