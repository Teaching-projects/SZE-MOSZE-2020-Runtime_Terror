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

        if(argc >= 2) 
        {
            Player a = Player::parsePlayer("unit/"+string(argv[1]));
            Player b = Player::parsePlayer("unit/"+string(argv[2]));

            Game game = Game(a, b);

            return 0;
        }
        else
        {
            throw std::runtime_error("wrong arguments given");
        }
        
    } catch(const std::runtime_error& e) {

        std::cerr << "exception: " << e.what() << std::endl; 
        return 1;

    }
}