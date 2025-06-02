cmake_minimum_required(VERSION 4.0.2)
project(CD-MediaPlayer)

INCLUDE_DIRECTORIES("include")
include_directories(/usr/include/vlc/)

add_executable(main main.c)
target_link_libraries(main vlc)