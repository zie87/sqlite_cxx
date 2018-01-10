add_executable (sqlite_example_plain "${CMAKE_CURRENT_SOURCE_DIR}/sqlite_example.cxx"
    )
target_link_libraries (sqlite_example_plain ${SQLITE3_LIBRARIES} )

add_executable (sqlite_example_handle "${CMAKE_CURRENT_SOURCE_DIR}/handle_example.cxx"
    )
target_link_libraries (sqlite_example_handle ${SQLITE3_LIBRARIES} )