// Graph.cpp
// Author: [ahmad basher]
// Email: [ahmadbsh30@gmail.com]
// ID: [213552698]

#include "Graph.hpp"

namespace ariel {
    // Constructor (already defined in Graph.hpp)
    // Graph::Graph() : numVertices(0) {}

    // Method to load a graph from an adjacency matrix
    void Graph::loadGraph(const vector<vector<int>>& matrix) {
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
    void Graph::printGraph() const {
        cout << "Graph with " << numVertices << " vertices and " << countEdges() << " edges." << endl;
    }

    // Private method to count the number of edges in the graph
    int Graph::countEdges() const {
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
}
