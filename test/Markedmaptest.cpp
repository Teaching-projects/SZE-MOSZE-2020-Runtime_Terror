#include "../MarkedMap.h"
#include "vector"

#include <gtest/gtest.h>

TEST(Markedmaptester, GoodBadfile)
{
    std::string file = "./doesnotexist.txt";
    ASSERT_THROW(MarkedMap Mmap(file), Map::WrongIndexException);
    file = "../markedmap.txt";
    ASSERT_NO_THROW(MarkedMap Mmap(file));
}
TEST(Markedmaptester, GetHeroPosition)
{
    std::string file = "../markedmap.txt";
    MarkedMap Mmap(file);
    coordinate hero = Mmap.getHeroPosition();
    coordinate coord(2, 1);
    ASSERT_EQ(hero.x, coord.x);
    ASSERT_EQ(hero.y, coord.y);
}
TEST(Markedmaptester, GetMontersPosition)
{
    std::string file = "../markedmap.txt";
    MarkedMap Mmap(file);
    std::vector<coordinate> monsters = Mmap.getMonsterPositions('1');
    coordinate c0(2, 3);
    ASSERT_EQ(monsters[0].x, c0.x);
    ASSERT_EQ(monsters[0].y, c0.y);
    coordinate c1(3, 4);
    ASSERT_EQ(monsters[1].x, c1.x);
    ASSERT_EQ(monsters[1].y, c1.y);
    coordinate c2(6, 5);
    ASSERT_EQ(monsters[2].x, c2.x);
    ASSERT_EQ(monsters[2].y, c2.y);
}