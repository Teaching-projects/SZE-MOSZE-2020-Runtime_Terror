#include "../Game.h"

#include <gtest/gtest.h>

TEST(Gametester, GoodBadfile)
{
    ASSERT_NO_THROW(Game g = Game("../map.txt"));
    ASSERT_THROW(Game g = Game("../doesnotexist.txt"), std::runtime_error);
}
TEST(Gametester, gameTestNoThrow)
{
    Game game;
    std::string file = "../map.txt";
    Map map(file);
    Hero A = Hero::parse("../unit/Dark_Wanderer.json");
    Monster B = Monster::parse("../unit/Fallen.json");
    ASSERT_NO_THROW(game.setMap(map));
    ASSERT_NO_THROW(game.putHero(A, 1, 2));
    ASSERT_NO_THROW(game.putMonster(B, 1, 2));
    ASSERT_NO_THROW(game.run());
}
TEST(Gametester, missingMapException)
{
    Game game;
    Hero A = Hero::parse("../unit/Dark_Wanderer.json");
    ASSERT_THROW(game.putHero(A, 1, 2), Map::WrongIndexException);
}
TEST(Gametester, putHeroException)
{
    Game game;
    std::string file = "../map.txt";
    Map map(file);
    game.setMap(map);
    Hero A = Hero::parse("../unit/Dark_Wanderer.json");
    game.putHero(A, 1, 2);
    ASSERT_THROW(game.putHero(A, 1, 2), Game::AlreadyHasHeroException);
}
TEST(Gametester, putHeroIntoWallException)
{
    Game game;
    std::string file = "../map.txt";
    Map map(file);
    game.setMap(map);
    Hero A = Hero::parse("../unit/Dark_Wanderer.json");
    ASSERT_THROW(game.putHero(A, 0, 0), Game::OccupiedException);
}