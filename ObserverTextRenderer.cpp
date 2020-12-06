#include "ObserverTextRenderer.h"

void ObserverTextRenderer::render(const Game& game) const 
{
    stream << "╔";
    for(int i = 0; i < game.map.getMaxWidth(); i++) stream << "══";
    stream << "╗" << std::endl;

    for (int y = 0; y < game.map.getHeight(); y++) 
    {
        stream << "║";

        for (int x = 0; x < game.map.getWidth(y); x++) 
        {   
            if(game.map.get(x, y) == game.map.type::Wall) stream << "██";
            else if (game.heroX == x && game.heroY == y) stream << "┣┫";
            else
            {
                int monsterCount = 0;

                for (size_t i = 0; i < game.monsterPlaces.size(); i++) 
                {
                    if(game.monsterPlaces[i].x == x && game.monsterPlaces[i].y == y && game.monsterPlaces[i].monster.isAlive())
                    {
                        monsterCount++;
                    }
                }

                if (monsterCount == 1) stream << "M░";
                else if (monsterCount > 1) stream << "MM";
                else stream << "░░";
            }                                                    
        }

        for(int i = game.map.getWidth(y); i < game.map.getMaxWidth(); i++) stream << "██";
        stream << "║";
        stream << std::endl;
    } 
    stream << "╚";
    for(int i = 0; i < game.map.getMaxWidth(); i++) stream << "══";
    stream << "╝" << std::endl;   
}