# Install script for directory: /home/user/code/c/basic_window/libs/SDL2

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/user/code/c/basic_window/build/libs/SDL2/libSDL2.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/user/code/c/basic_window/build/libs/SDL2/libSDL2main.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/SDL2" TYPE FILE FILES
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_assert.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_atomic.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_audio.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_bits.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_blendmode.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_clipboard.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_config_android.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_config_iphoneos.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_config_macosx.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_config_minimal.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_config_pandora.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_config_psp.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_config_windows.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_config_winrt.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_config_wiz.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_copying.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_cpuinfo.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_egl.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_endian.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_error.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_events.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_filesystem.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_gamecontroller.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_gesture.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_haptic.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_hints.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_joystick.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_keyboard.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_keycode.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_loadso.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_log.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_main.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_messagebox.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_mouse.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_mutex.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_name.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_opengl.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_opengl_glext.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_opengles.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_opengles2.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_opengles2_gl2.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_opengles2_gl2ext.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_opengles2_gl2platform.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_opengles2_khrplatform.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_pixels.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_platform.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_power.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_quit.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_rect.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_render.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_revision.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_rwops.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_scancode.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_shape.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_stdinc.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_surface.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_system.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_syswm.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_test.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_test_assert.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_test_common.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_test_compare.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_test_crc32.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_test_font.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_test_fuzzer.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_test_harness.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_test_images.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_test_log.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_test_md5.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_test_random.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_thread.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_timer.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_touch.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_types.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_version.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/SDL_video.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/begin_code.h"
    "/home/user/code/c/basic_window/libs/SDL2/include/close_code.h"
    "/home/user/code/c/basic_window/build/libs/SDL2/include/SDL_config.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/user/code/c/basic_window/build/libs/SDL2/sdl2.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE PROGRAM FILES "/home/user/code/c/basic_window/build/libs/SDL2/sdl2-config")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/share/aclocal/sdl2.m4")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/share/aclocal" TYPE FILE FILES "/home/user/code/c/basic_window/libs/SDL2/sdl2.m4")
endif()

