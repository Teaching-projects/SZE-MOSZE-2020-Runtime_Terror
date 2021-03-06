#include <string>

#include "PreparedGame.h"
#include "MarkedMap.h"
#include "JSON.h"
#include "Renderer.h"

PreparedGame::PreparedGame(std::string mapjson) {
    JSON json = JSON::parseFromFile(mapjson);

    std::string mapfilename = json.get<std::string>("map");
    MarkedMap map(mapfilename);
    this->setMap(map);

    std::string herofile = json.get<std::string>("hero");
    Hero hero = Hero::parse(herofile);
    coordinate heroPosition = map.getHeroPosition();
    this->putHero(hero, heroPosition.x, heroPosition.y);

    int maxMonsterNumber = 1;
    while(true)
    {
        std::string search = "monster" + std::to_string(maxMonsterNumber);
        if(json.count(search))
            maxMonsterNumber++;
        else break;
    }
    maxMonsterNumber -= 1;

    std::string actualMonsterFile;

    for (int i = 1; i <= maxMonsterNumber; i++) {
        actualMonsterFile = json.get<std::string>("monster" + std::to_string(i));
        Monster monster = Monster::parse(actualMonsterFile);
        std::vector<coordinate> monsterPositions = map.getMonsterPositions((char)(i + '0'));

        for (auto& pos : monsterPositions) {
            this->putMonster(monster, pos.x, pos.y);            
        }
    }   

    freeTexture = json.get<std::string>("free_texture");
    wallTexture = json.get<std::string>("wall_texture");
}

void PreparedGame::run()
{
    Game::run();
}

void PreparedGame::registerRenderer(Renderer* renderer) 
{
    Game::registerRenderer(renderer);
}