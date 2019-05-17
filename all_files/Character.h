#ifndef CHARACTER_H
#define CHARACTER_H

using namespace std;
class Character
{
    public:
        //*****************************************************************************************
        Character();
        //Summary: This constructor will set the object's life to 3, the signal as '^', and the pos
        //         pos as 1.
        //Precondition: N/A
        //Postcondition: The object is created.
        //*****************************************************************************************

        //*****************************************************************************************
        Character(int life);
        //Summary: This constructor will set the object's life to the the life that was passed in,
        //         the signal as '^', and the pos as 1.
        //Precondition: N/A
        //Postcondition: The object is created.
        //*****************************************************************************************
        // getter and setters
        int getLife()const {return life;}
        int getPos()const {return pos;}
        char getChar()const {return signal;}
        void setLife(int life) {this -> life = life;}

        //*****************************************************************************************
        void moveChar(char direction);
        //Summary: This function will change the position of the object based on the direction
        //         that is passed in.
        //Precondition: A direction character must be passed in.
        //Postcondition: The position is changed.
        //*****************************************************************************************

        //*****************************************************************************************
        void loseHealth();
        //Summary: This function will decrement life by one.
        //Precondition: N/A
        //Postcondition: Life has been decremented by 1.
        //*****************************************************************************************
        // member functions

        //*****************************************************************************************
        void display();
        //Summary: This display function is catered to the game. It will display a line that is
        //         "empty" (filled with the '|' char) except wherever the character is positioned.
        //Precondition: N/A
        //Postcondition: A line is displayed to the console.
        //*****************************************************************************************
    private:
        int life;
        char signal;
        int pos;
};

#endif // CHARACTER_H
