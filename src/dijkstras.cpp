#include "dijkstras.h"

struct Node {
    int vertex = 0;
    int weight = 0;

    Node(int v, int w) : vertex(v), weight(w) {}
}

struct Graph {
    vector<list<Node>> adjacencyList;
    vector<int> distance;
    vector<int> previous;
    vector<bool> visited;
}

// vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous);
// vector<int> extract_shortest_path(const vector<int>& /*distances*/, const vector<int>& previous, int destination);
// void print_path(const vector<int>& v, int total);
