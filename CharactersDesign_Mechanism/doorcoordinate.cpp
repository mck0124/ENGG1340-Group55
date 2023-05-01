#include "doorcoordinate.h"
#include <iostream>

using namespace std;

map<string,coordinates> Corridor;
map<string,coordinates> Stairs;

coordinates ClassRoom = {21,14};
coordinates ClubRoom = {75,13};
coordinates MusicRoom = {77,14};
coordinates TeachersOffice = {104,14};
coordinates RoofTopStairs = {107,23};
coordinates ToCorridor = {48,30};
coordinates RoofTop = {48,14};
coordinates DiningRoom = {21,44};///
coordinates RestRoom = {38,14};///

void initialize(){
    Corridor.insert({"ClassRoom",ClassRoom});
    Corridor.insert({"ClubRoom",ClubRoom});
    Corridor.insert({"MusicRoom",MusicRoom});
    Corridor.insert({"TeachersOffice",TeachersOffice});
    Corridor.insert({"RoofTopStairs",RoofTopStairs});
    Corridor.insert({"DiningRoom",DiningRoom});
    Corridor.insert({"RestRoom",RestRoom});

    Stairs.insert({"ToCorridor",ToCorridor});
    Stairs.insert({"RoofTop",RoofTop});
}

void clears()
{
    Corridor.clear();
    Stairs.clear();
}
