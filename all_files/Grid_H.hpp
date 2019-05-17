#ifndef Grid_H
#define Grid_H
#include "Panel.h"
#include <iostream>
#include <fstream>
using namespace std;

class Grid {
  public:
    //*********************************************************************************************
    Grid();
    //Summary: This function will create a randomly generated grid. At least only one panel object
    //         in our grid will be an empty space (have '|' as its character).
    //Precondition: N/A
    //Postcondition: The grid is created with randomly generated panels.
    //*********************************************************************************************

    //*********************************************************************************************
    Grid(Panel p1, Panel p2, Panel p3);
    //Summary: This constructor will create a grid. The first row will have the panels in the order
    //         that they are inputed into this constructor. All the other rows will be randomly
    //         generated.
    //Precondition: Three Panel object must be passed in. These will constitute the first line of
    //              grid.
    //Postcondition: The grid is created with the preset first line and with the randomly generated
    //               subsequent lines.
    //*********************************************************************************************

    //*********************************************************************************************
    void display() const;
    //Summary: This will print out the entire grid.
    //Precondition: N/A
    //Postcondition: The grid was printed out to the console.
    //*********************************************************************************************

    //*********************************************************************************************
    void displayLine(int lineNum)const;
    //Summary: This function only prints out the specific line of the number that was passed into
    //         the function.
    //Precondition: A number is passed in.
    //Postcondition: The line was printed out to the console.
    //*********************************************************************************************

    //*********************************************************************************************
    void displayBlanks()const;
    //Summary: Prints out a line of blanks ('|').
    //Precondition: N/A
    //Postcondition: The line is printed.
    //*********************************************************************************************
    char getPanelChar(int row, int col)const {return ourGrid[row][col].getChar();}
    Panel getPanel(int row, int col)const {return ourGrid[row][col];}
    friend ostream& operator << (ostream& out, const Grid& myGrid);
  private:
     Panel ourGrid[5][3];
};
#endif
