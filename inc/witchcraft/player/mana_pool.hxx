#ifndef WITCHCRAFT_PLAYER_MANA_POOL_HXX
#define WITCHCRAFT_PLAYER_MANA_POOL_HXX

#include <witchcraft/card/mana.hxx>
#include <witchcraft/card/mana_cost.hxx>

#include <map>

namespace player
{
  class mana_pool final : public card::mana_pool_interface
  {
  public:
    using amount_type = typename card::mana_pool_interface::amount_type;

    mana_pool();

    void add(const card::mana& mana, amount_type amount);
    void remove(const card::mana& mana, amount_type amount);

    amount_type mana_amount(const card::mana& mana) const noexcept override;
    amount_type converted() const noexcept override;
    inline bool empty() const noexcept { return converted() == 0; }

    bool is_payable(const card::mana_cost& cost) const noexcept;

  private:
    inline bool is_valid_mana(const card::mana& mana) const noexcept { return (mana.is_basic() || mana.is_snow()); }
    std::map<card::mana, amount_type> m_mana;
  };
} /*namespace player*/

#endif /*WITCHCRAFT_PLAYER_MANA_POOL_HXX*/