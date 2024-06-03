// Graph.hpp
// Author: [ahmad bsher]
// Email: [ahmadbsh30@gmail.com]
// ID: [213552698]

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <iostream>
#include <stdexcept>

using namespace std;

namespace ariel {
    class Graph {
    public:
        vector<vector<int>> adjMatrix;
        int numVertices;

        // Constructor
        Graph() : numVertices(0) {}

        // Method to load a graph from an adjacency matrix
        void loadGraph(const vector<vector<int>>& matrix) {
            int size = matrix.size();
            for (const auto& row : matrix) {
                if (row.size() != size) {
                    throw invalid_argument("Invalid graph: The graph is not a square matrix.");
                }
            }
            adjMatrix = matrix;
            numVertices = size;
        }

        // Method to print the graph
        void printGraph() const {
            cout << "Graph with " << numVertices << " vertices and " << countEdges() << " edges." << endl;
        }

    private:
        int countEdges() const {
            int edges = 0;
            for (int i = 0; i < numVertices; ++i) {
                for (int j = 0; j < numVertices; ++j) {
                    if (adjMatrix[i][j] != 0) {
                        edges++;
                    }
                }
            }
            return edges;
        }
    };
}

#endif
