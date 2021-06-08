#include "2048.hpp"
#include "menu.hpp"
#include <sstream>
#include <iostream>
#include <cstring>


#ifdef WIN32

#  include <Windows.h>

class MBuf : public std::stringbuf {
public:
  int sync() {
    fputs(str().c_str(), stdout);
    str("");
    return 0;
  }
};
#endif

int main() {
    #ifdef WIN32

    SetConsoleOutputCP(CP_UTF8);
    setvbuf(stdout, nullptr, _IONBF, 0);
    MBuf buf;
    std::cout.rdbuf(&buf);

    #endif
  Menu::startMenu();
  char a[4];
strcpy(a,"a string longer than 4 characters"); // write past end of buffer (buffer overflow)
printf("%s\n",a[6]); // read past end of buffer (also not a good idea)
  return 0;
}
