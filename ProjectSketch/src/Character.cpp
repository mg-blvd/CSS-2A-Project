#include "Character.h"
#include <iostream>
using namespace std;

Character::Character()
{
    //ctor
    life = 3;
}
Character::Character(int life)
{
    this -> life = life;
}
void Character::display()
{
    cout << "*";
}
