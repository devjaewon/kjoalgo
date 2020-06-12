// Created by Jaewon Kim on 2020/06/12
// Copyright © 2020 jaewonkim. All rights reserved.

#include "./Dijkstra.hpp"

int main() {
    Algo::Dijkstra dijkstra;
    // use matrix for convenience
    int graph[5][5];

    graph[5][2] = 4;
    graph[5][4] = 2;
    graph[4][2] = 1;
    graph[4][3] = 1;
    graph[3][4] = 2;
    graph[2][1] = 3;
    graph[1][3] = 6;
    graph[1][4] = 3;

    return 0;
}
