#include <iostream>
#include <string>
#include <time.h>
#include <vector>

#include "Unit.h"
#include "Game.h"

using namespace std;

int main(int argc, char *argv[])
{
    Unit player = Unit(argv[1], stoi(argv[2]), stoi(argv[3]));
    Unit enemy = Unit(argv[4], stoi(argv[5]), stoi(argv[6]));
    Game game = Game(player, enemy);
}