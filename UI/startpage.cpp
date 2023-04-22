#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function declarations
void show_start_page();
void display_instructions();

int main() {
    srand(time(0)); // Seed the random number generator

    show_start_page();

    // Your game code here

    return 0;
}

void show_start_page() {
    string input;

    cout << R"(
---------------------------------------------------------------------------------------------------------|
 ██░ ██  ▄▄▄      █    ██  ███▄    █ ▄▄▄█████▓▓█████ ▓█████▄                                             |
▓██░ ██▒▒████▄    ██  ▓██▒ ██ ▀█   █ ▓  ██▒ ▓▒▓█   ▀ ▒██▀ ██▌                                            |
▒██▀▀██░▒██  ▀█▄ ▓██  ▒██░▓██  ▀█ ██▒▒ ▓██░ ▒░▒███   ░██   █▌                                            |
░▓█ ░██ ░██▄▄▄▄██▓▓█  ░██░▓██▒  ▐▌██▒░ ▓██▓ ░ ▒▓█  ▄ ░▓█▄   ▌                                            |
░▓█▒░██▓ ▓█   ▓██▒▒█████▓ ▒██░   ▓██░  ▒██▒ ░ ░▒████▒░▒████▓                                             |
 ▒ ░░▒░▒ ▒▒   ▓▒█░▒▓▒ ▒ ▒ ░ ▒░   ▒ ▒   ▒ ░░   ░░ ▒░ ░ ▒▒▓  ▒                                             |
 ▒ ░▒░ ░  ▒   ▒▒ ░░▒░ ░ ░ ░ ░░   ░ ▒░    ░     ░ ░  ░ ░ ▒  ▒                                             |
 ░  ░░ ░  ░   ▒   ░░░ ░ ░    ░   ░ ░   ░         ░    ░ ░  ░                                             |
 ░  ░  ░      ░  ░  ░              ░             ░  ░   ░                                                |
                                                      ░                                                  |
                                                                                                         |
                                     ███▄ ▄███▓▓█████ ███▄ ▄███▓ ▒█████   ██▀███   ██▓▓█████   ██████    |
                                    ▓██▒▀█▀ ██▒▓█   ▀▓██▒▀█▀ ██▒▒██▒  ██▒▓██ ▒ ██▒▓██▒▓█   ▀ ▒██    ▒    |
                                    ▓██    ▓██░▒███  ▓██    ▓██░▒██░  ██▒▓██ ░▄█ ▒▒██▒▒███   ░ ▓██▄      |
                                    ▒██    ▒██ ▒▓█  ▄▒██    ▒██ ▒██   ██░▒██▀▀█▄  ░██░▒▓█  ▄   ▒   ██▒   |
                                    ▒██▒   ░██▒░▒████▒██▒   ░██▒░ ████▓▒░░██▓ ▒██▒░██░░▒████▒▒██████▒▒   |
                                    ░ ▒░   ░  ░░░ ▒░ ░ ▒░   ░  ░░ ▒░▒░▒░ ░ ▒▓ ░▒▓░░▓  ░░ ▒░ ░▒ ▒▓▒ ▒ ░   |
                                    ░  ░      ░ ░ ░  ░  ░      ░  ░ ▒ ▒░   ░▒ ░ ▒░ ▒ ░ ░ ░  ░░ ░▒  ░ ░   |
                                    ░      ░      ░  ░      ░   ░ ░ ░ ▒    ░░   ░  ▒ ░   ░   ░  ░  ░     |
                                           ░      ░  ░      ░       ░ ░     ░      ░     ░  ░      ░     |
                                                                                                         |
                                                                                                         |
                           Please enter the corresponding number to your choice:                         |
                                                                                                         |
                                      ___    ______           __                                         |
                                     <  /   / __/ /____ _____/ /_                                        |
                                     / /   _\ \/ __/ _ `/ __/ __/                                        |
                                    /_(_) /___/\__/\_,_/_/  \__/                                         |
                                                                                                         |
                                                                                                         |
                           ___      ____        __               __  _                                   |
                          |_  |    /  _/__  ___/ /_______ ______/ /_(_)__  ___                           |
                         / __/_   _/ // _ \(_-< __/ __/ // / __/ __/ / _ \/ _ \                          |
                        /____(_) /___/_//_/___|__/_/  \_,_/\__/\__/_/\___/_//_/                          |
                                                                                                         |
                                                                                                         |
----------------------------------------------------------------------------------------------------------

)";
    std::cin >> input;

    while (input != "1" && input != "2") {
        cout << "Invalid input. Please enter 1 or 2: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> input;
    }

    if (input == "1") {
        // Proceed to the game
    } else if (input == "2") {
        display_instructions();
    }
}

void display_instructions() {
    cout << "\nINSTRUCTIONS:\n";
    cout << "1. The game is a text-based horror school escape game.\n";
    cout << "2. You will be prompted with choices throughout the game.\n";
    cout << "3. Choose wisely, as your decisions will impact the story.\n";
    cout << "4. To make a choice, enter the corresponding number and press Enter.\n";
    cout << "\nPress Enter to return to the start page.";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    show_start_page();
}
