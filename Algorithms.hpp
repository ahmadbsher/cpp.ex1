// Algorithms.hpp
// Author: [ahmad bsher]
// Email: [ahmadbsh30@gmail.com]
// ID: [213552698]

#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "Graph.hpp"
#include <vector>
#include <string>

namespace ariel {
    class Algorithms {
    public:
        static bool isConnected(const Graph& g);
        static std::string shortestPath(const Graph& g, int start, int end);
        static bool isContainsCycle(const Graph& g);
        static bool isBipartite(const Graph& g);
        static std::string negativeCycle(const Graph& g);
    };
}

#endif // ALGORITHMS_HPP
