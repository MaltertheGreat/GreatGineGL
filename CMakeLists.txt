cmake_minimum_required(VERSION 3.10)
project (GreatGine)

# Export code database fot vim-YCM code completion
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(SOURCES ${SRC_DIR}/main.cpp ${SRC_DIR}/GGApplication.cpp ${SRC_DIR}/GGOGL.cpp ${SRC_DIR}/GGGraphics.cpp ${SRC_DIR}/GGShader.cpp ${SRC_DIR}/GGMesh.cpp ${SRC_DIR}/GGCamera.cpp ${SRC_DIR}/GGInput.cpp ${SRC_DIR}/GGChunk.cpp ${SRC_DIR}/GGChunkModel.cpp ${SRC_DIR}/GGTexture.cpp ${SRC_DIR}/stb_image.cpp)

#set(GCC_FLAGS "-Weverything")
#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} ${GCC_FLAGS}")
#set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} ${GCC_FLAGS}")

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
find_package(glm REQUIRED)
target_link_libraries(GreatGine	glm)
