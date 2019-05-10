#include "Grid_H.hpp"
#include <iostream>
#include <string>
using namespace std;

Grid::Grid() {
  ourGrid[0][0] = Panel("Wall");
  ourGrid[0][1] = Panel("Wall");
  ourGrid[0][2] = Panel("Empty");
  ourGrid[1][0] = Panel("Empty");
  ourGrid[1][1] = Panel("Wall");
  ourGrid[1][2] = Panel("Wall");
  ourGrid[2][0] = Panel("Wall");
  ourGrid[2][1] = Panel("Empty");
  ourGrid[2][2] = Panel("Wall");
  ourGrid[3][0] = Panel("Wall");
  ourGrid[3][1] = Panel("Empty");
  ourGrid[3][2] = Panel("Wall");
  ourGrid[4][0] = Panel("Wall");
  ourGrid[4][1] = Panel("Wall");
  ourGrid[4][2] = Panel("Empty");
}

void Grid::display()const
{
  for(int i = 0; i < 5; i++)
  {
    for(int y = 0; y < 3; y++)
    {
      if(y == 0)
        cout << "| ";
      cout << ourGrid[i][y] << " ";
      if(y == 2)
        cout << "|\n";
    }
  }
}

ostream& operator <<(ostream& out, const Grid& myGrid)
{
  myGrid.display();
  return out;
}
