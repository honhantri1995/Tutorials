#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

const vector<pair<int, int>> DIRECTIONS = {
	{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}
};

bool bfs(vector<vector<char>>& matrix, pair<int, int> sourceIdx, int rowSize, int colSize) {
	queue<pair<int, int>> q;
	q.push(sourceIdx);
	bool foundIsland = false;

	while (!q.empty()) {
		pair<int, int> node = q.front();
		q.pop();
		// printf("Source node: [%d][%d]\n", node.first, node.second);

		if (matrix[node.first][node.second] == 'L') {
			matrix[node.first][node.second] = 'W';		// Differ from ver1: Instead of using 'visited', just change node value from L to W. And we can save space.
			foundIsland = true;

			for (const auto& DIR : DIRECTIONS) {
				pair<int, int> adjNode = {node.first + DIR.first, node.second + DIR.second};
				if ((adjNode.first >= 0) && (adjNode.second >= 0) && (adjNode.first < rowSize) && (adjNode.second < colSize)) {
					if (matrix[adjNode.first][adjNode.second] == 'L') {
						// printf("Ajd node: [%d][%d]\n", adjNode.first, adjNode.second);
						q.push(adjNode);
					}
				}
			}
		}
	}
	return foundIsland;
}

int main() {
	vector<vector<char>> matrix = {
		{'L', 'L', 'W', 'W', 'W'},
		{'W', 'L', 'W', 'W', 'L'},
		{'L', 'W', 'W', 'L', 'L'},
		{'W', 'W', 'W', 'W', 'W'},
		{'L', 'W', 'L', 'L', 'W'}
	};

	// vector<vector<char>> matrix = {
	// 	{'W', 'L', 'L', 'L', 'W', 'W', 'W'},
	// 	{'W', 'W', 'L', 'L', 'W', 'L', 'W'},
	// };

	// vector<vector<char>> matrix = {
	// 	{'W', 'W'},
	// 	{'W', 'W'},
	// };

	int rowSize = matrix.size();
	int colSize = matrix[0].size();
	int islandCount = 0;

	for (int rowIdx = 0; rowIdx < rowSize; rowIdx++) {
		for (int colIdx = 0; colIdx < colSize; colIdx++) {
			const auto value = matrix[rowIdx][colIdx];
			if (value == 'L') {
				bfs(matrix, {rowIdx, colIdx}, rowSize, colSize);
				islandCount++;
			}
		}
	}
	cout << islandCount << endl;
	return 0;
}
