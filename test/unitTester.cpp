#include "../Monster.h"
#include "../Hero.h"

#include <gtest/gtest.h>

TEST(UnitTest, ParseUnit)
{
    Monster expected("Blood Raven", 113, 8, 1.2);
    Monster result = Monster::parse("../unit/Blood_Raven.json");
    EXPECT_EQ(expected.getName(), result.getName());
    EXPECT_EQ(expected.getHealthPoints(), result.getHealthPoints());
    EXPECT_EQ(expected.getDamage(), result.getDamage());
    EXPECT_EQ(expected.getAttackCoolDown(), result.getAttackCoolDown());
}
TEST(UnitTest, Minusheal)
{
    Monster alive("Blood Raven", 113, 8, 1.2);
    EXPECT_EQ(alive.isAlive(), true);
    Monster dead("Blood Raven", -1, 8, 1.2);
    EXPECT_EQ(dead.isAlive(), false);
}
