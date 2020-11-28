#include "../Monster.h"
#include "../Hero.h"

#include <gtest/gtest.h>

TEST(PlayerTest, GoodValues)
{
    Hero player = Hero::parse("../unit/Dark_Wanderer.json");
    EXPECT_EQ(player.getName(), "Prince Aidan of Khanduras");
    EXPECT_EQ(player.getHealthPoints(), 30);
    EXPECT_EQ(player.getPhysicalDamage(), 3);
    EXPECT_EQ(player.getMagicalDamage(), 2);
    EXPECT_FLOAT_EQ(player.getAttackCoolDown(), 1.1);
    EXPECT_EQ(player.getDefense(), 4);
    EXPECT_EQ(player.getLevel(), 1);
    EXPECT_EQ(player.getXp(), 0);
}

TEST(PlayerTest, Player)
{
    Hero expected = Hero("Kakarott", 200, 90, 1, 1, 1, 1, 1, 1, 1, 1, 1);
    EXPECT_EQ(expected.getLevel(), 1);
    EXPECT_EQ(expected.getXp(), 0);
}
TEST(PlayerTest, PlayerAttack)
{

    Hero A = Hero::parse("../unit/Dark_Wanderer.json");
    Monster B = Monster::parse("../unit/Fallen.json");

    int physicalDamage = A.getPhysicalDamage() - B.getDefense();
    if(physicalDamage < 0) physicalDamage = 0;

    int health = B.getHealthPoints() - physicalDamage - A.getMagicalDamage();

    A.Attack(B);
    EXPECT_EQ(B.getHealthPoints(), health);
}

TEST(PlayerTest, PlayerXPAfterAttack)
{
    Hero A = Hero::parse("../unit/Dark_Wanderer.json");
    Monster B = Monster::parse("../unit/Zombie.json");
    for (size_t i = 0; i < 6; i++)
    {
        A.Attack(B);
    }
    EXPECT_EQ(A.getXp(), 12);
}
