#include "dijkstras.h"

int main() {
    Graph G;
    file_to_graph("src/small.txt", G);
    vector<int> previous(G.size(), -1);
    vector<int> distances = dijkstra_shortest_path(G, 0, previous);
    vector<int> path = extract_shortest_path(distances, previous, 3);
    print_path(path, distances[3]);
    return 0;
}