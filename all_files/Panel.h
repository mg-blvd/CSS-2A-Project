#ifndef PANEL_H
#define PANEL_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


class Panel
{
    public:
        //*****************************************************************************************
        Panel();
        //Summary: Creates a Panel object. The Character will be '='.
        //Preconditions: N/A
        //Postcondition: An object is created with the directions from the constructor.
        //*****************************************************************************************

        //*****************************************************************************************
        Panel(string newChar);
        //Summary: This will take in a string called newChar. If newChar is "Wall", then the
        //         character will be '='. Else, the character will be '|'.
        //Precondition: A string must be passed into the constructor.
        //Postcondition: An object will be created based on the string that was passed in.
        //*****************************************************************************************
        char getChar()const {return displayChar;}
        void setChar(char newChar) {displayChar = newChar;}
        void display()const {cout << displayChar;}
        friend ostream& operator << (ostream& out, const Panel& myPanel);

    private:
        char displayChar;
};

#endif // PANEL_H
