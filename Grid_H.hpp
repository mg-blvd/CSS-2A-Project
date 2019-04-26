#ifndef Grid_H
#define Grid_H

class Grid {
  public: 
    Grid();
    
    //void setGridChar() {this -> gridChar = gridChar;}

    char getGridChar(char gridChar) {return gridChar;}
  private:
    char gridChar ='-';
};
#endif
