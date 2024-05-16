#include <iostream>
#include <random>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <chrono>
#include <assert.h>

using namespace std;

// Constants for the program
// Note for Nikola: this is the naming convention for constants, like Java
const int MAX_ITEMS = 8;
const int MAX_BULLETS = 8;
const int STARTING_ENERGY = 4;

/**
 * @param check The string are searching for in vec.
 * @param vec   The vector we are searching for check.
 * @return      True if check is in vec.
 */
bool strInVector(const std::string &check, std::vector<std::string> &vec) {
    return find(vec.begin(), vec.end(), check) != vec.end();
}

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
 * Prompts the user for input using prompt.  If the user input is contained in acceptableInput it returns the user input.
 * Otherwise it continually prompts the user for acceptable input.
 *
 * @param prompt            The prompt sent to user for input.
 * @param acceptableInput   The vector of acceptable input values.
 * @return                  The user input.
 */
std::string getUserInput(const std::string &prompt, std::vector<std::string> acceptableInput) {
    std::string userInput;
    bool validInput = false;
    // Continually prompt the user for input until a value from acceptableInput is provided
    do {
        std::cout << prompt; // Prompt user
        getline(std::cin, userInput); // Get input
        if (strInVector(userInput, acceptableInput)) { // If the user input is in acceptableInput
            validInput = true;
        }
        if (!validInput) { // If the user input is invalid
            std::cout << "Error in your response.  Please try again." << std::endl;
        }
    } while (!validInput); // While we don't have valid input
    return userInput;
}

/**
 * Determines which action the computer will take.
 *
 * @param magazine      Bullets in the magazine.
 * @param spentAmmo     Bullets already spent.
 * @param compsEnergy   Computer's energy.
 * @param usersEnergy   User's energy.
 * @param compsItems    Computer's items.
 * @param usersItems    User's items.
 * @return              The action decided on by the computer.
 */
int computersAction(vector<bool> magazine, vector<bool> spentAmmo, int compsEnergy, int usersEnergy,
                    vector<string> compsItems, vector<string> usersItems) {
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

/**
 * Initializes and runs one round of buckshot roulette.
 *
 * @return 0 if no error occurs.
 */
int oneRound() {
    // Initialize the players' energy and items
    int usersEnergy = STARTING_ENERGY;
    int compsEnergy = STARTING_ENERGY;
    vector<string> usersItems;
    vector<string> compsItems;
    usersItems.reserve(MAX_ITEMS);
    compsItems.reserve(MAX_ITEMS);

    // Load the gun with bullets
    int numBullets = ((int) lrand48() % (MAX_BULLETS - 1)) + 2; // Number bullets in range [2, MAX_BULLETS]
    int numBlanks = (int) lrand48() % (numBullets - 1) + 1; // At least one live and one blank bullet
    int numLive = numBullets - numBlanks;
    vector<bool> magazine;
    vector<bool> spentAmmo;
    magazine.reserve(MAX_BULLETS);
    spentAmmo.reserve(MAX_BULLETS);
    for (int i = 0; i < numBlanks; ++i) {
        magazine.push_back(false);
    }
    for (int i = 0; i < numLive; ++i) {
        magazine.push_back(true);
    }
    /**
     * The following shuffle is likely seeded with system time.  This means that it does not produce consistent
     * output for repeated runs.  This is good for the actual game but not the best for testing purposes.
     * I don't fully understand mt19937 and random_device.  I found this solution online.
     * TODO: Add ability to seed the random generator with a specific seed value.
     */
    shuffle(magazine.begin(), magazine.end(), std::mt19937(std::random_device()()));
    printVector<ostream, bool>(cout, magazine, "Contents: ", ", ", true);

    cout << "Loading the gun with " << numLive << " live bullets and " << numBlanks << " blanks." << endl;

    return 0;
}

int main() {
    srand48(time(nullptr));
    oneRound();

    return 0;
}
