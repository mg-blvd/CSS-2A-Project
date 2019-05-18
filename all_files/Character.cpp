#include "Character.h"
#include <iostream>
#include <windows.h>
using namespace std;



Character::Character()
{
    //ctor
    life = 3;
    signal = '^';
    pos = 1;
}
Character::Character(int life)
{
    this -> life = life;
    signal = '^';
    pos = 1;
}
void Character::display()
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 1);
    cout << "! ";
    for(unsigned i = 0; i < 3; i++)
    {
      if(i == pos)
      {
        SetConsoleTextAttribute(hConsole, 6);
        cout << signal << " ";
      }
      else
      {
        SetConsoleTextAttribute(hConsole, 14);
        cout << "| ";
      }
    }
    SetConsoleTextAttribute(hConsole, 1);
    cout << '!' << endl;
}

void Character::moveChar(char direction)
{
  if(direction == 'a')
  {
    //If pos is already zero, then the position will decrement anymore. Position 0 is the leftmost
    // you can be.
    if(pos > 0)
      pos -= 1;
  }
  else if(direction == 'd')
  {
    //If pos is already 2, then the position will not increment anymore. Position 2 is the rightmost
    //you can go.
    if(pos < 2)
      pos += 1;
  }
}

void Character::loseHealth()
{
  life -= 1;
}
