set(VIEW_SOURCE_FILES
        View.h
        View.cpp)

find_package(Threads)

add_library(view STATIC ${VIEW_SOURCE_FILES})
target_link_libraries(view ${CMAKE_THREAD_LIBS_INIT})