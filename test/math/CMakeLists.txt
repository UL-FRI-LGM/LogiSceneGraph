cmake_minimum_required(VERSION 3.2)

include("${PROJECT_SOURCE_DIR}/cmake_modules/CreateTest.cmake")

set(TEST_NAME "test_math")
set(INCLUDES "")
file(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
set(DEPENDENCIES "LogiSceneGraph")

create_test("${TEST_NAME}" "${SOURCES}" "${INCLUDES}" "${DEPENDENCIES}")
