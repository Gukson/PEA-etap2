cmake_minimum_required(VERSION 3.28)
project(PEA_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(PEA_2 main.cpp
        TSP/BaB/DFS/DFS.cpp
        TSP/BaB/DFS/DFS.h
        TSP/BaB/DFS/DFS.h
        TSP/BaB/BFS/BFS.cpp
        TSP/BaB/BFS/BFS.h
        data/data_loader/DataLoader.cpp
        Tree/Node/Node.cpp)
