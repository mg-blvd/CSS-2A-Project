#ifndef Grid_H
#define Grid_H
#include "Panel.h"
#include <iostream>
#include <fstream>
using namespace std;

class Grid {
  public:
    Grid();
    Grid(Panel p1, Panel p2, Panel p3);
    void display() const;
    void displayLine(int lineNum)const;
    void displayBlanks()const;
    char getPanelChar(int row, int col)const {return ourGrid[row][col].getChar();}
    Panel getPanel(int row, int col)const {return ourGrid[row][col];}
    friend ostream& operator << (ostream& out, const Grid& myGrid);
  private:
     Panel ourGrid[5][3];
};
#endif
