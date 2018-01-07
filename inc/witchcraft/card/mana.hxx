#ifndef WITCHCRAFT_CARD_MANA_HXX
#define WITCHCRAFT_CARD_MANA_HXX

#include <string>

namespace card
{
  class mana
  {
    using index_type = unsigned int;
    static index_type index_counter;

  public:
    using amount_type = unsigned int;

    enum class types
    {
      basic,
      snow,
      waste,
      hybrid,
      phyrexian
    };

    inline constexpr operator int() const noexcept { return m_index; }
    inline const std::string& to_string() const noexcept { return m_str; }

    inline types type() const noexcept { return m_type; }
    inline amount_type cmd_amount() const noexcept { return m_cmd_amount; }

    static const mana white;
    static const mana blue;
    static const mana black;
    static const mana red;
    static const mana green;
    static const mana colorless;

    static const mana undefined_x;
    static const mana undefined_y;
    static const mana undefined_z;

    virtual ~mana() = default;

  protected:
    explicit mana(const std::string& str, types t, amount_type amount) : m_index(index_counter++), m_str(str), m_type(t), m_cmd_amount(amount) {}

  private:
    explicit mana(const std::string& str, amount_type amount = 1) : mana(str, types::basic, amount) {}

    index_type m_index;
    std::string m_str;
    types m_type;
    amount_type m_cmd_amount;
  };

  class waste_mana final : public mana
  {
  public:
    static const waste_mana colorless;

    virtual ~waste_mana() = default;

  private:
    explicit waste_mana(const std::string& str) : mana(str, mana::types::waste, 1) {}
  };

  class snow_mana final : public mana
  {
  public:
    static const snow_mana white;
    static const snow_mana blue;
    static const snow_mana black;
    static const snow_mana red;
    static const snow_mana green;
    static const snow_mana colorless;

    virtual ~snow_mana() = default;

  private:
    explicit snow_mana(const std::string& str, const mana& alternate) : mana(str, mana::types::snow, 1), m_alternate(alternate) {}
    mana m_alternate;
  };

  class hybrid_mana final : public mana
  {
  public:
    static const hybrid_mana white_blue;
    static const hybrid_mana white_black;
    static const hybrid_mana blue_black;
    static const hybrid_mana blue_red;
    static const hybrid_mana black_red;
    static const hybrid_mana black_green;
    static const hybrid_mana red_white;
    static const hybrid_mana red_green;
    static const hybrid_mana green_white;
    static const hybrid_mana green_blue;

    static const hybrid_mana white;
    static const hybrid_mana blue;
    static const hybrid_mana black;
    static const hybrid_mana red;
    static const hybrid_mana green;

    virtual ~hybrid_mana() = default;

  private:
    explicit hybrid_mana(const std::string& str) : mana(str, mana::types::hybrid, 1) {}
  };

  class phyrexian_mana final : public mana
  {
  public:
    static const phyrexian_mana white;
    static const phyrexian_mana blue;
    static const phyrexian_mana black;
    static const phyrexian_mana red;
    static const phyrexian_mana green;

    virtual ~phyrexian_mana() = default;

  private:
    explicit phyrexian_mana(const std::string& str) : mana(str, mana::types::phyrexian, 1) {}
  };

} /*namespace card*/

#endif /*WITCHCRAFT_CARD_MANA_COST_HXX*/