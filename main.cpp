#include <iostream>
#include <string>
#include <time.h>
#include <vector>

#include "Unit.h"
#include "Game.h"

using namespace std;

int main(int argc, char* argv[])
{
    vector<string> data;
    for (int i = 0; i < argc; ++i) {
        data.push_back(argv[i]);
    }        

    Unit* player = new Unit(data[1], stoi(data[2]), stoi(data[3]));
    Unit* enemy = new Unit(data[4], stoi(data[5]), stoi(data[6]));

    Game game = Game(*player, *enemy);
    game.Combat();
}