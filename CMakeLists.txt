project(basic_window)
cmake_minimum_required(VERSION 2.8)



set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_FORCE_INLINES")

#flags to SDL2
option(SDL_SHARED "help string describing option" OFF)
set( SDL_SHARED OFF CACHE BOOL "Build the shared SDL library" )
set( SDL_STATIC ON CACHE BOOL "Build a static version of the library" )
set( SDL_AUDIO OFF CACHE BOOL "Audio" )
set( VIDEO_OPENGLES OFF CACHE BOOL  "Include OpenGL ES support")
set(SDL_STATIC_PIC  ON CACHE BOOL  "Static version of the library should be built with Position Independent Code")
  

 


file (GLOB_RECURSE SRC_LIST src/*.c src/*.h)


ADD_SUBDIRECTORY(libs/SDL2)
set(SDL_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/libs/SDL2/include)
include_directories( ${SDL_INCLUDE_DIRS})
include_directories( ${PROJECT_SOURCE_DIR}/libs/glad)
set(SRC_LIST ${SRC_LIST} ${PROJECT_SOURCE_DIR}/libs/glad/glad.h ${PROJECT_SOURCE_DIR}/libs/glad/glad.c)
if(MINGW)
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c99 -pedantic -static -Wall  -O3")
    add_executable(${PROJECT_NAME} ${SRC_LIST} ${PROJECT_SOURCE_DIR}/resources/icon.rc)
    TARGET_LINK_LIBRARIES(${PROJECT_NAME} mingw32 SDL2main SDL2-static ${OPENGL_LIBRARY})
endif(MINGW)

if(MSVC)
    set(EXECUTABLE_OUTPUT_PATH "binMSVS")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -static -Wall -mwindows -O3")
    add_executable(${PROJECT_NAME} ${SRC_LIST} ${PROJECT_SOURCE_DIR}/resources/icon.rc)
    TARGET_LINK_LIBRARIES(${PROJECT_NAME} SDL2main SDL2-static ${OPENGL_LIBRARY})
endif(MSVC)

if (UNIX)
    SET(DDM_DESKTOP_DIR     "/usr/share/applications/")
    SET(DDM_PIXMAPS_DIR     "/usr/share/icons/")
    #set(EXECUTABLE_OUTPUT_PATH "binUnix")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c99 -pedantic -Wall -O3")
    add_executable(${PROJECT_NAME} ${SRC_LIST} ${PROJECT_SOURCE_DIR}/resources/icon.rc)
    TARGET_LINK_LIBRARIES(${PROJECT_NAME} SDL2-static ${OPENGL_LIBRARY}   )
endif(UNIX)







if (ANDROID)

    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
    set(BUILD_SHARED_LIBS TRUE)
    set(EXECUTABLE_OUTPUT_PATH "binAndroid")


    include(${PROJECT_SOURCE_DIR}/src/android-project/cmake/android.cmake)
    include(${PROJECT_SOURCE_DIR}/src/android-project/cmake/macros.cmake)
    #add_definitions( -DGLES2=1 )
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

    set( SDL_SHARED OFF CACHE BOOL "Build the shared SDL library" )
    set( SDL_SHARED OFF CACHE BOOL "Build the shared SDL library" )
    set( SDL_STATIC ON CACHE BOOL "Build a static version of the library" )
    set( SDL_AUDIO OFF CACHE BOOL "Audio" )
    set( VIDEO_OPENGLES ON CACHE BOOL  "Include OpenGL ES support")
    set(SDL_STATIC_PIC  ON CACHE BOOL  "Static version of the library should be built with Position Independent Code")

    #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -O3")
    ###############

    set(ANDROID_BIN_ROOT ${PROJECT_SOURCE_DIR}/build/bin-android)
    add_custom_target(android-install ${ANDROID_ANT} ${ANT_INSTALL_TARGET} WORKING_DIRECTORY ${ANDROID_BIN_ROOT})
    add_custom_target(android-backtrace ${ANDROID_ADB} logcat WORKING_DIRECTORY ${ANDROID_BIN_ROOT})
    add_custom_target(android-build ${ANDROID_ANT} ${ANT_FLAGS} ${ANT_TARGET} WORKING_DIRECTORY ${ANDROID_BIN_ROOT})
    add_custom_target(android-start ${ANDROID_ADB} shell am start -n org.libsdl.app/org.libsdl.app.SDLActivity WORKING_DIRECTORY ${ANDROID_BIN_ROOT})


    # add_library (${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/libs/SDL2-2.0.5/src/main/android/SDL_android_main.c ${SRC_LIST})
    #  target_link_libraries (game engine)
    set (${SRC_LIST} ${SRC_LIST} ${PROJECT_SOURCE_DIR}/libs/SDL2/src/main/android/SDL_android_main.c)

    message(STATUS ${SRC_LIST})
    TARGET_LINK_LIBRARIES(${PROJECT_NAME} SDL2-static)

    # add_custom_command(TARGET game POST_BUILD COMMAND ${ANDROID_ANT} ${ANT_FLAGS} ${ANT_TARGET} WORKING_DIRECTORY ${ANDROID_BIN_ROOT})

    add_custom_command(TARGET ${PROJECT_NAME} PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${PROJECT_SOURCE_DIR}/src/android-project/
        ${ANDROID_BIN_ROOT}/)

    add_custom_command(TARGET ${PROJECT_NAME} PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${PROJECT_SOURCE_DIR}/src/image/
        ${ANDROID_BIN_ROOT}/image)

    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/ ${ANDROID_BIN_ROOT}/libs/${ANDROID_NDK_ABI_NAME})

    ##############

endif(ANDROID)
