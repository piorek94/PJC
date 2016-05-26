set(MAIN_SOURCE_FILES board.cpp
        creature.cpp
        imobile.cpp
        iobject.cpp
        isize.cpp
        main.cpp
        obstacle.h
        player.h
        board.h
        creature.h
        imobile.h
        iobject.h
        isize.h
        obstacle.cpp
        player.cpp)

add_executable(PJC ${MAIN_SOURCE_FILES})
target_link_libraries(PJC ${SDL2_LDFLAGS} ${SDL2IMAGE_LDFLAGS})
