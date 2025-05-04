#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void addEdge(vector<vector<int>>& adj, int i, int j) {
    if (i >= adj.size() || j >= adj.size()) {
        cout << "FAIL" << endl;
        return;
    }
    adj[i].emplace_back(j);
    adj[j].emplace_back(i);     // Undirected
}

void printQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

void bfs(vector<vector<int>> adj, int start_vertex, vector<bool>& visited) {
    queue<int> queue = {};

    visited[start_vertex] = true;
    queue.push(start_vertex);

    while (!queue.empty()) {                 // O(v)
        // printQueue(queue);
        int cur = queue.front();
        queue.pop();
        visited[cur] = true;
        cout << cur << " ";
        for (const auto v : adj[cur]) {      // O(e)
            if (!visited[v]) {
                visited[v] = true;
                queue.push(v);
            }
        }
    }
}

void bfs_disconnected(vector<vector<int>> adj) {
    vector<bool> visited(adj.size(), false);
    for (int i = 0; i < adj.size(); i++) {
        bfs(adj, i, visited);
    }
}

// NOTE: Due to fixed vector size, this code only works when maximum value of all vertices is not greater than number of vertices 
int main() {
    int V = 5;
    vector<vector<int>> adj(V); 

    // Now add edges one by one
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 4);

    cout << "BFS starting from 0" << endl;
    bfs_disconnected(adj);

    return 0;
}