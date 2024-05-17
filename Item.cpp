#include "Item.h"

#include <utility>

Item::Item(const string& name,const string& description){
    this->name = name;
    this->description = name;
}

string Item::getName() {
    return name;
}

int Item::setName(string n) {
    this->name = std::move(n);
    return 0;
}

string Item::getDescription() {
    return description;
}

int Item::setDescription(string d) {
    this->description = std::move(d);
    return 0;
}
