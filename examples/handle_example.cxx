#include <sqlite3.h>
#include <sqlite_cxx/detail/wrapper.hxx>
#include <stdio.h>

struct connection_handle_traits : sqlite::detail::handle_traits<sqlite3*>
{
  static void close(type value) noexcept { sqlite3_close(value); }
};

using connection_handle = sqlite::detail::handle<connection_handle_traits>;

int main()
{
  connection_handle connection;
  int result = sqlite3_open(":memory:", connection.set());

  if (SQLITE_OK != result)
  {
    printf("%s\n", sqlite3_errmsg(connection.get()));
    return result;
  }
}
