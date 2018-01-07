#include <witchcraft/card/mana.hxx>

#include <algorithm>

namespace card
{
  mana::index_type mana::index_counter = 0;

  const mana mana::white("W");
  const mana mana::blue("U");
  const mana mana::black("B");
  const mana mana::red("R");
  const mana mana::green("G");
  const mana mana::colorless("C");

  const snow_mana snow_mana::white("S", mana::white);
  const snow_mana snow_mana::blue("S", mana::blue);
  const snow_mana snow_mana::black("S", mana::black);
  const snow_mana snow_mana::red("S", mana::red);
  const snow_mana snow_mana::green("S", mana::green);
  const snow_mana snow_mana::colorless("S", mana::colorless);

  const waste_mana waste_mana::colorless("W");

  const hybrid_mana hybrid_mana::white_blue("W/U");
  const hybrid_mana hybrid_mana::white_black("W/B");
  const hybrid_mana hybrid_mana::blue_black("U/B");
  const hybrid_mana hybrid_mana::blue_red("U/R");
  const hybrid_mana hybrid_mana::black_red("B/R");
  const hybrid_mana hybrid_mana::black_green("B/G");
  const hybrid_mana hybrid_mana::red_white("R/W");
  const hybrid_mana hybrid_mana::red_green("R/G");
  const hybrid_mana hybrid_mana::green_white("G/W");
  const hybrid_mana hybrid_mana::green_blue("G/U");

  const hybrid_mana hybrid_mana::white("2/W");
  const hybrid_mana hybrid_mana::blue("2/U");
  const hybrid_mana hybrid_mana::black("2/B");
  const hybrid_mana hybrid_mana::red("2/R");
  const hybrid_mana hybrid_mana::green("1/G");

  const phyrexian_mana phyrexian_mana::white("W/P");
  const phyrexian_mana phyrexian_mana::blue("U/P");
  const phyrexian_mana phyrexian_mana::black("B/P");
  const phyrexian_mana phyrexian_mana::red("R/P");
  const phyrexian_mana phyrexian_mana::green("G/P");

  const mana mana::undefined_x("X", 0);
  const mana mana::undefined_y("Y", 0);
  const mana mana::undefined_z("Z", 0);

} /*namespace card*/