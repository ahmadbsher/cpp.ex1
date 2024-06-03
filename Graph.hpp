// Graph.hpp
// Author: [Your Name]
// Email: [Your Email]
// ID: [Your ID]

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
