#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Perform BFS from given source
void bfs(const vector<vector<int>> adjs, int source, vector<bool>& visited, vector<int>& result) {	// source is starting node
    queue<int> q;
    q.push(source);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (!visited[current]) {
            visited[current] = true;
            result.emplace_back(current);

            vector<int> adj = adjs[current];
            for (const auto neightbor : adj) {       // forward
                if (!visited[neightbor]) {
                    q.push(neightbor);
                }
            }
        }

    }
}

// Perform BFS for the entire graph which maybe disconnected
void bfsDisconnected(const vector<vector<int>> adjs, vector<int>& result) {
    vector<bool> visited(adjs.size(), false);
    for (int node = 0; node < adjs.size(); node++) {
        bfs(adjs, node, visited, result);
    }
}

void printResult(const vector<int>& result) {
    for (const auto& node: result) {
        printf("%d ", node);
    }
}

int main() {
    // Assume index of the outter vector equals to node value
    vector<vector<int>> adjs{
        {1, 2},     // Meaning node 0 is connected with node 1 and node 2
        {0, 2, 3},  // Meaning node 1 is connected with node 0, node 2 and node 3
        {0, 1, 4},
        {1, 4},
        {2, 3},
    };      // Result: 0 1 2 3 4


    // vector<vector<int>> adjs{
    //     {1, 2},
    //     {0, 2},
    //     {0, 1, 3, 4},
    //     {2},
    //     {2},
    // };      // Result: 0 1 2 3 4

    vector<int> result;
    bfsDisconnected(adjs, result);
    printResult(result);
    return 0;
}