#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <random>
#include "../CharactersDesign_Mechanism/doorcoordinate.h"
#include "../CharactersDesign_Mechanism/MainEngine.h"
#include "../CharactersDesign_Mechanism/MapLoader.h"

using namespace std;

string startpath = "CharactersDesign_Mechanism/startpage.txt";
Maps Start(28, 104);
VectorWrapper StartData = Start.Map_Loader(startpath);

bool display_instructions(VectorWrapper StartData);

string get_username();

class rooms
{
public:
    void ClassRoom();
    void ClubRoom();
    void MusicRoom();
    void DiningRoom();
    void RestRoom();
    void TeachersOffice();
    int RoofTop();
    string SchoolMap(int,int);
    string RoofTopStairs(int,int);
    string roomchooser(int);
};

// Seed the random number generator with the current time
mt19937 rng(time(nullptr));

// Define an array of letters to choose from
char letters[] = {'M', 'T', 'D', 'C', 'R'};

// Get the size of the array
int numLetters = sizeof(letters) / sizeof(letters[0]);

// Generate a random index into the array
uniform_int_distribution<int> indexDist(0, numLetters - 1);
int randIndex = indexDist(rng);

// Get the random room from the array
char randroom = letters[randIndex];

// seed the random number generator
random_device rd;
mt19937 gen(rd());

// define the range of values
uniform_int_distribution<int> valueDist(1, 6);

// generate a random number
int randnum = valueDist(gen);
std::string str_randnum = std::to_string(randnum);

