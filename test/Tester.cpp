#include "../Json.h"
#include "../Unit.h"
#include "../Player.h"

#include <gtest/gtest.h>

TEST(UnitTest, ParseUnit)
{
    ASSERT_THROW(Unit::parseUnit("doesntexits.json"), std::runtime_error);
    ASSERT_NO_THROW(Unit::parseUnit("../unit/unit1.json"));
    Unit expected("Kakarott", 200, 90, 1.0);
    Unit result = Unit::parseUnit("../unit/unit1.json");
    EXPECT_EQ(expected.GetName(), result.GetName());
    EXPECT_EQ(expected.GetDamage(), result.GetDamage());
    EXPECT_EQ(expected.GetHealth(), result.GetHealth());
    EXPECT_EQ(expected.GetCurrentCooldown(), result.GetCurrentCooldown());
}
TEST(UnitTest, ParseUnitMissingValue)
{
    ASSERT_THROW(Unit::parseUnit("./missingUnit.json"), std::runtime_error);
}
TEST(UnitTest, ParseUnitMinusValue)
{
    ASSERT_THROW(Unit::parseUnit("./minusValue.json"), std::runtime_error);
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

TEST(JsonTest, Filetest)
{
    ASSERT_THROW(Json::ParseFile("doesntexits.json"), std::runtime_error);
    ASSERT_NO_THROW(Json::ParseFile("../unit/unit1.json"));
}
TEST(JsonTest, ParseString)
{
    std::map<std::string, std::string> data = Json::ParseString("{   \"hp\" : 200  ,   \"name\" : \"Kakarott\"  ,   \"attackcooldown\": 1.0  ,   \"dmg\" : 90   }");
    ASSERT_EQ(data["name"], "Kakarott");
    ASSERT_EQ(data["hp"], "200");
    ASSERT_EQ(data["dmg"], "90");
    ASSERT_EQ(data["attackcooldown"], "1.0");
}
TEST(JsonTest, MinisValue)
{
    ASSERT_THROW(Json::Validator("\"name\" : \"Kakarott\",  \"hp\" : -200,  \"dmg\" : 90, \"attackcooldown\": 1.0 }"), std::runtime_error);
    ASSERT_THROW(Json::Validator("\"name\" : \"Kakarott\",  \"hp\" : 200,  \"dmg\" : -90, \"attackcooldown\": 1.0 }"), std::runtime_error);
    ASSERT_THROW(Json::Validator("\"name\" : \"Kakarott\",  \"hp\" : 200,  \"dmg\" : 90, \"attackcooldown\": -1.0 }"), std::runtime_error);
}
TEST(JsonTest, ValidatorMissingChars)
{
    ASSERT_THROW(Json::Validator("    \"name\" : \"Kakarott\",    \"hp\" : 200,    \"dmg\" : 90, \"attackcooldown\": 1.0 }"), std::runtime_error);
    ASSERT_THROW(Json::Validator("{    name\" : \"Kakarott\",    \"hp\" : 200,    \"dmg\" : 90, \"attackcooldown\": 1.0  }"), std::runtime_error);
    ASSERT_THROW(Json::Validator("{    \"name : \"Kakarott\",    \"hp\" : 200,    \"dmg\" : 90, \"attackcooldown\": 1.0  }"), std::runtime_error);
    ASSERT_THROW(Json::Validator("{    \"name\"  \"Kakarott\",    \"hp\" : 200,    \"dmg\" : 90, \"attackcooldown\": 1.0  }"), std::runtime_error);
    ASSERT_THROW(Json::Validator("{    \"name\" : Kakarott\",    \"hp\" : 200,    \"dmg\" : 90, \"attackcooldown\": 1.0  }"), std::runtime_error);
    ASSERT_THROW(Json::Validator("{    \"name\" : \"Kakarott,    \"hp\" : 200,    \"dmg\" : 90, \"attackcooldown\": 1.0  }"), std::runtime_error);
    ASSERT_THROW(Json::Validator("{    \"name\" : \"Kakarott\"    \"hp\" : 200,    \"dmg\" : 90, \"attackcooldown\": 1.0  }"), std::runtime_error);
    ASSERT_THROW(Json::Validator("{    \"name\" : \"Kakarott\",    hp\" : 200,    \"dmg\" : 90, \"attackcooldown\": 1.0  }"), std::runtime_error);
    ASSERT_THROW(Json::Validator("{    \"name\" : \"Kakarott\",    \"hp : 200,    \"dmg\" : 90, \"attackcooldown\": 1.0  }"), std::runtime_error);
    ASSERT_THROW(Json::Validator("{    \"name\" : \"Kakarott\",    \"hp\"  200,    \"dmg\" : 90, \"attackcooldown\": 1.0  }"), std::runtime_error);
    ASSERT_THROW(Json::Validator("{    \"name\" : \"Kakarott\",    \"hp\" : 200    \"dmg\" : 90, \"attackcooldown\": 1.0  "), std::runtime_error);
    ASSERT_THROW(Json::Validator("{    \"name\" : \"Kakarott\",    \"hp\" : 200    dmg\" : 90, \"attackcooldown\": 1.0  }"), std::runtime_error);
}
TEST(JsonTest, ValidatorPlusSpace)
{
    ASSERT_NO_THROW(Json::Validator("{\"name\":\"Kakarott\",\"hp\": 200,\"dmg\":90, \"attackcooldown\": 1.0 }"));
    ASSERT_NO_THROW(Json::Validator("{   \"name\"   :   \"Kakarott\"   ,    \"hp\"   : 200  ,    \"dmg\"   :    90  , \"attackcooldown\": 1.0   }"));
    ASSERT_NO_THROW(Json::Validator("{  \"hp\"   : 200,   \"name\"   :   \"Kakarott\",        \"dmg\"   :    90  , \"attackcooldown\": 1.0   }"));
    ASSERT_NO_THROW(Json::Validator("{  \"hp\"   : 200,       \"dmg\"   :    90,  \"name\"   :   \"Kakarott\" , \"attackcooldown\": 1.0  }"));
    ASSERT_NO_THROW(Json::Validator("{    \"name\" : \"Kakarott\",    \"hp\" : 200,    \"dmg\" : 90, \"attackcooldown\": 1.0 }"));
}
TEST(JsonTest, ValidatorMixedKeys)
{
    ASSERT_NO_THROW(Json::Validator("{  \"hp\"   : 200,   \"name\"   :   \"Kakarott\",        \"dmg\"   :    90  , \"attackcooldown\": 1.0   }"));
    ASSERT_NO_THROW(Json::Validator("{  \"hp\"   : 200,       \"dmg\"   :    90,  \"name\"   :   \"Kakarott\" , \"attackcooldown\": 1.0  }"));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
