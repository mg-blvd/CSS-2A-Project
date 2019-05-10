#include "Panel.h"
#include <string>
using namespace std;


Panel::Panel()
{
  displayChar = '=';
}

Panel::Panel(string newChar)
{
  if(newChar == "Wall")
    setChar('=');
  else if(newChar == "Empty")
    setChar('|');
  else
    setChar('|');
}

ostream& operator << (ostream& out, const Panel& myPanel)
{
  myPanel.display();
  return out;
}
