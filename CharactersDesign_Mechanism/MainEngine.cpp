#include <ncurses.h>
#include <iostream>
#include <string>
#include <fstream>
#include "MapLoader.h"

//compile using: g++ -pedantic-errors -std=c++11 CharactersDesign_Mechanism/MainEngine.cpp Map_Objects/Map_loading.cpp -o Game -lncurses

WINDOW* createInventoryWindow(int inv_height, int inv_width);
void printInventory(vector<string> inventory);
void addItem(vector<string>& inventory, string item);

int main() {
    // Initialize ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0); // Hide cursor

    // Set up initial variables
    int x = 87, y = 23;
    int key_input;
    string file_path = "/Users/M1/Documents/GitHub/Initial/Map_Objects/Map_resources/Classroom.txt";
    // Set up screen size
    int screen_height=0;
    int screen_width=0;
    char ch;
    bool flag = TRUE;

    ifstream inputline;
    inputline.open(file_path);
    if (inputline.fail()) {
        cout<<"파일이 없다잖아 병신아!!!"<<endl;
        exit(1);
    }
    while (inputline >> noskipws >> ch) {
        if (ch != '\n') {
            if (flag) {
                screen_width++;
            }
        } else {
            screen_height++;
            flag=FALSE;
        }
    }
    inputline.close();

    ifstream charline("/Users/M1/Documents/GitHub/Initial/CharactersDesign_Mechanism/character3.txt");
    if (charline.fail()) {
        cout<<"no file!"<<endl;
        exit(1);
    }
    int const charsize = 5;
    string char_left[charsize], char_right[charsize], char_down[charsize], char_up[charsize];
    string line;
    int ii = 0;
    while (getline(charline, line)) {
        if (ii < charsize) {
            char_left[ii] = line;
        } else if (ii < charsize*2) {
            char_right[ii%charsize] = line;
        } else if (ii < charsize*3) {
            char_down[ii%charsize] = line;
        } else {
            char_up[ii%charsize] = line;
        }
        ii++;
    }
    charline.close();

    string *current_character = char_up;

    // Main loop
    while ((key_input = getch()) != 27) { // Exit on ESC key press
        clear(); //clear screen
        Maps gameMap(screen_height, screen_width);
        VectorWrapper mapData = gameMap.Map_Loader(file_path);

        // Draw the map
        gameMap.Map_printer(mapData, 0, 0, screen_height, screen_width);

        switch(key_input) {
            case 'w':
                y--;
                current_character = char_up;
                if (mapData.TDVEC[y+4][x+2] != ' ') {
                    y++;
                    break;
                }
                break;

            case 's':
                y++;
                current_character = char_down;
                if (mapData.TDVEC[y+4][x+2] != ' ') {
                    y--;
                    break;
                }
                break;

            case 'a':
                x-=2;
                current_character = char_left;
                if (mapData.TDVEC[y+4][x] != ' '|| mapData.TDVEC[y+4][x+1] != ' ') {
                    x+=2;
                    break;
                }
                break;

            case 'd':
                x+=2;
                current_character = char_right;
                if (mapData.TDVEC[y+4][x+4] != ' ' || mapData.TDVEC[y+4][x+3] != ' ') {
                    x-=2;
                    break;
                }
                break;
        }

        // Keep character within screen boundaries
        if (x < 1) {
            x = 1;
        } if (y < 3) {
            y = 2;
        } if (x >= screen_width - 5) {
            x = screen_width - 6;
        } if (y >= screen_height - 5) {
            y = screen_height - 5;
        }
        //for later: add coordinates of objects for each map, so that character can't pass

        for (int i = 0; i < charsize; i++) {
            for (int j = 0; j < current_character[i].length(); j++) {
                if (current_character[i][j] != '~') {
                    mvaddch(y+i, x+j, current_character[i][j]);
                }
            }
        }
//        mvaddch(y, x, 'O');

        // Refresh screen
        refresh();

    }
    // Clean up ncurses
    endwin();
    return 0;
}

void printInventory(vector<string> inventory) {
    int inv_height = 20;
    int inv_width = 40;

    initscr();
    raw();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);

    WINDOW* inventoryWin = createInventoryWindow(inv_height, inv_width);

    mvwprintw(inventoryWin, 1, 1, "Inventory:");
    for (int i = 0; i < inventory.size(); i++) {
        mvwprintw(inventoryWin, i + 2, 1, "%d. %s", i + 1, inventory[i].c_str());
    }
    wrefresh(inventoryWin);

    //screen displayed until 'q' is pressed
    while (true) {              // consider while ((key_input = getch()) != 27) {
        int ch = getch();
        if (ch == 'q') {
            break;
        }
    }

    delwin(inventoryWin);
    endwin();
}

WINDOW* createInventoryWindow(int inv_height, int width) {
    int startY = (LINES - inv_height) / 2;
    int startX = (COLS - width) / 2;

    WINDOW* win = newwin(inv_height, width, startY, startX);
    box(win, 0, 0);
    refresh();
    wrefresh(win);

    return win;
}

void addItem(vector<string>& inventory, string item) {
    ofstream outputFile("/Users/M1/CLionProjects/1340GP/UI/inventory.txt", ios::app); // Open the file in append mode
    if (outputFile.is_open()) {
        inventory.push_back(item);
        outputFile << item << endl; // Write the item to the file
        outputFile.close(); // Close the file
        cout << "Added " << item << " to the inventory." << endl;
    } else {
        cout << "Unable to open file for writing." << endl;
    }
