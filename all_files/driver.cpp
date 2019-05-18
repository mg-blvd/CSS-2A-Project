/* CSS-2A-Project
Authors: Misael Guijarro
         Denize Patric Ignacio
         Jennifer Lopez
         Aminata Seck
Date: 5/17/19
Class: CSS-2A
Description: This program will run an endless runner kind of game where you are supposed to run
             as long as possible without hitting a wall. The board will loop endlessly until
             your character runs out of life. The program quits when your character runs out of life.
            The last thing displayed will be your final score.*/
#include <iostream>
#include <cctype>
#include <conio.h>
#include <thread>
#include <windows.h>
#include <stdlib.h>
#include "Grid_H.hpp"
#include "Panel.h"
#include "Character.h"

using namespace std;


//*************************************************************************************************
void playGame(Grid& table, Character& player);
//Summary: With help from other functions, this function organizes the game logic. It starts the
//         game process, begins the thread that will loop and refresh the game board. It will also
//         read in any input from the user to move the character.
//Precondition: The Grid and Character objects that will be used in the game must be passed into the
//              the game. This are really important and the code cannot work without them.
//Postcondition: The game should have been simulated in the console and your final score should have
//               displayed.
//*************************************************************************************************

//*************************************************************************************************
int getSecondLine(int currLine);
//Summary: This is a helper function which will return the second line that should be displayed in
//         the console. It takes the first line as input and figures out which should be the next.
//         Usually, it will the next number, so if you have line 1, the next line will be 2.
//         However, if currLine is 4, then the next line will be 0. This is important, since it
//         allows the grid to flow fluidly without causing any confusion.
//Precondition: The index line we are currently on must be passed in.
//Postcondition: The line of the next line must be returned.
//*************************************************************************************************

//*************************************************************************************************
void phase1(const Grid& table, Character& player, int lineNum);
//Summary: This function will print to the console the first phase of the grid. It will print out
//         the character's line, it will print out two lines of spaces, the first actual lines with
//         barriers, two more lines of empty space, and the second line of barriers.
//Precondition: The Grid object, the Character object, and an integer with the first line index
//              must be passed in. We will get the lines from the Grid, the character line and
//              position from the Character object, and the first line to print out form the lineNum
//              integer.
//Postcondition: The first phase of the game cycle must be printed to the console.
//*************************************************************************************************

//*************************************************************************************************
void phase2(const Grid& table, Character& player, int lineNum);
//Summary: This will print out the second phase of the game board printing cycle. It will print out
//         the character line first, then one line of empty space, then the first barrier line, then
//         two more lines of empty space, then the second line of barriers, and one final line of
//         empty space. This last line is important to keep the grid looking fluid.
//Preconditions: The Grid object, the Character object, and an integer with the first line index
//               must be passed in. We will get the lines from the Grid, the character line and
//               position from the Character object, and the first line to print out form the lineNum
//               integer.
//Postcondition: The second phase of the board printing cycle must be printed to the console.
//*************************************************************************************************

//*************************************************************************************************
void phase3(Grid& table, Character& player, int lineNum);
//Summary: This function will print out the third phase of the board printing sequence. It get the
//         position of the character. It will then print out the first barrier line, but the
//         position of the character will print out the character, not whatever is in the first
//         barrier array. It will then print out two rows of space, the second barrier line, and
//         the two more lines of space. If the character is in a position where a wall would be,
//         then the character's life will be decremented by 1. Else, the points will be incremented
//         by 10.
//Preconditions: The Grid object, the Character object, and an integer with the first line index
//               must be passed in. We will get the lines from the Grid, the character line and
//               position from the Character object, and the first line to print out form the lineNum
//               integer.
//Postcondition: The third phase of the board printing cycle will be printed out. If the character
//               hit a wall, a life will be decremented. If a wall was not hit, then the points
//               will be incremented by 10 points.
//*************************************************************************************************

//*************************************************************************************************
void loadBoard(Grid& table, Character& player, unsigned& score);
//Summary: This function call all the printing functions while the Character's life is still
//         greater than 0. It will clear the console between each phase to simulate a game in the
//         same position every time. It will also pause for a specific amount of time between each
//         phase to simulate movement. After every line in the Grid has been displayed, a new Grid
//         will be created, and the speed at which the board moves will be increased.
//Preconditions: A Grid, character, and score will be passed into the function. These objects will
//               be passed into the other functions when needed.
//Postcondition: The board will have gone through all the phases. It will endlessly loop until the
//               character will run out of lives.
//*************************************************************************************************

int main() {
  Grid newGrid;
  Character hero;
  char choice;
  cout << "Press the 'a' key to move left.\n";
  cout << "Press the 'd' key to move right.\n";
  cout << "Press the g key to start.\n";
  choice = getch();
  if(tolower(choice) == 'g')
    playGame(newGrid, hero);
  cout << "Thanks for playing.\n";
  return 0;
}

void playGame(Grid& table, Character& player)
{
  char direction;
  unsigned score = 0;
  //This thread will make cycle through the different phases of grid creation until the user runs
  //out of lives. It must be detached so that the user can still input direction while the board
  //is being loaded.
  thread t1(loadBoard, ref(table), ref(player), ref(score));
  t1.detach();
  //This loop reads in directions for character movement. It stops when the user runs out of
  //lives.
  while(player.getLife() > 0)
  {
      direction = getch();
      player.moveChar(direction);
  }
    cout << "Final score was " << score << ".\n";
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

void phase3(Grid& table, Character& player, int lineNum, unsigned& score)
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  int secondLine = getSecondLine(lineNum);
  table.displayBlanks();
  table.displayBlanks();
  table.displayLine(secondLine);
  table.displayBlanks();
  table.displayBlanks();
  SetConsoleTextAttribute(hConsole, 1);
  cout << "! ";
  for(int i = 0; i < 3; i++)
  {
    if(player.getPos() == i)
    {
      SetConsoleTextAttribute(hConsole, 6);
      cout << player.getChar() << " ";
    }
    else
    {
        if(table.getPanelChar(lineNum, i) == '=')
            SetConsoleTextAttribute(hConsole, 2);
        else
            SetConsoleTextAttribute(hConsole, 14);
        cout << table.getPanelChar(lineNum, i) << " ";
    }
  }
  SetConsoleTextAttribute(hConsole, 1);
  cout << "!" << endl;
  if(table.getPanelChar(lineNum, player.getPos()) == '=')
  {
    player.loseHealth();
    SetConsoleTextAttribute(hConsole, 15);
    cout << "Hit a wall. Player health is now " << player.getLife() << endl;
  }
  else
    score += 10;
}

void loadBoard(Grid& table, Character& player, unsigned& score)
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    //Speed starts off at 1000. This means that the board will refresh every second.
    int speed = 1000;
    while(player.getLife() > 0)
    {
        for(int i = 0; i < 4; i++)
        {
            phase1(table, player, i);
            Sleep(speed);
            system("CLS");
            phase2(table, player, i);
            Sleep(speed);
            system("CLS");
            phase3(table, player, i, score);
            cout << "Points = " << score << endl;
            Sleep(speed);
            system("CLS");
            if(player.getLife() == 0)
                break;
        }
        //This next line will create a new, randomly generated grid.
        table = Grid(table.getPanel(4, 0), table.getPanel(4, 1), table.getPanel(4, 2));
        //This next line increases the speed by 15 percent.
        speed *= .85;
    }
    SetConsoleTextAttribute(hConsole, 15);
    cout << "Hit any button to continue\n";
}
