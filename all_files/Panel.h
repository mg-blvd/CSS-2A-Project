#ifndef PANEL_H
#define PANEL_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


class Panel
{
    public:
        Panel();
        Panel(string newChar);
        char getChar()const {return displayChar;}
        void setChar(char newChar) {displayChar = newChar;}
        void display()const {cout << displayChar;}
        friend ostream& operator << (ostream& out, const Panel& myPanel);

    private:
        char displayChar;
};

#endif // PANEL_H