int main()
{
    initialize();
    reset_inventory();
    reset_roomflag();
    reset_username();
    int a;
    int b;
    int *x = new int;
    int *y = new int;
    bool intro_flag = true;
    int counter = 0;
    string exitto;
    string previous;
    string exitfrom;
    string entered;
    bool flag = true;

    Maps mp(28, 104);
    string filep = "CharactersDesign_Mechanism/startpage.txt";
    VectorWrapper start = mp.Map_Loader(filep);

    while (intro_flag)
    {
        initscr();
        start_color();
        init_pair(1, COLOR_RED, COLOR_BLACK); // Pair 1: Red text on the default background
        init_pair(2, COLOR_GREEN, COLOR_BLACK); // Pair 2: Green text on the default background
        init_pair(3, COLOR_BLUE, COLOR_BLACK); // Pair 3: Blue text on the default background
        init_pair(4, COLOR_YELLOW, COLOR_BLACK); // Pair 4: Yellow text on the default background
        clear();
        refresh();
        curs_set(0);
        noecho();

        int screen_rows, screen_cols;
        getmaxyx(stdscr, screen_rows, screen_cols); // Get the size of the screen

        int row_offset = (screen_rows - 28) / 2;
        int col_offset = (screen_cols - 104) / 2;

        for (int i = 0; i < start.TDVEC.size(); i++) {
            for (int j = 0; j < start.TDVEC[i].size(); j++) {
                if (start.TDVEC[i][j] == '.') {
                    continue; // Skip '.' characters
                }
                if (i < 17) {
                    attron(COLOR_PAIR(1));
                    mvprintw(row_offset + i, col_offset + j, "%c", start.TDVEC[i][j]);
                    attroff(COLOR_PAIR(1));
                } else if (i < 19) {
                    attron(COLOR_PAIR(3));
                    mvprintw(row_offset + i, col_offset + j, "%c", start.TDVEC[i][j]);
                    attroff(COLOR_PAIR(3));
                } else {
                    attron(COLOR_PAIR(2));
                    mvprintw(row_offset + i, col_offset + j, "%c", start.TDVEC[i][j]);
                    attroff(COLOR_PAIR(2));
                }
            }
            // Write start_time to the text file
            time_t start_time = time(NULL);
            std::ofstream out_file("start_time.txt");
            if (out_file) {
                out_file << start_time;
                out_file.close();
            }
        }

        refresh();

        if (getch() == '1')
        {
            flag = true;
            intro_flag = false;
        }
        else if (getch() == '2')
        {
            intro_flag = display_instructions(start);
        }
        clear(); // Clear the screen
        refresh(); // Refresh the screen after clearing
    }
    string username = get_username();
    // Create a text file with the username
    std::ofstream username_file("username.txt");
    if (username_file) {
        username_file << username;
        username_file.close();
    }
    rooms RM;
    while (flag)
    {
        if (counter == 0)
        {
            *x = 43, *y = 14;
            string file_path = "Map_Objects/Map_resources/Classroom.txt";
            main_engine(file_path,*x,*y);
            entered="SchoolMap";
            *x = Corridor["ClassRoom"].x_coordinates;
            *y = Corridor["ClassRoom"].y_coordinates;
            counter++;
        }

        if (entered == "ClassRoom")
        {
            RM.ClassRoom();
            exitfrom = "ClassRoom";
            *x = Corridor[exitfrom].x_coordinates;
            *y = Corridor[exitfrom].y_coordinates;
            entered = "SchoolMap";
        }
        else if (entered == "ClubRoom")
        {
            RM.ClubRoom();
            exitfrom = "ClubRoom";
            *x = Corridor[exitfrom].x_coordinates;
            *y = Corridor[exitfrom].y_coordinates;
            entered = "SchoolMap";
        }
        else if (entered == "MusicRoom")
        {
            RM.MusicRoom();
            exitfrom = "MusicRoom";
            *x = Corridor[exitfrom].x_coordinates;
            *y = Corridor[exitfrom].y_coordinates;
            entered = "SchoolMap";
        }
        else if (entered == "TeachersOffice")
        {
            RM.TeachersOffice();
            exitfrom = "TeachersOffice";
            *x = Corridor[exitfrom].x_coordinates;
            *y = Corridor[exitfrom].y_coordinates;
            entered = "SchoolMap";
        }
        else if (entered == "DiningRoom")
        {
            RM.DiningRoom();
            exitfrom = "DiningRoom";
            *x = Corridor[exitfrom].x_coordinates;
            *y = Corridor[exitfrom].y_coordinates;
            entered = "SchoolMap";
        }
        else if (entered == "RestRoom")
        {
            RM.RestRoom();
            exitfrom = "RestRoom";
            *x = Corridor[exitfrom].x_coordinates;
            *y = Corridor[exitfrom].y_coordinates;
            entered = "SchoolMap";
        }
        else if (entered == "RoofTop")
        {
            int u = RM.RoofTop();
            exitfrom = "RoofTop";
            previous = "ToRoofTop";
            entered = "RoofTopStairs";
            if (u==99)
            {
                break;
            }
        }
        else if (entered == "RoofTopStairs")
        {
            *x = Stairs[previous].x_coordinates;
            *y = Stairs[previous].y_coordinates;
            exitto = RM.RoofTopStairs(*x,*y);
            if (exitto == "NONE")
            {
                *x = Corridor["RoofTopStairs"].x_coordinates;
                *y = Corridor["RoofTopStairs"].y_coordinates;
                entered = "SchoolMap";
            }
            else if (exitto == "RoofTop")
            {
                *x = Stairs["RoofTop"].x_coordinates;
                *y = Stairs["RoofTop"].y_coordinates;
                entered = exitto;
            }

        }
        else if (entered == "SchoolMap")
        {
            previous = "ToCorridor";
            entered = RM.SchoolMap(*x,*y);
        }
    }

    //ending page
    int ending_height = 25;
    int ending_width = 64;
    string object;

    initscr();
    raw();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);

    string filePath = "UI/endingpage.txt";
    ifstream inputFile(filePath);
    string line;

    WINDOW* endingWin = CreateWindow(ending_height, ending_width); // create window for each file
    box(endingWin, 0, 0);

    int row = 1; // start at row 1
    wattron(endingWin, COLOR_PAIR(2));
    while (getline(inputFile, line)) {
        mvwprintw(endingWin, row, 1, "%s", line.c_str());
        row++; // increment row after printing the line
    }
    wattroff(endingWin, COLOR_PAIR(2));
    wrefresh(endingWin);

    while (true) {
        int ch = getch();
        if (ch == 10) {
            break;
        }
    }

    werase(endingWin); // clear the window
    wrefresh(endingWin); // redraw the window

    delwin(endingWin); // delete window after displaying the file
    inputFile.close();

    endwin();


    delete x;
    delete y;
}
//coordinates inside each room (point on feet)
void rooms::ClassRoom()
{
    string file_path = "Map_Objects/Map_resources/Classroom.txt";
    int x_door = 87;
    int y_door = 26;
    main_engine(file_path,x_door,y_door);
}
void rooms::ClubRoom()
{
    string file_path;
    if (randroom != 'C') {
        file_path = "Map_Objects/Map_resources/Club Room .txt";
        int file_length = file_path.length();
        file_path.insert(file_length - 4, str_randnum);
    }
    else {
        file_path = "Map_Objects/Map_resources/Club Room.txt";
    }

    int x_door = 20;
    int y_door = 5;
    main_engine(file_path,x_door,y_door);
}

void rooms::MusicRoom()
{
    string file_path;
    if (randroom != 'M') {
        file_path = "Map_Objects/Map_resources/Music Room .txt";
        int file_length = file_path.length();
        file_path.insert(file_length - 4, str_randnum);
    }
    else {
        file_path = "Map_Objects/Map_resources/Music Room.txt";
    }
    int x_door = 79;
    int y_door = 5;
    main_engine(file_path,x_door,y_door);
}

int rooms::RoofTop()
{
    string file_path = "Map_Objects/Map_resources/Rooftop6.txt";
    int x_door = 44;
    int y_door = 20;
    int a = main_engine(file_path,x_door,y_door);
    return a;
}

