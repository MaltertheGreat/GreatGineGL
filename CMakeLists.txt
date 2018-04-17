cmake_minimum_required(VERSION 3.10)
project (GreatGine)

# Export code database fot vim-YCM code completion
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(SOURCES ${SRC_DIR}/main.cpp ${SRC_DIR}/GGApplication.cpp ${SRC_DIR}/GGOGL.cpp ${SRC_DIR}/GGGraphics.cpp ${SRC_DIR}/GGShader.cpp ${SRC_DIR}/GGMesh.cpp ${SRC_DIR}/GGCamera.cpp ${SRC_DIR}/GGInput.cpp)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")

add_executable(${PROJECT_NAME}  ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${SRC_DIR})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

# Shader files
configure_file(${SRC_DIR}/basic.vs basic.vs COPYONLY)
configure_file(${SRC_DIR}/basic.fs basic.fs COPYONLY)

# GLFW
find_package(glfw3 REQUIRED)
target_link_libraries(GreatGine	glfw)

# GLAD
set(GLAD_DIR "${LIB_DIR}/glad")
add_library("glad" "${GLAD_DIR}/src/glad.c")
target_include_directories("glad" PRIVATE "${GLAD_DIR}/include")
target_include_directories(${PROJECT_NAME} PRIVATE "${GLAD_DIR}/include")
target_link_libraries(${PROJECT_NAME} "glad" "${CMAKE_DL_LIBS}")

# GLM
set(GLM_DIR "${LIB_DIR}/glm")
target_include_directories(${PROJECT_NAME} PRIVATE "${GLM_DIR}/include")
