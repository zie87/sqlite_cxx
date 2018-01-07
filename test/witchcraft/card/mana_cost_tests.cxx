#include <witchcraft/card/mana_cost.hxx>

#include <catch.hpp>

TEST_CASE("test mana cost creation from string", "[card]")
{
  SECTION("test simple mana cost parsing")
  {
    auto costs = card::mana_cost::from_string("RB");
    REQUIRE(costs.converted() == 2);

    costs = card::mana_cost::from_string("2WUB");
    REQUIRE(costs.converted() == 5);

    costs = card::mana_cost::from_string("rgbrgu");
    REQUIRE(costs.converted() == 6);
  }

  SECTION("test undefined mana cost parsing")
  {
    auto costs = card::mana_cost::from_string("XYZ");
    REQUIRE(costs.converted() == 0);

    costs = card::mana_cost::from_string("XR");
    REQUIRE(costs.converted() == 1);
  }

  SECTION("test hybrid mana cost parsing")
  {
    auto costs = card::mana_cost::from_string("W/U");
    REQUIRE(costs.converted() == 1);

    costs = card::mana_cost::from_string("2/B");
    REQUIRE(costs.converted() == 1);
  }

  SECTION("test phyrexian mana cost parsing")
  {
    auto costs = card::mana_cost::from_string("W/P");
    REQUIRE(costs.converted() == 1);

    costs = card::mana_cost::from_string("RR/P");
    REQUIRE(costs.converted() == 2);
  }

  SECTION("test snow mana cost parsing")
  {
    auto costs = card::mana_cost::from_string("SS");
    REQUIRE(costs.converted() == 2);
  }

  SECTION("test waste mana cost parsing")
  {
    auto costs = card::mana_cost::from_string("W");
    REQUIRE(costs.converted() == 1);
  }
}