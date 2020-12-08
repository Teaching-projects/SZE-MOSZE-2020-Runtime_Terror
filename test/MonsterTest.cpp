#include "../Monster.h"
#include "../Hero.h"

#include <gtest/gtest.h>

TEST(MonsterTest, ParseUnit)
{
    Monster expected("Fallen", 4, 1, 1, 1.6, 2, "texture/fallen.png");
    Monster result = Monster::parse("../unit/Fallen.json");
    EXPECT_EQ(expected.getName(), result.getName());
    EXPECT_EQ(expected.getHealthPoints(), result.getHealthPoints());
    EXPECT_EQ(expected.getPhysicalDamage(), result.getPhysicalDamage());
    EXPECT_EQ(expected.getMagicalDamage(), result.getMagicalDamage());
    EXPECT_EQ(expected.getAttackCoolDown(), result.getAttackCoolDown());
    EXPECT_EQ(expected.getDefense(), result.getDefense());
    EXPECT_EQ(expected.getTexture(), result.getTexture());
}
TEST(MonsterTest, Minusheal)
{
    Monster alive("Blood Raven", 113, 5, 3, 1.2, 3, "texture/blood_raven.png");
    EXPECT_EQ(alive.isAlive(), true);
    Monster dead("Blood Raven", -1, 5, 3, 1.2, 3, "texture/blood_raven.png");
    EXPECT_EQ(dead.isAlive(), false);
}
