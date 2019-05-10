#ifndef Grid_H
#define Grid_H
#include "Panel.h"
#include <iostream>
#include <fstream>
using namespace std;

class Grid {
  public:
    Grid();
    void display() const;
    friend ostream& operator << (ostream& out, const Grid& myGrid);
  private:
     Panel ourGrid[5][3];
};
#endif
