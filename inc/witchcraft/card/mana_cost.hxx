#ifndef WITCHCRAFT_CARD_MANA_COST_HXX
#define WITCHCRAFT_CARD_MANA_COST_HXX

#include "mana.hxx"

#include <map>
#include <string>
#include <vector>

namespace card
{
  class mana_pool_interface
  {
  public:
    using amount_type = typename mana::amount_type;

    virtual amount_type converted() const = 0;
    virtual amount_type mana_amount(const mana& type) const = 0;
  };

  class mana_cost final : public mana_pool_interface
  {
  public:
    using amount_type = typename mana_pool_interface::amount_type;
    using container_type = typename std::map<mana, amount_type>;
    using const_iterator = typename container_type::const_iterator;

    static mana_cost from_string(const std::string& spec);

    mana_cost() = default;
    amount_type converted() const noexcept override;
    amount_type mana_amount(const mana& type) const noexcept override;

    inline const_iterator begin() const { return m_costs.begin(); }
    inline const_iterator end() const { return m_costs.end(); }

  private:
    container_type m_costs;
  };
} /*namespace card*/

#endif /*WITCHCRAFT_CARD_MANA_COST_HXX*/