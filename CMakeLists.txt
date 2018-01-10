cmake_minimum_required(VERSION 3.1)

<<<<<<< HEAD
project(sqlite_cxx LANGUAGES C CXX VERSION 0.0.1)
=======
project(witchcraft LANGUAGES C CXX VERSION 0.0.1)
>>>>>>> 7e014cdab92e50002854512c65e9adcd1b234375

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(PROJECT_TEST_NAME "${PROJECT_NAME}_test")
if (CMAKE_BUILD_TYPE STREQUAL "Coverage")
  include(CodeCoverage)
  set(CMAKE_CXX_FLAGS "-g -O0 -Wall --coverage")
  set(LCOV_REMOVE_EXTRA 'test/*' '3rd/*')
  setup_target_for_coverage(test_coverage ${PROJECT_TEST_NAME} coverage)
endif (CMAKE_BUILD_TYPE STREQUAL "Coverage")

<<<<<<< HEAD
include (FindSQLite3)
find_package (SQLite3 REQUIRED)
include_directories (${SQLITE3_INCLUDE_DIRS})
add_subdirectory (3rd EXCLUDE_FROM_ALL)

include_directories ("${PROJECT_SOURCE_DIR}/inc")
add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(examples)
=======
include (FindSDL2)
find_package (SDL2 REQUIRED)
include_directories (${SDL2_INCLUDE_DIR})

include (FindSDL2_image)
find_package(SDL2_image)

include (FindSDL2_ttf)
find_package(SDL2_ttf)

add_subdirectory (3rd EXCLUDE_FROM_ALL)
add_definitions(-DWITCHCRAFT_DATA="${CMAKE_CURRENT_SOURCE_DIR}/data")

include_directories(inc ${SDL2_CXX_INCLUDE_PATH})
add_subdirectory(src)
add_subdirectory(test)
>>>>>>> 7e014cdab92e50002854512c65e9adcd1b234375

find_package(Doxygen)
if(DOXYGEN_FOUND)
    add_subdirectory(doc)
endif()

include(CTest)
enable_testing()