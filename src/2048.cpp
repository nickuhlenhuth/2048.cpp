#include "2048.hpp"
#include "menu.hpp"
#include <sstream>
#include <iostream>


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
  return 0;
}
