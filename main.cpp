#include <iostream>
#include <string>
#include <time.h>
#include <vector>

#include "Unit.h"
#include "Game.h"

using namespace std;

int main(int argc, char *argv[])
{
    try {
        Unit a = Unit::parseUnit("unit/"+string(argv[1]));
        Unit b = Unit::parseUnit("unit/"+string(argv[2]));
        Game game = Game(a, b);
        return 0;
    } catch(const std::runtime_error& e) {
        std::cerr << "exception: " << e.what() << std::endl; 
        return 1;
    }
}