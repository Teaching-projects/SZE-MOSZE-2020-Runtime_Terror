#include "../Player.h"
#include "../Game.h"

#include <gtest/gtest.h>

TEST(PlayerTest, GoodValues)
{
    Player player = Player::parsePlayer("../unit/unit1.json");
    EXPECT_EQ(player.GetName(), "Kakarott");
    EXPECT_EQ(player.GetHealth(), 200);
    EXPECT_EQ(player.GetDamage(), 90);
    EXPECT_EQ(player.GetCurrentCooldown(), 1.0);
    EXPECT_EQ(player.GetLevel(), 1);
    EXPECT_EQ(player.GetXp(), 0);
}

TEST(PlayerTest, Player)
{
    Player expected = Player("Kakarott", 200, 90, 1.0);
    EXPECT_EQ(expected.GetLevel(), 1);
    EXPECT_EQ(expected.GetXp(), 0);
}
TEST(PlayerTest, PlayerAttack)
{
    Player A = Player::parsePlayer("../unit/unit1.json");
    Player B = Player::parsePlayer("../unit/unit2.json");
    int heal = B.GetHealth() - A.GetDamage();
    A.Attack(B);
    EXPECT_EQ(B.GetHealth(), heal);
}

TEST(PlayerTest, PlayerLevelupAttack)
{
    Player A = Player("Kakarott", 1000, 150, 1.0);
    Player B = Player("Lajcsi", 1000, 90, 1.0);
    int heal = B.GetHealth() - A.GetDamage();
    int A_damage_before_levelup = A.GetDamage();
    int A_heal_before_levelup = A.GetHealth();
    A.Attack(B);

    EXPECT_EQ(A.GetLevel(), 2);
    EXPECT_EQ(A.GetXp(), 150);
    EXPECT_EQ(A.GetDamage(), A_damage_before_levelup * 1.1);
    EXPECT_EQ(A.GetHealth(), A_heal_before_levelup * 1.1);
}
