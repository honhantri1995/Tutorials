#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<vector<int>>& adjMatrix, int i, int j) {
    if (i >= adjMatrix.size() || j >= adjMatrix.size()) {
        cout << "FAIL" << endl;
        return;
    }
    adjMatrix[i][j] = 1;	// Node i is neighbor of node j
    adjMatrix[j][i] = 1;	// Node j is neighbor of node i
}

void displayMatrix(const vector<vector<int>>& adjMatrix) {
    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < adjMatrix.size(); ++i) {
        for (int j = 0; j < adjMatrix[i].size(); ++j) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int V = 4;
    vector<vector<int>> adjMatrix(V, vector<int>(V, 0));	// 0 means not neighbor, 1 means neighbor

    addEdge(adjMatrix, 0, 1);
    addEdge(adjMatrix, 0, 2);
    addEdge(adjMatrix, 1, 2);
    addEdge(adjMatrix, 2, 3);

    displayMatrix(adjMatrix);

    return 0;
}