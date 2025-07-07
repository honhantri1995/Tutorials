#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<vector<int>>& adj, int i, int j) {
    if (i >= adj.size() || j >= adj.size()) {
        cout << "FAIL" << endl;
        return;
    }
    adj[i].emplace_back(j);
    adj[j].emplace_back(i);     // Undirected
}

/*
    0: 1 2
    1: 0 2
    2: 0 1 3
    3: 2
*/
void display(vector<vector<int>> adj) {
    for (int i = 0; i < adj.size(); i++) {
        cout << i << ":";
        for (int j = 0; j < adj[i].size(); j++) {
            cout << " " << adj[i][j];
        }
        cout << endl;
    }
}

// NOTE: Due to fixed vector size, this code only works when maximum value of all vertices is not greater than number of vertices 
int main() {
    // Create a graph with 4 vertices and no edges
    int V = 4;
    vector<vector<int>> adj(V); 

    // Now add edges one by one
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);

    cout << "Adjacency list representation:" << endl;
    display(adj);

    return 0;
}