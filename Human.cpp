#include "Human.h"

// TODO: Not sure if this should be here.  We should check/decide.
/**
 * @param check The string are searching for in vec.
 * @param vec   The vector we are searching for check.
 * @return      True if check is in vec.
 */
bool strInVector(const string& check, vector<string> vec) {
    return find(vec.begin(), vec.end(), check) != vec.end();
}

string Human::getUserInput() {
    // TODO: Implement me.
    return "";
}

/**
 * Prompts the user for input using prompt.  If the user input is contained in acceptableInput it returns the user input.
 * Otherwise it continually prompts the user for acceptable input.
 *
 * @param prompt            The prompt sent to user for input.
 * @param acceptableInput   The vector of acceptable input values.
 * @return                  The user input.
 */
std::string Human::getUserInput(const std::string &prompt, const vector<string>& acceptableInput) {
    std::string userInput;
    bool validInput = false;
    // Continually prompt the user for input until a value from acceptableInput is provided
    do {
        cout << prompt; // Prompt user
        getline(cin, userInput); // Get input
        if (strInVector(userInput, acceptableInput)) { // If the user input is in acceptableInput
            validInput = true;
        }
        if (!validInput) { // If the user input is invalid
            std::cout << "Error in your response.  Please try again." << std::endl;
        }
    } while (!validInput); // While we don't have valid input
    return userInput;
}