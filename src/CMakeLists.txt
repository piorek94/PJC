set(MAIN_SOURCE_FILES
        main.cpp)

add_subdirectory(controller)
add_subdirectory(model)
add_subdirectory(view)
add_subdirectory(common)

add_executable(PJC ${MAIN_SOURCE_FILES})
target_link_libraries(PJC controller model view common)
