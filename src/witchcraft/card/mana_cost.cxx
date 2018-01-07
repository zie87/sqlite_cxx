#include <witchcraft/card/mana_cost.hxx>

#include <algorithm>
#include <regex>

#include <iostream>

namespace card
{
  mana_cost::amount_type count_and_remove_mana(const mana& m, std::string& str)
  {
    if (m.to_string().empty()) return 0;

    auto start_len = str.length();
    auto mana_str = m.to_string();

    std::regex pattern(mana_str);
    str = std::regex_replace(str, pattern, "");

    return ((start_len - str.length()) / mana_str.length());
  }

  mana_cost mana_cost::from_string(const std::string& input)
  {
    mana_cost cost;

    std::string spec(input);
    std::transform(spec.begin(), spec.end(), spec.begin(), ::toupper);

    cost.m_costs[hybrid_mana::white_black] = count_and_remove_mana(hybrid_mana::white_black, spec);
    cost.m_costs[hybrid_mana::white_blue] = count_and_remove_mana(hybrid_mana::white_blue, spec);
    cost.m_costs[hybrid_mana::blue_black] = count_and_remove_mana(hybrid_mana::blue_black, spec);
    cost.m_costs[hybrid_mana::blue_red] = count_and_remove_mana(hybrid_mana::blue_red, spec);
    cost.m_costs[hybrid_mana::black_green] = count_and_remove_mana(hybrid_mana::black_green, spec);
    cost.m_costs[hybrid_mana::black_red] = count_and_remove_mana(hybrid_mana::black_red, spec);
    cost.m_costs[hybrid_mana::red_green] = count_and_remove_mana(hybrid_mana::red_green, spec);
    cost.m_costs[hybrid_mana::red_white] = count_and_remove_mana(hybrid_mana::red_white, spec);
    cost.m_costs[hybrid_mana::green_blue] = count_and_remove_mana(hybrid_mana::green_blue, spec);
    cost.m_costs[hybrid_mana::green_white] = count_and_remove_mana(hybrid_mana::green_white, spec);

    cost.m_costs[hybrid_mana::white] = count_and_remove_mana(hybrid_mana::white, spec);
    cost.m_costs[hybrid_mana::blue] = count_and_remove_mana(hybrid_mana::blue, spec);
    cost.m_costs[hybrid_mana::black] = count_and_remove_mana(hybrid_mana::black, spec);
    cost.m_costs[hybrid_mana::red] = count_and_remove_mana(hybrid_mana::red, spec);
    cost.m_costs[hybrid_mana::green] = count_and_remove_mana(hybrid_mana::green, spec);

    cost.m_costs[phyrexian_mana::white] = count_and_remove_mana(phyrexian_mana::white, spec);
    cost.m_costs[phyrexian_mana::blue] = count_and_remove_mana(phyrexian_mana::blue, spec);
    cost.m_costs[phyrexian_mana::black] = count_and_remove_mana(phyrexian_mana::black, spec);
    cost.m_costs[phyrexian_mana::red] = count_and_remove_mana(phyrexian_mana::red, spec);
    cost.m_costs[phyrexian_mana::green] = count_and_remove_mana(phyrexian_mana::green, spec);

    cost.m_costs[snow_mana::colorless] = count_and_remove_mana(snow_mana::colorless, spec);
    cost.m_costs[waste_mana::colorless] = count_and_remove_mana(waste_mana::colorless, spec);

    cost.m_costs[mana::white] = count_and_remove_mana(mana::white, spec);
    cost.m_costs[mana::blue] = count_and_remove_mana(mana::blue, spec);
    cost.m_costs[mana::black] = count_and_remove_mana(mana::black, spec);
    cost.m_costs[mana::red] = count_and_remove_mana(mana::red, spec);
    cost.m_costs[mana::green] = count_and_remove_mana(mana::green, spec);

    cost.m_costs[mana::undefined_x] = count_and_remove_mana(mana::undefined_x, spec);
    cost.m_costs[mana::undefined_y] = count_and_remove_mana(mana::undefined_y, spec);
    cost.m_costs[mana::undefined_z] = count_and_remove_mana(mana::undefined_z, spec);

    if (!spec.empty())
    {
      cost.m_costs[mana::colorless] += std::stoi(spec);
    }

    return cost;
  }

  mana_cost::amount_type mana_cost::converted() const noexcept
  {
    amount_type cmd = 0;
    for (auto& cost : m_costs)
    {
      cmd += cost.second * cost.first.cmd_amount();
    }
    return cmd;
  }

  mana_cost::amount_type mana_cost::mana_amount(const mana& type) const noexcept
  {
    if (m_costs.find(type) != m_costs.end()) return m_costs.at(type);
    return 0;
  }

} /*namespace card*/