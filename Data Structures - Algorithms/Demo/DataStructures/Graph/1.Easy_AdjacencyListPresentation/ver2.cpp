#include <iostream>
#include <map>
#include <vector>
using namespace std;

void addEdge(map<int, vector<int>>& adj, int i, int j) {
    adj[i].emplace_back(j); // Node i is neighbor of node j
    adj[j].emplace_back(i); // Node j is neighbor of node 
}

void display(map<int, vector<int>> adj) {
    for (int i = 0; i < adj.size(); i++) {
        cout << i << ":";
        for (int j = 0; j < adj[i].size(); j++) {
            cout << " " << adj[i][j];
        }
        cout << endl;
    }
}

// NOTE: Thanks to map, this code works for all cases
int main() {
    map<int, vector<int>> adj = {}; 

    // Add edges one by one
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);

    cout << "Adjacency list representation:" << endl;
    display(adj);

    return 0;
}