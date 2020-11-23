#include "../Monster.h"
#include "../Hero.h"

#include <gtest/gtest.h>

TEST(PlayerTest, GoodValues)
{
    /* Hero player = Hero::parse("../unit/Dark_Wanderer.json");
    EXPECT_EQ(player.getName(), "Prince Aidan of Khanduras");
    EXPECT_EQ(player.getHealthPoints(), 30);
    EXPECT_EQ(player.getDamage(), 3);
    EXPECT_FLOAT_EQ(player.getAttackCoolDown(), 1.1);
    std::cout << player.getLevel() << " " << player.getXp() << " "
              << "\n";
    EXPECT_EQ(player.getLevel(), 1);
    EXPECT_EQ(player.getXp(), 0);
    */
}

TEST(PlayerTest, Player)
{
    Hero expected = Hero("Kakarott", 200, 90, 1.0, 1.0, 1, 1, 1, 1.0, 1.0);
    EXPECT_EQ(expected.getLevel(), 1);
    EXPECT_EQ(expected.getXp(), 0);
}
TEST(PlayerTest, PlayerAttack)
{

    Hero A = Hero::parse("../unit/Dark_Wanderer.json");
    /* Monster B = Monster::parse("../unit/Fallen.json");
    int heal = B.getHealthPoints() - A.getDamage();
    A.Attack(B);
    EXPECT_EQ(B.getHealthPoints(), heal); */
}
/* 
TEST(PlayerTest, PlayerXPAfterAttack)
{
    Hero A = Hero::parse("../unit/Dark_Wanderer.json");
    Monster B = Monster::parse("../unit/Blood_Raven.json");
    A.Attack(B);
    A.Attack(B);
    A.Attack(B);
    A.Attack(B);
    EXPECT_EQ(A.getXp(), 12);
} */
