#include <witchcraft/card/mana_cost.hxx>
#include <witchcraft/player/mana_pool.hxx>

#include <catch.hpp>

TEST_CASE("test mana pool", "[player]")
{
  SECTION("test empty creation")
  {
    player::mana_pool pool;
    REQUIRE(pool.converted() == 0);
    REQUIRE(pool.empty());
  }

  SECTION("test simple add and remove")
  {
    player::mana_pool pool;

    pool.add(card::mana::black, 7);
    REQUIRE(pool.converted() == 7);
    REQUIRE_FALSE(pool.empty());

    pool.remove(card::mana::black, 4);
    REQUIRE(pool.converted() == 3);
    REQUIRE(pool.mana_amount(card::mana::black) == 3);
  }

  SECTION("test remove more than exists")
  {
    player::mana_pool pool;

    pool.remove(card::mana::white, 2);
    REQUIRE(pool.converted() == 0);
    REQUIRE(pool.empty());

    pool.add(card::mana::red, 3);
    pool.remove(card::mana::red, 4);
    REQUIRE(pool.converted() == 0);
    REQUIRE(pool.mana_amount(card::mana::red) == 0);
  }

  SECTION("test payable mana costs")
  {
    player::mana_pool pool;
    pool.add(card::mana::red, 2);
    pool.add(card::mana::green, 3);

    REQUIRE(pool.is_payable(card::mana_cost::from_string("GGR")));
    REQUIRE_FALSE(pool.is_payable(card::mana_cost::from_string("BU")));
  }
}