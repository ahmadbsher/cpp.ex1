// Graph.hpp
// Author: [ahmad bsher]
// Email: [ahmadbsh30@gmail.com]
// ID: [213552698]

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <iostream>

namespace ariel {
    class Graph {
    public:
        std::vector<std::vector<int>> adjMatrix;
        int numVertices;

        Graph();

        void loadGraph(const std::vector<std::vector<int>>& matrix);
        void printGraph() const;
    };
}

#endif // GRAPH_HPP
