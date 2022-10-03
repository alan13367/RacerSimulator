cmake_minimum_required(VERSION 3.15)
project(P2Final C)

set(CMAKE_C_STANDARD 11)
set(ALLEGRO_DIR "C:\\MinGW")
include_directories(${ALLEGRO_DIR}/include)
link_directories(${ALLEGRO_DIR}/lib)


add_executable(P2Final main.c LS_allegro.c LS_allegro.h Option1.c Option1.h Option2.c Option2.h sortedlist.c sortedlist.h Menu.c Menu.h sortedgplist.c sortedgplist.h Option3.c Option3.h Option4.c Option4.h)

target_link_libraries(P2Final -lmingw32 -lallegro-5.0.10-monolith-md-debug)