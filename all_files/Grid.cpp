#include "Grid_H.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

Grid::Grid() {
  int spacePos;
  srand(static_cast<unsigned>(time(NULL)));
  for(int i = 0; i < 5; i++)
  {
    spacePos = rand() % 3;
    for(int y = 0; y < 3; y++)
    {
      if(y == spacePos)
        ourGrid[i][y] = Panel("Empty");
      else
        ourGrid[i][y] = Panel("Wall");
    }
  }
}

Grid::Grid(Panel p1, Panel p2, Panel p3)
{
  ourGrid[0][0] = p1; ourGrid[0][1] = p2; ourGrid[0][2] = p3;
  int spacePos;
  srand(static_cast<unsigned>(time(NULL)));
  for(int i = 1; i < 5; i++)
  {
    spacePos = rand() % 3;
    for(int y = 0; y < 3; y++)
    {
      if(y == spacePos)
        ourGrid[i][y] = Panel("Empty");
      else
        ourGrid[i][y] = Panel("Wall");
    }
  }
}

void Grid::display()const
{
  for(int i = 0; i < 5; i++)
  {
    displayLine(i);
  }
}

void Grid::displayLine(int lineNum)const
{
  for(int y = 0; y < 3; y++)
  {
    if(y == 0)
      cout << "! ";
    cout << ourGrid[lineNum][y] << " ";
    if(y == 2)
      cout << "!\n";
  }
}

void Grid::displayBlanks()const
{
  cout << "! | | | !\n";
}

ostream& operator <<(ostream& out, const Grid& myGrid)
{
  myGrid.display();
  return out;
}
