// Graph.cpp
// Author: [ahmad bsher]
// Email: [ahmadbsh30@gmail.com]
// ID: [213552698]

#include "Graph.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

namespace ariel {

    Graph::Graph() : numVertices(0) {}

    void Graph::loadGraph(const vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (const auto& row : matrix) {
            if (row.size() != n) {
                throw invalid_argument("Invalid graph: The graph is not a square matrix.");
            }
        }
        adjMatrix = matrix;
        numVertices = n;
    }

    void Graph::printGraph() const {
        cout << "Graph with " << numVertices << " vertices." << endl;
        for (const auto& row : adjMatrix) {
            for (int val : row) {
                cout << val << " ";
            }
            cout << endl;
        }
    }
}
