#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Perform DFS from given source using iteration
void dfs(const vector<vector<int>> adjs, int source, vector<bool>& visited, vector<int>& result) {	// source is starting node
    stack<int> s;
    s.push(source);

    while (!s.empty()) {
        int current = s.top();
        s.pop();

        if (!visited[current]) {
            visited[current] = true;
            result.emplace_back(current);

            vector<int> adj = adjs[current];
            for (int i = adj.size() - 1; i >= 0; --i) {     // backward
                int neightbor = adj[i];
                if (!visited[neightbor]) {
                    s.push(neightbor);
                }
            }
        }
    }
}

// Perform DFS for the entire graph which maybe disconnected
void dfsDisconnected(const vector<vector<int>> adjs, vector<int>& result) {
    vector<bool> visited(adjs.size(), false);
    for (int node = 0; node < adjs.size(); node++) {
        dfs(adjs, node, visited, result);
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
    };      // Result: 0 1 2 4 3

    // vector<vector<int>> adjs{
    //     {1, 2},
    //     {0, 2},
    //     {0, 1, 3, 4},
    //     {2},
    //     {2},
    // };      // Result: 0 1 2 3 4

    vector<int> result;
    dfsDisconnected(adjs, result);
    printResult(result);
    return 0;
}
