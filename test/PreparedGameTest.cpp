#include "../PreparedGame.h"

#include <gtest/gtest.h>

TEST(PreparedGametester, GoodBadfile)
{
    std::string file = "./doesnotexist.txt";
    ASSERT_THROW(PreparedGame PR(file), std::runtime_error);
    file = "../preparedgame.json";
    ASSERT_NO_THROW(PreparedGame game = PreparedGame("../preparedgame.json"));
}
