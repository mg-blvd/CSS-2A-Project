#include "Character.h"
#include <iostream>
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
    pos = 0;
}
void Character::display()
{
    cout << "! ";
    for(unsigned i = 0; i < 3; i++)
    {
      if(i == pos)
        cout << signal << " ";
      else
        cout << "| ";
    }
    cout << '!' << endl;
}

void Character::moveChar(char direction)
{
  if(direction == 'a')
  {
    if(pos > 0)
      pos -= 1;
  }
  else if(direction == 'd')
  {
    if(pos < 2)
      pos += 1;
  }
}

void Character::loseHealth()
{
  life -= 1;
}
