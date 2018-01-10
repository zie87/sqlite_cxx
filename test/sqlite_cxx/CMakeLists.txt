#set includes
include_directories ("${TEST_THIRD_PARTY_INCLUDE_PATH}")

add_executable (${PROJECT_TEST_NAME} "${CATCH_MAIN_FILE}"
    )
target_link_libraries (${PROJECT_TEST_NAME} ${SQLITE3_LIBRARIES} )

enable_testing()
ParseAndAddCatchTests (${PROJECT_TEST_NAME})