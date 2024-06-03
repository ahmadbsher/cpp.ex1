// Algorithms.cpp
// Author: [ahmad bsher]
// Email: [ahmadbsh30@gmail.com]
// ID: [213552698]

#include "Algorithms.hpp"

namespace ariel {
    // Function to check if the graph is connected
    bool Algorithms::isConnected(const Graph& g) {
        vector<bool> visited(g.numVertices, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int count = 1;

        while (!q.empty()) {
            int vertex = q.front();
            q.pop();

            for (int i = 0; i < g.numVertices; ++i) {
                if (g.adjMatrix[vertex][i] != 0 && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                    ++count;
                }
            }
        }

        return count == g.numVertices;
    }

    // Function to find the shortest path in an unweighted graph
    string Algorithms::shortestPath(const Graph& g, int start, int end) {
        if (start < 0 || end >= g.numVertices) {
            return "-1";
        }

        vector<int> distance(g.numVertices, numeric_limits<int>::max());
        vector<int> parent(g.numVertices, -1);
        queue<int> q;
        q.push(start);
        distance[start] = 0;

        while (!q.empty()) {
            int vertex = q.front();
            q.pop();

            for (int i = 0; i < g.numVertices; ++i) {
                if (g.adjMatrix[vertex][i] != 0 && distance[i] == numeric_limits<int>::max()) {
                    distance[i] = distance[vertex] + 1;
                    parent[i] = vertex;
                    q.push(i);
                }
            }
        }

        if (distance[end] == numeric_limits<int>::max()) {
            return "-1";
        }

        // Build path
        stack<int> path;
        int crawl = end;
        path.push(crawl);
        while (parent[crawl] != -1) {
            path.push(parent[crawl]);
            crawl = parent[crawl];
        }

        // Create string representation of the path
        string result;
        while (!path.empty()) {
            result += to_string(path.top());
            path.pop();
            if (!path.empty()) {
                result += "->";
            }
        }

        return result;
    }

    // Function to check if the graph contains a cycle
    bool Algorithms::isContainsCycle(const Graph& g) {
        vector<bool> visited(g.numVertices, false);
        vector<bool> recStack(g.numVertices, false);

        function<bool(int)> dfs = [&](int v) {
            if (!visited[v]) {
                visited[v] = true;
                recStack[v] = true;

                for (int i = 0; i < g.numVertices; ++i) {
                    if (g.adjMatrix[v][i] != 0 && !visited[i] && dfs(i)) {
                        return true;
                    } else if (g.adjMatrix[v][i] != 0 && recStack[i]) {
                        return true;
                    }
                }
            }
            recStack[v] = false;
            return false;
        };

        for (int i = 0; i < g.numVertices; ++i) {
            if (dfs(i)) {
                return true;
            }
        }

        return false;
    }

    // Function to check if the graph is bipartite
    string Algorithms::isBipartite(const Graph& g) {
        vector<int> color(g.numVertices, -1);
        queue<int> q;

        for (int i = 0; i < g.numVertices; ++i) {
            if (color[i] == -1) {
                color[i] = 0;
                q.push(i);

                while (!q.empty()) {
                    int u = q.front();
                    q.pop();

                    for (int v = 0; v < g.numVertices; ++v) {
                        if (g.adjMatrix[u][v] && color[v] == -1) {
                            color[v] = 1 - color[u];
                            q.push(v);
                        } else if (g.adjMatrix[u][v] && color[v] == color[u]) {
                            return "0";
                        }
                    }
                }
            }
        }

        // Build bipartite sets
        string A = "A={";
        string B = "B={";
        for (int i = 0; i < g.numVertices; ++i) {
            if (color[i] == 0) {
                A += to_string(i) + ", ";
            } else {
                B += to_string(i) + ", ";
            }
        }
        // Remove trailing comma and space
        if (A.size() > 2) A.pop_back(), A.pop_back();
        if (B.size() > 2) B.pop_back(), B.pop_back();
        A += "}";
        B += "}";

        return "The graph is bipartite: " + A + ", " + B;
    }
}
