#ifndef WITCHCRAFT_CARD_MANA_HXX
#define WITCHCRAFT_CARD_MANA_HXX

#include <bitset>
#include <string>

namespace card
{
  class mana
  {
    using index_type = unsigned int;
    static index_type index_counter;

  public:
    using amount_type = unsigned int;
    using flag_type = uint16_t;
    using bit_type = std::bitset<16>;

    struct atoms
    {
      static constexpr flag_type colorless = 0;
      static constexpr flag_type white = 1 << 0;
      static constexpr flag_type blue = 1 << 1;
      static constexpr flag_type black = 1 << 2;
      static constexpr flag_type red = 1 << 3;
      static constexpr flag_type green = 1 << 4;

      static constexpr flag_type generic = 1 << 6;

      static constexpr flag_type undefined_amount = 1 << 8;
      static constexpr flag_type or_2_colorless = 1 << 9;
      static constexpr flag_type or_2_life = 1 << 10;
      static constexpr flag_type snow = 1 << 11;
    };

    inline constexpr operator index_type() const noexcept { return m_index; }
    inline const std::string& to_string() const noexcept { return m_str; }

    inline bool is_kind_of_atom(flag_type atom) const noexcept { return (m_atom & atom) != 0; }

    inline bool is_basic() const noexcept { return m_atom <= atoms::generic; }
    inline bool is_waste() const noexcept { return is_kind_of_atom(atoms::colorless) && !is_kind_of_atom(atoms::generic); }
    inline bool is_snow() const noexcept { return is_kind_of_atom(atoms::snow); }
    inline bool is_hybrid() const noexcept { return is_kind_of_atom(atoms::or_2_life) || (bit_type(m_atom & color_mask).count() == 2); }
    inline bool is_phyrexian() const noexcept { return is_kind_of_atom(atoms::or_2_life); }

    inline bool is_undefined_amount() const noexcept { return is_kind_of_atom(atoms::undefined_amount); }
    inline amount_type cmd_amount() const noexcept
    {
      if (is_undefined_amount()) return 0;
      if (is_kind_of_atom(atoms::or_2_colorless)) return 2;
      return 1;
    }

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
    explicit mana(const std::string& str, flag_type atom) : m_atom(atom), m_str(str), m_index(index_counter++) {}

    static constexpr flag_type color_mask = (atoms::white | atoms::blue | atoms::black | atoms::red | atoms::green);

    flag_type m_atom;
    std::string m_str;
    index_type m_index;
  };

  class waste_mana final : public mana
  {
  public:
    static const waste_mana colorless;

    virtual ~waste_mana() = default;

  private:
    explicit waste_mana(const std::string& str) : mana(str, atoms::colorless) {}
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
    explicit snow_mana(const std::string& str, flag_type atom) : mana(str, atom) {}
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
    explicit hybrid_mana(const std::string& str, flag_type atom) : mana(str, atom) {}
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
    explicit phyrexian_mana(const std::string& str, flag_type atom) : mana(str, atom) {}
  };

} /*namespace card*/

#endif /*WITCHCRAFT_CARD_MANA_COST_HXX*/