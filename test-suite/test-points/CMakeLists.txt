set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(test-points main.cpp)
target_link_libraries(test-points ${LIBS} ${LOC_LIBS})
add_test(NAME test-points COMMAND test-points)
