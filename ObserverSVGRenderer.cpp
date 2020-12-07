#include "ObserverSVGRenderer.h"

void ObserverSVGRenderer::render(const Game& game) const 
{
    std::ofstream file;
    file.open(filename);
    file << "<svg xmlns=\"http://www.w3.org/2000/svg\" >";

    std::string currentTexture;

    for (int y = 0; y < game.map.getHeight(); y++) 
    {
        for (int x = 0; x < game.map.getWidth(y); x++) 
        {   
            if(game.map.get(x, y) == game.map.type::Wall) currentTexture = game.wallTexture;
            else if (game.heroX == x && game.heroY == y) currentTexture = game.hero->getTexture();
            else
            {
                int monsterCount = 0;
                int monsterIndex = -1;

                for (size_t i = 0; i < game.monsterPlaces.size(); i++) 
                {
                    if(game.monsterPlaces[i].x == x && game.monsterPlaces[i].y == y && game.monsterPlaces[i].monster.isAlive())
                    {
                        monsterCount++;
                        if(monsterIndex == -1) monsterIndex = i;
                    }
                }

                if (monsterCount >= 1) currentTexture = game.monsterPlaces[monsterIndex].monster.getTexture();
                else currentTexture = game.freeTexture;
            }

            file << "<image x=\"" << x * 10 << "\" y=\"" << y * 10 << "\" width=\"10\" height=\"10\" href=\"" << currentTexture << "\" />";                                         
        }
    }   
    file << "</svg>";
    file.close();
}