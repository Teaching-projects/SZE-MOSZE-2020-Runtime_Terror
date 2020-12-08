#include "../Map.h"

#include <gtest/gtest.h>

TEST(Maptest, GoodBadfile)
{
    std::string file = "./doesnotexist.txt";
    ASSERT_THROW(Map map(file), Map::WrongIndexException);
    file = "../map.txt";
    ASSERT_NO_THROW(Map map(file));
}
TEST(Maptest, GetWallorFree)
{
    std::string file = "../map.txt";
    Map map(file);
    ASSERT_EQ(map.get(0, 0), 0);
    ASSERT_EQ(map.get(1, 1), 1);
}
TEST(Maptest, GetHeight)
{
    std::string file = "../map.txt";
    Map map(file);
    ASSERT_EQ(map.getHeight(), 7);
}
TEST(Maptest, GetWidth)
{
    std::string file = "../map.txt";
    Map map(file);
    int width[7] = {14, 14, 13, 12, 11, 10, 9};
    for (int i = 0; i < map.getHeight(); i++)
    {
        ASSERT_EQ(map.getWidth(i), width[i]);
    }
}
TEST(Maptest, GetMaxWidth)
{
    std::string file = "../map.txt";
    Map map(file);
    ASSERT_EQ(map.getMaxWidth(), 14);
}