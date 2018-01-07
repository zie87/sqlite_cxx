
#include <witchcraft/card/mana_cost.hxx>
#include <witchcraft/player/mana_pool.hxx>

#include <iostream>

namespace player
{

  mana_pool::mana_pool() : m_mana() {}

  void mana_pool::add(const card::mana& mana, player::mana_pool::amount_type amount)
  {
    if (mana.type() != card::mana::types::basic && mana.type() != card::mana::types::snow) return;

    m_mana[mana] += amount;
  }

  void mana_pool::remove(const card::mana& mana, player::mana_pool::amount_type amount)
  {
    if (mana.type() != card::mana::types::basic && mana.type() != card::mana::types::snow) return;

    if (mana_amount(mana) < amount)
      m_mana[mana] = 0;
    else
      m_mana[mana] -= amount;
  }

  mana_pool::amount_type mana_pool::mana_amount(const card::mana& mana) const noexcept
  {
    if (m_mana.find(mana) != m_mana.end()) return m_mana.at(mana);
    return 0;
  }

  mana_pool::amount_type mana_pool::converted() const noexcept
  {
    amount_type cmd = 0;
    for (auto mana : m_mana)
    {
      cmd += mana.second * mana.first.cmd_amount();
    }
    return cmd;
  }

  bool mana_pool::is_payable(const card::mana_cost& cost) const noexcept
  {
    bool payable = false;
    if (cost.converted() <= converted())
    {
      payable = true;

      for (auto& mana : cost)
      {
        payable &= mana.second <= mana_amount(mana.first);
      }
    }
    return payable;
  }
} /*namespace player*/
