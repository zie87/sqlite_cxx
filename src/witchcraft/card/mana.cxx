#include <witchcraft/card/mana.hxx>

#include <algorithm>

namespace card
{
  mana::index_type mana::index_counter = 0;

  const mana mana::white("W", atoms::white);
  const mana mana::blue("U", atoms::blue);
  const mana mana::black("B", atoms::black);
  const mana mana::red("R", atoms::red);
  const mana mana::green("G", atoms::green);
  const mana mana::colorless("C", atoms::colorless | atoms::generic);

  const mana mana::undefined_x("X", atoms::undefined_amount | atoms::colorless);
  const mana mana::undefined_y("Y", atoms::undefined_amount | atoms::colorless);
  const mana mana::undefined_z("Z", atoms::undefined_amount | atoms::colorless);

  const snow_mana snow_mana::white("S", atoms::white | atoms::snow);
  const snow_mana snow_mana::blue("S", atoms::blue | atoms::snow);
  const snow_mana snow_mana::black("S", atoms::black | atoms::snow);
  const snow_mana snow_mana::red("S", atoms::red | atoms::snow);
  const snow_mana snow_mana::green("S", atoms::green | atoms::snow);
  const snow_mana snow_mana::colorless("S", atoms::colorless | atoms::snow);

  const waste_mana waste_mana::colorless("C");

  const hybrid_mana hybrid_mana::white_blue("W/U", atoms::white | atoms::blue);
  const hybrid_mana hybrid_mana::white_black("W/B", atoms::white | atoms::black);
  const hybrid_mana hybrid_mana::blue_black("U/B", atoms::blue | atoms::black);
  const hybrid_mana hybrid_mana::blue_red("U/R", atoms::blue | atoms::red);
  const hybrid_mana hybrid_mana::black_red("B/R", atoms::black | atoms::red);
  const hybrid_mana hybrid_mana::black_green("B/G", atoms::black | atoms::green);
  const hybrid_mana hybrid_mana::red_white("R/W", atoms::red | atoms::white);
  const hybrid_mana hybrid_mana::red_green("R/G", atoms::red | atoms::green);
  const hybrid_mana hybrid_mana::green_white("G/W", atoms::green | atoms::white);
  const hybrid_mana hybrid_mana::green_blue("G/U", atoms::green | atoms::blue);

  const hybrid_mana hybrid_mana::white("2/W", atoms::white | atoms::or_2_colorless);
  const hybrid_mana hybrid_mana::blue("2/U", atoms::blue | atoms::or_2_colorless);
  const hybrid_mana hybrid_mana::black("2/B", atoms::black | atoms::or_2_colorless);
  const hybrid_mana hybrid_mana::red("2/R", atoms::red | atoms::or_2_colorless);
  const hybrid_mana hybrid_mana::green("1/G", atoms::green | atoms::or_2_colorless);

  const phyrexian_mana phyrexian_mana::white("W/P", atoms::white | atoms::or_2_life);
  const phyrexian_mana phyrexian_mana::blue("U/P", atoms::blue | atoms::or_2_life);
  const phyrexian_mana phyrexian_mana::black("B/P", atoms::black | atoms::or_2_life);
  const phyrexian_mana phyrexian_mana::red("R/P", atoms::red | atoms::or_2_life);
  const phyrexian_mana phyrexian_mana::green("G/P", atoms::green | atoms::or_2_life);

} /*namespace card*/