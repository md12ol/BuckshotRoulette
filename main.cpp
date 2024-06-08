#include <iostream>
#include <random>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <chrono>
#include <cassert>

using namespace std;

// Constants for the program
// Note for Nikola: this is the naming convention for constants, like Java - global const
const int MAX_ITEMS = 8;
const int MAX_BULLETS = 8;
const int STARTING_ENERGY = 4;

/**
 * Prints msg to console followed by the contents of the vec to outp with sep between the items in the vector.
 * Optional new line character after printing the vector.
 *
 * @tparam T1       The type of output stream.
 * @tparam T2       The type of objects in the vector.
 * @param outp      The stream to output to.
 * @param vec       The vector to print.
 * @param msg       The message before the vector.
 * @param sep       The separator between items.
 * @param newline   Whether or not to print a new line character after printing the vector.
 * @return          0 if no error occurs.
 */
template<class T1, class T2>
int printVector(T1 &outp, vector<T2> vec, const string &msg, const string &sep, bool newline) {
    outp << msg;
    // Note for Nikola: I print the first item outside the loop to ensure the separator isn't printed after the final item
    outp << vec[0]; // Print the first value
    // Print the rest of the values
    for (int i = 1; i < vec.size(); ++i) {
        outp << sep << vec[i]; // Print separator and next item
    }
    if (newline) outp << "\n";
    return 0;
}

/**
 * Perform the action.
 *
 * @param action        The action to perform.
 * @param magazine      Bullets in the magazine.
 * @param spentAmmo     Bullets already spent.
 * @param compsEnergy   Computer's energy.
 * @param usersEnergy   User's energy.
 * @param compsItems    Computer's items.
 * @param usersItems    User's items.
 * @return              0 if no error occurs.
 * TODO: Determine if some of this is useful.
 */
int performAction(int action, vector<bool> magazine, vector<bool> spentAmmo, int compsEnergy, int usersEnergy,
                  vector<string> compsItems, vector<string> usersItems) {
    switch (action) {
        case 0: // Shoot the user
            // Ensure there is a bullet to shoot and the user has enough energy
            assert(!magazine.empty());
            assert(usersEnergy > 0);
            if (magazine[0]) { // Live bullet
                usersEnergy--;
            }
            // Move bullet to spent ammo
            magazine.erase(magazine.begin());
            spentAmmo.push_back(true);
            break;
        case 1: // Shoot the computer
            // Ensure there is a bullet to shoot and the computer has enough energy
            assert(!magazine.empty());
            assert(compsEnergy > 0);
            if (magazine[0]) { // Live bullet
                compsEnergy--;
            }
            // Move bullet to spent ammo
            magazine.erase(magazine.begin());
            spentAmmo.push_back(true);
            break;
        case 2: // Use item ...

            break;
    }
}



int main() {
    srand48(time(nullptr));
    oneRound();

    return 0;
}
