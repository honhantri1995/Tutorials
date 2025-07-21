#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<pair<int, int>>& edgeSet, int i, int j) {
    edgeSet.emplace_back(i, j); // Node i is neighbor of node j
    edgeSet.emplace_back(j, i); // Node j is neighbor of node i
}

void displayEdges(const vector<pair<int, int>>& edgeSet) {
    cout << "Edge Set:\n";
    for (const auto& edge : edgeSet) {
        cout << "(" << edge.first << ", " << edge.second << ")\n";
    }
}

int main() {
    vector<pair<int, int>> edgeSet;

    addEdge(edgeSet, 0, 1);
    addEdge(edgeSet, 0, 2);
    addEdge(edgeSet, 1, 2);
    addEdge(edgeSet, 2, 3);

    displayEdges(edgeSet);

    return 0;
}