#include "../Json.h"

#include <gtest/gtest.h>

TEST(JsonTest, ParseString)
{
    std::map<std::string, std::string> data = Json::ParseString("{   \"hp\" : 200  ,   \"name\" : \"Kakarott\"  ,   \"attackcooldown\": 1.0  ,   \"dmg\" : 90   }");
    ASSERT_EQ(data["name"], "Kakarott");
    ASSERT_EQ(data["hp"], "200");
    ASSERT_EQ(data["dmg"], "90");
    ASSERT_EQ(data["attackcooldown"], "1.0");
}
TEST(JsonTest, doesnotexistFile)
{
    ASSERT_THROW(Json::ParseFile("../unit/doesnotexist.json"), std::runtime_error);
}
TEST(JsonTest, existFile)
{
    ASSERT_NO_THROW(Json::ParseFile("../unit/unit1.json"));
}
TEST(JsonTest, ValidatorMissingChars)
{
    ASSERT_THROW(Json::ParseString("    \"name\" : \"Kakarott\",    \"hp\" : 200,    \"dmg\" : 90, \"attackcooldown\": 1.0 }"), std::runtime_error);
    ASSERT_THROW(Json::ParseString("{    name\" : \"Kakarott\",    \"hp\" : 200,    \"dmg\" : 90, \"attackcooldown\": 1.0  }"), std::runtime_error);
    ASSERT_THROW(Json::ParseString("{    \"name : \"Kakarott\",    \"hp\" : 200,    \"dmg\" : 90, \"attackcooldown\": 1.0  }"), std::runtime_error);
    ASSERT_THROW(Json::ParseString("{    \"name\"  \"Kakarott\",    \"hp\" : 200,    \"dmg\" : 90, \"attackcooldown\": 1.0  }"), std::runtime_error);
    ASSERT_THROW(Json::ParseString("{    \"name\" : Kakarott\",    \"hp\" : 200,    \"dmg\" : 90, \"attackcooldown\": 1.0  }"), std::runtime_error);
    ASSERT_THROW(Json::ParseString("{    \"name\" : \"Kakarott,    \"hp\" : 200,    \"dmg\" : 90, \"attackcooldown\": 1.0  }"), std::runtime_error);
    ASSERT_THROW(Json::ParseString("{    \"name\" : \"Kakarott\"    \"hp\" : 200,    \"dmg\" : 90, \"attackcooldown\": 1.0  }"), std::runtime_error);
    ASSERT_THROW(Json::ParseString("{    \"name\" : \"Kakarott\",    hp\" : 200,    \"dmg\" : 90, \"attackcooldown\": 1.0  }"), std::runtime_error);
    ASSERT_THROW(Json::ParseString("{    \"name\" : \"Kakarott\",    \"hp : 200,    \"dmg\" : 90, \"attackcooldown\": 1.0  }"), std::runtime_error);
    ASSERT_THROW(Json::ParseString("{    \"name\" : \"Kakarott\",    \"hp\"  200,    \"dmg\" : 90, \"attackcooldown\": 1.0  }"), std::runtime_error);
    ASSERT_THROW(Json::ParseString("{    \"name\" : \"Kakarott\",    \"hp\" : 200    \"dmg\" : 90, \"attackcooldown\": 1.0  "), std::runtime_error);
    ASSERT_THROW(Json::ParseString("{    \"name\" : \"Kakarott\",    \"hp\" : 200    dmg\" : 90, \"attackcooldown\": 1.0  }"), std::runtime_error);
}
TEST(JsonTest, ValidatorPlusSpace)
{
    ASSERT_NO_THROW(Json::ParseString("{\"name\":\"Kakarott\",\"hp\": 200,\"dmg\":90, \"attackcooldown\": 1.0 }"));
    ASSERT_NO_THROW(Json::ParseString("{   \"name\"   :   \"Kakarott\"   ,    \"hp\"   : 200  ,    \"dmg\"   :    90  , \"attackcooldown\": 1.0   }"));
    ASSERT_NO_THROW(Json::ParseString("{  \"hp\"   : 200,   \"name\"   :   \"Kakarott\",        \"dmg\"   :    90  , \"attackcooldown\": 1.0   }"));
    ASSERT_NO_THROW(Json::ParseString("{  \"hp\"   : 200,       \"dmg\"   :    90,  \"name\"   :   \"Kakarott\" , \"attackcooldown\": 1.0  }"));
    ASSERT_NO_THROW(Json::ParseString("{    \"name\" : \"Kakarott\",    \"hp\" : 200,    \"dmg\" : 90, \"attackcooldown\": 1.0 }"));
}
TEST(JsonTest, ValidatorMixedKeys)
{
    ASSERT_NO_THROW(Json::ParseString("{  \"hp\"   : 200,   \"name\"   :   \"Kakarott\",        \"dmg\"   :    90  , \"attackcooldown\": 1.0   }"));
    ASSERT_NO_THROW(Json::ParseString("{  \"hp\"   : 200,       \"dmg\"   :    90,  \"name\"   :   \"Kakarott\" , \"attackcooldown\": 1.0  }"));
}
