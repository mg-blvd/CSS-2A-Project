#include <iostream>
#include <cctype>
#include <conio.h>
#include "Grid_H.hpp"
#include "Panel.h"
#include "Character.h"

using namespace std;

void playGame(Grid& table, Character& player);
int getSecondLine(int currLine);
void phase1(const Grid& table, Character& player, int lineNum);
void phase2(const Grid& table, Character& player, int lineNum);
void phase3(Grid& table, Character& player, int lineNum);

int main() {
  Grid newGrid;
  Character hero;
  char choice;
  cout << "Press the 'a' key to move left.\n";
  cout << "Press the 'd' key to move right.\n";
  cout << "Press the g key to start.\n";
  cin >> choice;
  if(tolower(choice) == 'g')
    playGame(newGrid, hero);
  else
    cout << "Thanks for playing.\n";
  return 0;
}

void playGame(Grid& table, Character& player)
{
  char direction;
  while(player.getLife() > 0)
  {
    for(int i = 0; i < 4; i++)
    {
      phase1(table, player, i);
      direction = getch();
      player.moveChar(direction);
      phase2(table, player, i);
      direction = getch();
      player.moveChar(direction);
      phase3(table, player, i);
      if(player.getLife() == 0)
        break;
      direction = getch();
      player.moveChar(direction);
    }
  table = Grid(table.getPanel(4, 0), table.getPanel(4, 1), table.getPanel(4, 2));
  }
}

int getSecondLine(int currLine)
{
  if(currLine == 4)
    return 0;
  return currLine + 1;
}

void phase1(const Grid& table, Character& player, int lineNum)
{
  int secondLine = getSecondLine(lineNum);
  table.displayLine(secondLine);
  table.displayBlanks();
  table.displayBlanks();
  table.displayLine(lineNum);
  table.displayBlanks();
  player.display();
}

void phase2(const Grid& table, Character& player, int lineNum)
{
  int secondLine = getSecondLine(lineNum);
  table.displayBlanks();
  table.displayLine(secondLine);
  table.displayBlanks();
  table.displayBlanks();
  table.displayLine(lineNum);
  player.display();
}

void phase3(Grid& table, Character& player, int lineNum)
{
  int secondLine = getSecondLine(lineNum);
  table.displayBlanks();
  table.displayBlanks();
  table.displayLine(secondLine);
  table.displayBlanks();
  table.displayBlanks();
  cout << "! ";
  for(int i = 0; i < 3; i++)
  {
    if(player.getPos() == i)
      cout << player.getChar() << " ";
    else
      cout << table.getPanelChar(lineNum, i) << " ";
  }
  cout << "!" << endl;
  if(table.getPanelChar(lineNum, player.getPos()) == '=')
  {
    player.loseHealth();
    cout << "Hit a wall. Player health is now " << player.getLife() << endl;
  }
}
