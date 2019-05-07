#ifndef PANEL_H
#define PANEL_H
#include <iostream>
using namespace std;


class Panel
{
    public:
        Panel() {display_char = '=';}
        Panel(char newChar) {display_char = newChar;}
        char getChar()const {return display_char;}
        void setChar(char newChar) {display_char = newChar;}
         display()

    private:
        char display_char;
};

#endif // PANEL_H
