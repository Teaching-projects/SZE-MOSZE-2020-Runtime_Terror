#include "../Unit.h"

#include <gtest/gtest.h>

TEST(UnitTest, ParseUnit)
{
    Unit expected("Kakarott", 200, 90, 1.0);
    Unit result = Unit::parseUnit("../unit/unit1.json");
    EXPECT_EQ(expected.GetName(), result.GetName());
    EXPECT_EQ(expected.GetDamage(), result.GetDamage());
    EXPECT_EQ(expected.GetHealth(), result.GetHealth());
    EXPECT_EQ(expected.GetCurrentCooldown(), result.GetCurrentCooldown());
}
TEST(UnitTest, Minusheal)
{
    Unit alive("Kakarott", 200, 90, 1.0);
    EXPECT_EQ(alive.IsDead(), false);
    Unit dead("Kakarott", -1, 90, 1.0);
    EXPECT_EQ(dead.IsDead(), true);
}
