cmake_minimum_required(VERSION 3.10)
project (GreatGine)

# Export code database fot vim-YCM code completion
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(SOURCES ${SRC_DIR}/main.cpp ${SRC_DIR}/GGApplication.cpp ${SRC_DIR}/GGGraphics.cpp)

add_executable(GreatGine ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${SRC_DIR})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)


# GLFW
find_package(glfw3 REQUIRED)
target_link_libraries(GreatGine	glfw)


# GLAD
set(GLAD_DIR "${LIB_DIR}/glad")
add_library("glad" "${GLAD_DIR}/src/glad.c")
target_include_directories("glad" PRIVATE "${GLAD_DIR}/include")
target_include_directories(${PROJECT_NAME} PRIVATE "${GLAD_DIR}/include")
target_link_libraries(${PROJECT_NAME} "glad" "${CMAKE_DL_LIBS}")
