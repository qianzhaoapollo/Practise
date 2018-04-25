cmake_minimum_required(VERSION 2.6)
project(practise)

set(SRCS
    list/list.cpp
    stack/stack.cpp
    main.cpp
)

add_executable(practise ${SRCS})

install(TARGETS practise RUNTIME DESTINATION bin)
