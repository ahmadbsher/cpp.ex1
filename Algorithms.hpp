// Algorithms.hpp
// Author: [ahmad bsher]
// Email: [ahmadbsh30@gmail.com]
// ID: [213552698]

#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "Graph.hpp"
#include <vector>
#include <queue>
#include <stack>
#include <limits>
#include <iostream>
#include <stdexcept>

using namespace std;

namespace ariel {
    class Algorithms {
    public:
        // Function to check if the graph is connected
        static bool isConnected(const Graph& g);

        // Function to find the shortest path in an unweighted graph
        static string shortestPath(const Graph& g, int start, int end);

        // Function to check if the graph contains a cycle
        static bool isContainsCycle(const Graph& g);

        // Function to check if the graph is bipartite
        static string isBipartite(const Graph& g);
    };
}

#endif