void rooms::TeachersOffice()
{
    string file_path;
    if (randroom != 'T') {
        file_path = "Map_Objects/Map_resources/Teacher's office .txt";
        int file_length = file_path.length();
        file_path.insert(file_length - 4, str_randnum);
    }
    else {
        file_path = "Map_Objects/Map_resources/Teacher's office.txt";
    }

    int x_door = 86;
    int y_door = 26;
    main_engine(file_path,x_door,y_door);
}

void rooms::RestRoom()
{
    string file_path;
    if (randroom != 'R') {
        file_path = "Map_Objects/Map_resources/Restroom .txt";
        int file_length = file_path.length();
        file_path.insert(file_length - 4, str_randnum);
    }
    else {
        file_path = "Map_Objects/Map_resources/Restroom.txt";
    }

    int x_door = 86;
    int y_door = 26;
    main_engine(file_path,x_door,y_door);

}

void rooms::DiningRoom()
{
    str_randnum = "5";
    string file_path;
    if (randroom != 'D') {
        file_path = "Map_Objects/Map_resources/Dining Room .txt";
        int file_length = file_path.length();
        file_path.insert(file_length - 4, str_randnum);
    }
    else {
        file_path = "Map_Objects/Map_resources/Diningroom.txt";
    }
    int x_door = 64;
    int y_door = 5;
    main_engine(file_path,x_door,y_door);
}

string rooms::RoofTopStairs(int a,int b)
{
    string file_path = "Map_Objects/Map_resources/Rooftop stairs.txt";
    int x_door = a;
    int y_door = b;
    int C_Or_R = main_engine(file_path,x_door,y_door);
    return roomchooser(C_Or_R);
}

string rooms::SchoolMap(int a,int b)
{
    string file_path = "Map_Objects/Map_resources/schoolmap.txt";
    int x_door = a;
    int y_door = b;
    int roomdecider = main_engine(file_path,x_door,y_door);
    return roomchooser(roomdecider);
}

string rooms::roomchooser(int roomdecider){
    switch (roomdecider)
    {
        case 1:
            return "ClassRoom";
            break;
        case 2:
            return "RestRoom";
            break;
        case 3:
            return "ClubRoom";
            break;
        case 4:
            return "TeachersOffice";
            break;
        case 5:
            return "MusicRoom";
            break;
        case 6:
            return "DiningRoom";
            break;
        case 7:
            return "RoofTop";
            break;
        case 8:
            return "RoofTopStairs";
            break;
        default:
            return "NONE";
            break;
    }
}

bool display_instructions(VectorWrapper StartData) {
    bool flag = true;
    clear();

    attron(COLOR_PAIR(1));
    printw("\n");
    printw("  ___ _  _ ___ _____ ___ _   _  ___ _____ ___ ___  _  _ ___ \n");
    printw(" |_ _| \\| / __|_   _| _ \\ | | |/ __|_   _|_ _/ _ \\| \\| / __|\n");
    printw("  | || .` \\__ \\ | | |   / |_| | (__  | |  | | (_) | .` \\__ \\ \n");
    printw(" |___|_|\\_|___/ |_| |_|_\\\\___/ \\___| |_| |___\\___/|_|\\_|___/\n");
    printw("                                                        ");
    printw("\n");
    attroff(COLOR_PAIR(1));
    attron(COLOR_PAIR(4));
    printw("1. Welcome to horror school escape game!\n");
    printw("\n");
    printw("2. You will have to find the key(s) to escape from the school, which is presented as *.\n");
    printw("\n");
    printw("3. You have to press 'F' to pick up *.\n");
    printw("\n");
    printw("4. You can move your character by using 'W, A, S, D' in your keyboard to move to another place. (W = up, S = down, A = left, D = right)\n");
    printw("\n");
    printw("5. You can press 'I' to open/close your inventory and 'M' to open/close the menu.\n");
    printw("\n");
    printw("6. Your flashlight will lose battery as time passes, so find a battery before it dies out! \n");
    printw("\n");
    printw("! PLEASE KEEP GOING FORWARD WHEN PASSING THE DOOR !\n");
    printw("\n");
    printw("! PLEASE PRESS ENTER TO SKIP POP-UP MESSAGES !\n");
    printw("\n");
    printw("\nPress Enter to return to the start page.");
    attroff(COLOR_PAIR(4));

    refresh();

    // Wait for the user to press Enter
    int ch;
    while (getch()!='\n')
    {

    }
    return true;
}

string get_username() {
    char user_input[50]; // Create a char array to store the user input
    echo(); // Enable echo to display typed characters
    curs_set(1); // Show the cursor

    int screen_rows, screen_cols;
    getmaxyx(stdscr, screen_rows, screen_cols);

    int username_row = screen_rows / 2;
    int username_col = (screen_cols - 20) / 2;

    clear();
    mvprintw(username_row, username_col, "Enter your username: ");
    refresh();
    getstr(user_input); // Read the input into the char array

    noecho(); // Disable echo
    curs_set(0); // Hide the cursor

    string username(user_input); // Convert char array to string
    return username;
}