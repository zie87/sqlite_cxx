set (THIRD_PARTY_MODULE_PATH "${PROJECT_SOURCE_DIR}/3rd")

# -------------------------------------------------------------------------
# catch

#configure directories
set (CATCH_MODULE_PATH "${THIRD_PARTY_MODULE_PATH}/Catch")
set (CATCH_INCLUDE_PATH "${CATCH_MODULE_PATH}/single_include")

#include custom cmake function
include ( "${CATCH_MODULE_PATH}/contrib/ParseAndAddCatchTests.cmake")

# -------------------------------------------------------------------------

#set variables for tests
set (TEST_THIRD_PARTY_INCLUDE_PATH  ${CATCH_INCLUDE_PATH})
set (TEST_THIRD_PARTY_INCLUDE_PATH  ${TEST_THIRD_PARTY_INCLUDE_PATH} PARENT_SCOPE)

# -------------------------------------------------------------------------
# json

#configure directories
set (JSON_MODULE_PATH  "${THIRD_PARTY_MODULE_PATH}/json")
set (JSON_INCLUDE_PATH "${SDL2_CXX_MODULE_PATH}/single_include")

# -------------------------------------------------------------------------
# sdl2_cxx

#configure directories
set (SDL2_CXX_MODULE_PATH "${THIRD_PARTY_MODULE_PATH}/sdl2_cxx")
set (SDL2_CXX_INCLUDE_PATH "${SDL2_CXX_MODULE_PATH}/inc")
set (SDL2_CXX_INCLUDE_PATH  ${SDL2_CXX_INCLUDE_PATH} PARENT_SCOPE)
