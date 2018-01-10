#ifndef SQLITE_CXX_DETAIL_WRAPPER_HXX
#define SQLITE_CXX_DETAIL_WRAPPER_HXX

#include <utility>

namespace sqlite
{
  namespace detail
  {
    template <typename T>
    struct handle_traits
    {
      using type = T;
      static type invalid() noexcept { return nullptr; }
      // static void close( type value ) noexcept
    };

    template <typename traits>
    class handle
    {
    public:
      using type = decltype(traits::invalid());

      handle(const handle&) = delete;
      handle& operator=(const handle&) = delete;

      explicit handle(type value = traits::invalid()) noexcept : m_value(value) {}
      ~handle() noexcept { close(); }

      handle(handle&& other) noexcept : m_value(other.detach()) {}
      handle& operator=(handle&& other) noexcept
      {
        if (this != &other) reset(other.detach());
        return *this;
      }

      explicit operator bool() const noexcept { return m_value != traits::invalid(); }

      inline type get() const noexcept { return m_value; }
      inline type* set() noexcept { return &m_value; }

      type detach() noexcept
      {
        type value = m_value;
        m_value = traits::invalid();
        return value;
      }

      bool reset(type value = traits::invalid()) noexcept
      {
        if (m_value != value)
        {
          close();
          m_value = value;
        }
        return static_cast<bool>(*this);
      }

      void swap(handle<traits>& other) noexcept { std::swap(m_value, other.m_value); }

    private:
      void close() noexcept
      {
        if (*this) traits::close(m_value);
      }
      type m_value;
    };
  } // namepspace detail
} // namespace sqlite

template <typename traits>
void swap(sqlite::detail::handle<traits>& left, sqlite::detail::handle<traits>& right) noexcept
{
  left.swap(right);
}

template <typename traits>
bool operator==(const sqlite::detail::handle<traits>& left, const sqlite::detail::handle<traits>& right) noexcept
{
  return left.get() == right.get();
}

template <typename traits>
bool operator!=(const sqlite::detail::handle<traits>& left, const sqlite::detail::handle<traits>& right) noexcept
{
  return !(left == right);
}

#endif /*SQLITE_CXX_DETAILS_WRAPPER_HXX*/