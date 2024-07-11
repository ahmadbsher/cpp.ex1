# Assignment 1 - Graphs (Classes and Namespaces)

Your objective in this assignment is to create a class that represents a graph and to implement algorithms on the graphs (it's time to recall Algorithms 1 course).

In this assignment, your graph representation will be implemented using an adjacency matrix - https://en.wikipedia.org/wiki/Adjacency_matrix.

The graph can be directed or undirected, and it can also be weighted. The adjacency matrix must be a square matrix.

You need to write the following files:

```
Graph.cpp
Algorithms.cpp
```

The file `Graph.cpp` contains a class representing a graph.
The class includes the methods `loadGraph`, which receives an adjacency matrix and loads it into the graph, and `printGraph`, which prints the representation of the graph (the format is up to you, see an example in `Demo.cpp`).

The file `Algorithms.cpp` contains implementations of algorithms on graphs, including:

- `isConnected(g)` - The algorithm receives a graph and returns 1 if the graph is connected (otherwise, it returns 0).
- `shortestPath(g, start, end)` - The algorithm receives a graph, a start vertex, and an end vertex, and returns the shortest path (if the graph is unweighted - the shortest path) between the two vertices. If there is no such path, the algorithm returns -1.
- `isContainsCycle(g)` - The algorithm receives a graph and prints any cycle. If there is no cycle in the graph, the algorithm returns 0.
- `isBipartite(g)` - The algorithm receives a graph and returns the bipartite division of the graph. If it is not possible to divide the graph, the algorithm returns 0.
- `negativeCycle(g)` - The algorithm receives a graph and finds a negative cycle (a cycle where the sum of the edge weights is negative). If there is no such cycle, the algorithm prints that no negative cycle exists.

The file `Demo.cpp` contains examples of inputs and outputs.
You must write your ID number and email at the beginning of each file. Additionally, besides the assignment files, you are required to submit a README file that describes the implementation and the division you performed in the code (a kind of user guide). Failure to comply with the instructions will result in a grade reduction. Good luck!