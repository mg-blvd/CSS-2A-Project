#include "Grid_H.hpp"
#include <iostream>
#include <string>
using namespace std;

Grid::Grid() {
  for(int r = 0; r < 20; r++) {
    for(int c = 0; c < 20; c++) {
      if(r == 0 || r == 19 || c == 0 || c == 19) {
        cout << gridChar << " ";
      }
      else cout << "  ";
    }
    cout << endl;
  }
}
