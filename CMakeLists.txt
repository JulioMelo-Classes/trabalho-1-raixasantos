cmake_minimum_required(VERSION 3.0.0)
project(keno VERSION 0.1.0)

include_directories(include)
enable_testing()

add_executable(keno src/main.cpp
                    src/Interface.cpp
                    src/Arquive.cpp
                    #src/KenoBet.cpp
                    )
