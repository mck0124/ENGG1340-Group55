#ifndef MAPLOADER_H
#define MAPLOADER_H

#include <vector>
#include <fstream>
#include <ncurses.h>

using namespace std;

struct VectorWrapper{
    vector<vector<char> > TDVEC;
};

class Maps
{
private:
    int Map_height;
    int Map_width;
public:
    Maps(int,int);
    int map_height;
    int map_width;
    VectorWrapper Map_Loader(string &file_path);
    VectorWrapper MapToArray(ifstream&);
    void Map_printer(VectorWrapper, int, int, int, int, WINDOW*);
};

#endif
