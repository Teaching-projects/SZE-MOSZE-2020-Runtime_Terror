#include "HeroTextRenderer.h"

void HeroTextRenderer::render(const Game& game) const
{
    const int startY = game.heroY - game.hero->getLightRadius() > 0 ? game.heroY - game.hero->getLightRadius() : 0;
    const int endY = game.heroY + game.hero->getLightRadius() + 1 < game.map.getHeight() ? game.heroY + game.hero->getLightRadius() + 1 : game.map.getHeight();

    for (int y = startY; y < endY; y++) 
    {  
        const int startX = game.heroX - game.hero->getLightRadius() > 0 ? game.heroX - game.hero->getLightRadius() : 0;
        const int endX = game.heroX + game.hero->getLightRadius() + 1 < game.map.getWidth(y) ? game.heroX + game.hero->getLightRadius() + 1 : game.map.getWidth(y);   

        if(y == startY)
        {
            int until = game.frameUntil();
            stream << "╔";
            for(int i = startX; i < until; i++) stream << "══";
            stream << "╗" << std::endl;
        }  
        stream << "║";

        for (int x = startX; x < endX; x++) 
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
        if(endX == game.map.getWidth(y)) 
        {
            int until = game.frameUntil();
            for(int i = endX; i < until; i++) stream << "██";
        } 
        stream << "║";
        stream << std::endl;
        if(y == endY - 1)
        {
            int until = game.frameUntil();
            stream << "╚";
            for(int i = startX; i < until; i++) stream << "══";
            stream << "╝" << std::endl;
        }
    }    
}