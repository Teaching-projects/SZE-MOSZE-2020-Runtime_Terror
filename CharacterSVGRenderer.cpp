#include "CharacterSVGRenderer.h"

void CharacterSVGRenderer::render(const Game &game) const
{
    std::ofstream file;
    file.open(filename);
    file << "<svg xmlns=\"http://www.w3.org/2000/svg\">";

    std::string currentTexture;

    const int startY = game.heroY - game.hero->getLightRadius() > 0 ? game.heroY - game.hero->getLightRadius() : 0;
    const int endY = game.heroY + game.hero->getLightRadius() + 1 < game.map.getHeight() ? game.heroY + game.hero->getLightRadius() + 1 : game.map.getHeight();

    for (int y = startY; y < endY; y++) 
    {  
        const int startX = game.heroX - game.hero->getLightRadius() > 0 ? game.heroX - game.hero->getLightRadius() : 0;
        const int endX = game.heroX + game.hero->getLightRadius() + 1 < game.map.getWidth(y) ? game.heroX + game.hero->getLightRadius() + 1 : game.map.getWidth(y);   

        for (int x = startX; x < endX; x++) 
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

            file << "<image x=\"" << (x - startX) * 10 << "\" y=\"" << (y - startY) * 10 << "\" width=\"10\" height=\"10\" href=\"" << currentTexture << "\" />";
        }
    }    
    file << "</svg>";
    file.close();
}