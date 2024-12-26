cmake_minimum_required(VERSION 3.30)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


project(OpenGLGame VERSION 1.0)





set(SOURCES

App.cpp
GLAD/gl.c
stb_image.c
stb_image.h

Src/Classes/Window.h
Src/Classes/Window.cpp
Src/Classes/Shader.h
Src/Classes/Shader.cpp
Src/Classes/Texture.h
Src/Classes/Texture.cpp
Src/Classes/Loader.h
Src/Classes/Loader.cpp
Src/Classes/Model.h
Src/Classes/Model.cpp
Src/Classes/Camera.h
Src/Classes/Camera.cpp

Src/Shaders/Basic.shader
)



add_executable(OpenGLGame ${SOURCES})



add_custom_command(
    TARGET OpenGLGame  # Replace with your target name
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${PROJECT_SOURCE_DIR}/SDL3.dll  # Source DLL
        ${PROJECT_BINARY_DIR}/Debug  # Destination directory
    COMMENT "Copying DLL to the build directory"
)

add_custom_command(
    TARGET OpenGLGame  # Replace with your target name
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${PROJECT_SOURCE_DIR}/Src/Shaders/Basic.shader  # Source DLL
        ${PROJECT_BINARY_DIR}/Debug  # Destination directory
    COMMENT "Copying DLL to the build directory"
)

add_custom_command(
    TARGET OpenGLGame  # Replace with your target name
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${PROJECT_SOURCE_DIR}/metal.jpg  # Source DLL
        ${PROJECT_BINARY_DIR}/Debug  # Destination directory
    COMMENT "Copying DLL to the build directory"
)

add_custom_command(
    TARGET OpenGLGame  # Replace with your target name
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${PROJECT_SOURCE_DIR}/Src/Meshes/monkey3.obj  # Source DLL
        ${PROJECT_BINARY_DIR}/Debug  # Destination directory
    COMMENT "Copying DLL to the build directory"
)





include_directories(${CMAKE_SOURCE_DIR} glm)

target_include_directories(OpenGLGame PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} Src/Classes)

include_directories(${CMAKE_SOURCE_DIR} SDL3)
target_link_libraries(OpenGLGame PUBLIC ${CMAKE_SOURCE_DIR} ../SDL3)

include_directories(${CMAKE_SOURCE_DIR} GLAD/include)

target_link_libraries(OpenGLGame PRIVATE opengl32)
