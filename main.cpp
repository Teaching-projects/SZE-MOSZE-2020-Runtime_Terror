#include <iostream>
#include <string>
#include <time.h>
#include <vector>

#include "Unit.h"
#include "Game.h"

using namespace std;

int main(int argc, char *argv[])
{
    Unit a = Unit::parseUnit("unit/"+string(argv[1]));
    Unit b = Unit::parseUnit("unit/"+string(argv[2]));

    Game game = Game(a, b);
}