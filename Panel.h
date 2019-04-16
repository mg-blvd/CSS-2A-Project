#ifndef PANEL_H
#define PANEL_H


class Panel
{
    public:
        Panel();
        char getDisplay()const {return display_char;}

    private:
        char display_char;
};

#endif // PANEL_H
