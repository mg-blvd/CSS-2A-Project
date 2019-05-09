#ifndef CHARACTER_H
#define CHARACTER_H

using namespace std;
class Character
{
    public:
        Character();
        Character(int life);
        // getter and setters
        int getLife() {return life;}
        void setLife(int life) {this -> life = life;}
        // member functions
        void display();
    private:
        int life;
};

#endif // CHARACTER_H
