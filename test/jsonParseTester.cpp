#include "../Json.cpp"
#include <gtest/gtest.h>

TEST(JsonTest, Filetest)
{
    ASSERT_THROW(Json::ParseFile("doesntexits.json"), std::runtime_error);
    ASSERT_NO_THROW(Json::ParseFile("../unit/unit1.json"));
}
TEST(JsonTest, ParseString)
{
    std::map<std::string, std::string> data = Json::ParseString("{    \"name\" : \"Kakarott\",    \"hp\" : 30000,    \"dmg\" : 9000}");
    ASSERT_EQ(data["name"], "Kakarott");
    ASSERT_EQ(data["hp"], "30000");
    ASSERT_EQ(data["dmg"], "9000");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
