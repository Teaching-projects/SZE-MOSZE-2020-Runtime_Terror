#include "../JSON.h"

#include <gtest/gtest.h>

TEST(JsonTest, exist)
{
    JSON parsed = JSON::parseFromString("{\"name\":\"Kakarott\",\"hp\": 200}");
    ASSERT_EQ(parsed.count("name"), 1);
    ASSERT_EQ(parsed.count("hp"), 1);
    ASSERT_EQ(parsed.count("dmg"), 0);
}

TEST(JSONTest, doesnotexistFile)
{
    ASSERT_THROW(JSON::parseFromFile("../unit/doesnotexist.json"), std::runtime_error);
}

TEST(JSONTest, existFile)
{
    ASSERT_NO_THROW(JSON::parseFromFile("../unit/Dark_Wanderer.json"));
}
TEST(JSONTest, ValidatorMissingChars)
{
    ASSERT_THROW(JSON::parseFromString("    \"name\" : \"Kakarott\",    \"hp\" : 200,    \"dmg\" : 90, \"attackcooldown\": 1.0 }"), std::runtime_error);
    ASSERT_THROW(JSON::parseFromString("{    name\" : \"Kakarott\",    \"hp\" : 200,    \"dmg\" : 90, \"attackcooldown\": 1.0  }"), std::runtime_error);
    ASSERT_THROW(JSON::parseFromString("{    \"name : \"Kakarott\",    \"hp\" : 200,    \"dmg\" : 90, \"attackcooldown\": 1.0  }"), std::runtime_error);
    ASSERT_THROW(JSON::parseFromString("{    \"name\"  \"Kakarott\",    \"hp\" : 200,    \"dmg\" : 90, \"attackcooldown\": 1.0  }"), std::runtime_error);
    ASSERT_THROW(JSON::parseFromString("{    \"name\" : Kakarott\",    \"hp\" : 200,    \"dmg\" : 90, \"attackcooldown\": 1.0  }"), std::runtime_error);
    ASSERT_THROW(JSON::parseFromString("{    \"name\" : \"Kakarott,    \"hp\" : 200,    \"dmg\" : 90, \"attackcooldown\": 1.0  }"), std::runtime_error);
    ASSERT_THROW(JSON::parseFromString("{    \"name\" : \"Kakarott\",    hp\" : 200,    \"dmg\" : 90, \"attackcooldown\": 1.0  }"), std::runtime_error);
    ASSERT_THROW(JSON::parseFromString("{    \"name\" : \"Kakarott\",    \"hp : 200,    \"dmg\" : 90, \"attackcooldown\": 1.0  }"), std::runtime_error);
    ASSERT_THROW(JSON::parseFromString("{    \"name\" : \"Kakarott\",    \"hp\"  200,    \"dmg\" : 90, \"attackcooldown\": 1.0  }"), std::runtime_error);
    ASSERT_THROW(JSON::parseFromString("{    \"name\" : \"Kakarott\",    \"hp\" : 200    \"dmg\" : 90, \"attackcooldown\": 1.0  "), std::runtime_error);
    ASSERT_THROW(JSON::parseFromString("{    \"name\" : \"Kakarott\",    \"hp\" : 200    dmg\" : 90, \"attackcooldown\": 1.0  }"), std::runtime_error);

    ASSERT_THROW(JSON::parseFromString("{    name : \"Kakarott\",    \"hp\" : 200,    \"dmg\" : 90, \"attackcooldown\": 1.0 }"), std::runtime_error);
    ASSERT_THROW(JSON::parseFromString("    \"name\" : \"Kakarott\",    \"hp\" : 200,    \"dmg\" : 90, \"attackcooldown\": 1.0 "), std::runtime_error);
    ASSERT_THROW(JSON::parseFromString("{    \"name\"  \"Kakarott\",    \"hp\" : 200,    \"dmg\"  90, \"attackcooldown\": 1.0 }"), std::runtime_error);
    ASSERT_THROW(JSON::parseFromString("{    \"name\"  \"Kakarott\"    \"hp\" : 200    \"dmg\" : 90, \"attackcooldown\": 1.0 }"), std::runtime_error);
    ASSERT_THROW(JSON::parseFromString("{    \"name\" : \"Kakarott    \"hp\" : 200,    \"dmg\" : 90, \"attackcooldown\": 1.0 }"), std::runtime_error);
    ASSERT_THROW(JSON::parseFromString("{    \"name\" : \"Kakarott\",    \"hp\" : 200,    \"dmg\" : 90, \"attackcooldown 1.0 }"), std::runtime_error);
    ASSERT_THROW(JSON::parseFromString("{    name\" : \"Kakarott\",    \"hp\"  200,    \"dmg\" : 90, \"attackcooldown 1.0 }"), std::runtime_error);
}

TEST(JSONTest, ValidatorPlusSpace)
{
    ASSERT_NO_THROW(JSON::parseFromString("{\"name\":\"Kakarott\",\"hp\": 200,\"dmg\":90, \"attackcooldown\": 1.0 }"));
    ASSERT_NO_THROW(JSON::parseFromString("{   \"name\"   :   \"Kakarott\"   ,    \"hp\"   : 200  ,    \"dmg\"   :    90  , \"attackcooldown\": 1.0   }"));
    ASSERT_NO_THROW(JSON::parseFromString("{  \"hp\"   : 200,   \"name\"   :   \"Kakarott\",        \"dmg\"   :    90  , \"attackcooldown\": 1.0   }"));
    ASSERT_NO_THROW(JSON::parseFromString("{  \"hp\"   : 200,       \"dmg\"   :    90,  \"name\"   :   \"Kakarott\" , \"attackcooldown\": 1.0  }"));
    ASSERT_NO_THROW(JSON::parseFromString("{    \"name\" : \"Kakarott\",    \"hp\" : 200,    \"dmg\" : 90, \"attackcooldown\": 1.0 }"));
}
TEST(JSONTest, ValidatorMixedKeys)
{
    ASSERT_NO_THROW(JSON::parseFromString("{  \"hp\"   : 200,   \"name\"   :   \"Kakarott\",        \"dmg\"   :    90  , \"attackcooldown\": 1.0   }"));
    ASSERT_NO_THROW(JSON::parseFromString("{  \"hp\"   : 200,       \"dmg\"   :    90,  \"name\"   :   \"Kakarott\" , \"attackcooldown\": 1.0  }"));
}
