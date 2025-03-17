#include "dijkstras.h"

struct Node {
    int vertex = 0;
    int weight = 0;

    Node(int v, int w) : vertex(v), weight(w) {}
};


// struct Graph {
//     vector<vector<int>> adjacencyList;
//     vector<int> distance;
//     vector<int> previous;
//     vector<int> visited;
// }

// void dijkstra(int source, vector<vector<int>> &graph) {
//     int n = graph.adjacencyList.size();

//     graph.distance.resize(n, INT_MAX);
//     graph.previous.resize(n, -1);
//     graph.visited.resize(n, false);

//     priority_queue<int> pq;
//     pq.push(Node(source, 0));
//     graph.distance[source] = 0;

//     while (!pq.empty()) {
//         Node current = pq.top();
//         pq.pop();
        
//         int u = current.vertex;

//         if (graph.visited[u]) continue;
//         graph.visited[u] = true;

//         for (Node& neighbor : graph.adjacencyList[u]) {
//             int v = neighbor.vertex;
//             int weight = neighbor.weight;

//             if  (!graph.visited[v] && (graph.distance[u] + weight < graph.distance[v])) {
//                 graph.distance[v] = graph.distance[u] + weight;
//                 graph.previous[v] = u;
//                 pq.push(Node(v, graph.distance[v]));
//             }
//         }
//     }
// }

// vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous);
// vector<int> extract_shortest_path(const vector<int>& /*distances*/, const vector<int>& previous, int destination);
void print_path(const vector<int>& v, int total)
{
    for (int e : v)
        cout << e << " ";
    cout << "\ntotal: " << total << endl;
}

