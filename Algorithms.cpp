// Algorithms.cpp
// Author: [Your Name]
// Email: [Your Email]
// ID: [Your ID]

#include "Algorithms.hpp"
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <functional>
#include <limits>
#include <stack>

using namespace std;

namespace ariel {

    bool Algorithms::isConnected(const Graph& g) {
        int n = g.numVertices;
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int count = 1;

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int i = 0; i < n; ++i) {
                if (g.adjMatrix[v][i] != 0 && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                    ++count;
                }
            }
        }
        return count == n;
    }

    string Algorithms::shortestPath(const Graph& g, int start, int end) {
        int n = g.numVertices;
        vector<int> dist(n, numeric_limits<int>::max());
        vector<int> prev(n, -1);
        dist[start] = 0;

        queue<int> q;
        q.push(start);

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int i = 0; i < n; ++i) {
                if (g.adjMatrix[v][i] != 0) {
                    int alt = dist[v] + g.adjMatrix[v][i];
                    if (alt < dist[i]) {
                        dist[i] = alt;
                        prev[i] = v;
                        q.push(i);
                    }
                }
            }
        }

        if (dist[end] == numeric_limits<int>::max()) {
            return "-1";
        }

        stack<int> path;
        for (int at = end; at != -1; at = prev[at]) {
            path.push(at);
        }

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

    bool Algorithms::isContainsCycle(const Graph& g) {
        int n = g.numVertices;
        vector<bool> visited(n, false);
        vector<int> parent(n, -1);

        function<bool(int, int)> dfs = [&](int v, int p) {
            visited[v] = true;
            for (int i = 0; i < n; ++i) {
                if (g.adjMatrix[v][i] != 0) {
                    if (!visited[i]) {
                        parent[i] = v;
                        if (dfs(i, v)) {
                            return true;
                        }
                    } else if (i != p) {
                        return true;
                    }
                }
            }
            return false;
        };

        for (int i = 0; i < n; ++i) {
            if (!visited[i] && dfs(i, -1)) {
                return true;
            }
        }

        return false;
    }

    bool Algorithms::isBipartite(const Graph& g) {
        int n = g.numVertices;
        vector<int> color(n, -1);

        function<bool(int, int)> bfs = [&](int src, int col) {
            queue<int> q;
            q.push(src);
            color[src] = col;

            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (int i = 0; i < n; ++i) {
                    if (g.adjMatrix[v][i] != 0) {
                        if (color[i] == -1) {
                            color[i] = 1 - color[v];
                            q.push(i);
                        } else if (color[i] == color[v]) {
                            return false;
                        }
                    }
                }
            }

            return true;
        };

        for (int i = 0; i < n; ++i) {
            if (color[i] == -1 && !bfs(i, 0)) {
                return false;
            }
        }

        return true;
    }

    string Algorithms::negativeCycle(const Graph& g) {
        int n = g.numVertices;
        vector<int> dist(n, numeric_limits<int>::max());
        vector<int> parent(n, -1);
        dist[0] = 0;

        for (int i = 0; i < n - 1; ++i) {
            for (int u = 0; u < n; ++u) {
                for (int v = 0; v < n; ++v) {
                    if (g.adjMatrix[u][v] != 0) {
                        if (dist[u] != numeric_limits<int>::max() && dist[u] + g.adjMatrix[u][v] < dist[v]) {
                            dist[v] = dist[u] + g.adjMatrix[u][v];
                            parent[v] = u;
                        }
                    }
                }
            }
        }

        for (int u = 0; u < n; ++u) {
            for (int v = 0; v < n; ++v) {
                if (g.adjMatrix[u][v] != 0) {
                    if (dist[u] != numeric_limits<int>::max() && dist[u] + g.adjMatrix[u][v] < dist[v]) {
                        stack<int> cycle;
                        for (int x = v; ; x = parent[x]) {
                            cycle.push(x);
                            if (x == v && cycle.size() > 1) break;
                        }

                        string result = "Negative cycle: ";
                        while (!cycle.empty()) {
                            result += to_string(cycle.top());
                            cycle.pop();
                            if (!cycle.empty()) {
                                result += "->";
                            }
                        }
                        return result;
                    }
                }
            }
        }

        return "No negative cycle exists.";
    }
}
