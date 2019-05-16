#ifndef CHARACTER_H
#define CHARACTER_H

using namespace std;
class Character
{
    public:
        Character();
        Character(int life);
        // getter and setters
        int getLife()const {return life;}
        int getPos()const {return pos;}
        char getChar()const {return signal;}
        void setLife(int life) {this -> life = life;}
        void moveChar(char direction);
        void loseHealth();
        // member functions
        void display();
    private:
        int life;
        char signal;
        int pos;
};

#endif // CHARACTER_H
