#set includes
include_directories ("${TEST_THIRD_PARTY_INCLUDE_PATH}")


add_executable (${PROJECT_TEST_NAME} "${CATCH_MAIN_FILE}"
                                     "${CMAKE_CURRENT_SOURCE_DIR}/card/mana_cost_tests.cxx"
                                     
                                     "${CMAKE_CURRENT_SOURCE_DIR}/player/mana_pool_tests.cxx"
    )
target_link_libraries (${PROJECT_TEST_NAME} ${PROJECT_NAME} )

enable_testing()
ParseAndAddCatchTests (${PROJECT_TEST_NAME})