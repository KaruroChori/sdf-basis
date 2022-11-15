set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(test-suite-working main.cpp)
target_link_libraries(test-suite-working ${LIBS} ${LOC_LIBS})
add_test(NAME test-suite-working COMMAND test-suite-working)
