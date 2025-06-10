cmake_minimum_required(VERSION 4.0.2)
project(CD-MediaPlayer)

INCLUDE_DIRECTORIES("include")

include_directories(/usr/include/vlc/)
link_directories(/usr/lib/vlc/)
include_directories(/usr/include/ncurses/)

add_executable(main src/main.c src/start.c src/vlc_cont.c)
target_link_libraries(main vlc ncurses)