#include "dijkstras.h"

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous)
{
    int numVertices = G.size();
    vector<int> distances(numVertices, INF);
    vector<bool> visited(numVertices, false);
    distances[source] = 0;
    previous[source] = -1;

    struct MinHeap {
        bool operator() (const pair<int, int> &a, const pair<int, int>&b) {
            return a.second > b.second;
        }
    };

    priority_queue<pair<int,int>, vector<pair<int, int>>, MinHeap> minHeap;
    minHeap.push({source, 0});
    while (!minHeap.empty()) {
        int u = minHeap.top().first;
        minHeap.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (Edge e : G[u]) {
            int v = e.dst;
            int weight = e.weight;
            if (!visited[v] && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                previous[v] = u;
                minHeap.push({v, distances[v]});
            }
        }
    }
    return distances;
}

vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination)
{
    stack<int> s;
    for (int v = destination; v != -1; v = previous[v])
        s.push(v);

    vector<int> p;
    while (!s.empty()) {
        p.push_back(s.top());
        s.pop();
    }
    return p;
}

void print_path(const vector<int>& v, int total)
{
    for (int e : v)
        cout << e << " ";
    cout << "\nTotal cost is " << total << endl;
}

