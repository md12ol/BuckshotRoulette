#ifndef BUCKSHOTROULETTE_ITEM_H
#define BUCKSHOTROULETTE_ITEM_H

#include <string>

using namespace std;

class Item {
public:
    string getName();
    int setName(string name);
    string getDescription();
    int setDescription(string description);

private:
    explicit Item(const string& name, const string& description);

    string name;
    string description;

};


#endif //BUCKSHOTROULETTE_ITEM_H
