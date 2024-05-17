#include "Round.h"

/**
 * Initializes and runs one round of buckshot roulette.
 *
 * @return 0 if no error occurs.
 * @todo - one round is one clip - we need to get one turn set up
 * @todo - move player into class
 */
// TODO: Might be useful?
//int oneRound() {
//    // Initialize the players' energy and items
//    int usersEnergy = STARTING_ENERGY;
//    int compsEnergy = STARTING_ENERGY;
//    vector<string> usersItems;
//    vector<string> compsItems;
//    usersItems.reserve(MAX_ITEMS);
//    compsItems.reserve(MAX_ITEMS);
//
//    // Load the gun with bullets
//    int numBullets = ((int) lrand48() % (MAX_BULLETS - 1)) + 2; // Number bullets in range [2, MAX_BULLETS]
//    int numBlanks = (int) lrand48() % (numBullets - 1) + 1; // At least one live and one blank bullet
//    int numLive = numBullets - numBlanks;
//    vector<bool> magazine;
//    vector<bool> spentAmmo;
//    magazine.reserve(MAX_BULLETS);
//    spentAmmo.reserve(MAX_BULLETS);
//    for (int i = 0; i < numBlanks; ++i) {
//        magazine.push_back(false);
//    }
//    for (int i = 0; i < numLive; ++i) {
//        magazine.push_back(true);
//    }
//    /**
//     * The following shuffle is likely seeded with system time.  This means that it does not produce consistent
//     * output for repeated runs.  This is good for the actual game but not the best for testing purposes.
//     * I don't fully understand mt19937 and random_device.  I found this solution online.
//     * TODO: Add ability to seed the random generator with a specific seed value.
//     */
//    shuffle(magazine.begin(), magazine.end(), std::mt19937(std::random_device()()));
//    printVector<ostream, bool>(cout, magazine, "Contents: ", ", ", true);
//
//    cout << "Loading the gun with " << numLive << " live bullets and " << numBlanks << " blanks." << endl;
//
//    return 0;
//}