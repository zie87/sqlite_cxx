
set(WITCHCRAFT_TEST_NAME "${PROJECT_NAME}_test")

#set includes
include_directories ("${TEST_THIRD_PARTY_INCLUDE_PATH}")


add_executable (${WITCHCRAFT_TEST_NAME} "${CMAKE_CURRENT_SOURCE_DIR}/catch_main.cxx"
    )
# target_link_libraries (${WITCHCRAFT_TEST_NAME} ${PROJECT_NAME} )

enable_testing()
ParseAndAddCatchTests (${WITCHCRAFT_TEST_NAME})