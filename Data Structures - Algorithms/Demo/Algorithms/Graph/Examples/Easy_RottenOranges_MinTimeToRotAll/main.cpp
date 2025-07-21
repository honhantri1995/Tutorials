#include <queue>
#include <vector>
#include <utility>
#include <iostream>
using namespace std;

void initQueueWithAllRottenNode(const vector<vector<int>>& matrix, queue<pair<int, int>>& q) {		// O(N^2) or O(M^2)
	for (int i=0; i < matrix.size(); i++) {
		for (int j=0; j < matrix[0].size(); j++) {
			if (matrix[i][j] == 2) {
				q.push({i, j});
			}
		}
	}
}

bool isAnyRemainingFreshNode(const vector<vector<int>>& matrix) {		// O(N^2) or O(M^2) in worst case
	for (int i=0; i < matrix.size(); i++) {
		for (int j=0; j < matrix[0].size(); j++) {
			if (matrix[i][j] == 1) {
				return true;
			}
		}
	}
	return false;
}

const vector<pair<int, int>> DIRECTIONS = {
	{1, 0},	{0, 1},	{-1, 0}, {0, -1},
};

bool isValidRange(pair<int, int> pos, int rowSize, int columnSize) {
	return ((pos.first >= 0) && (pos.second >= 0) && (pos.first < rowSize) && (pos.second < columnSize));
}

void printMatrix(const vector<vector<int>>& matrix) {
	for (const auto& row : matrix) {
		for (const auto& col : row) {
			printf("%d ", col);
		}
		printf("\n");
	}
}

int bfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int rowSize, int columnSize) {		// O(NxM)
	queue<pair<int, int>> q;
	int minTime = -2;	// Ignore the first iteration (always rotten nodes) and the last iteration (no more fresh nodes)

	// Because this problem is about finding the minimum time required, we will not choose a random rotten node.
	// Instead, we use all rotten nodes from the beginning.
	initQueueWithAllRottenNode(matrix, q);

	while (!q.empty()) {
		int queueSize = q.size();

		while (queueSize > 0) {		// We don't need this loop for graph traversal, but we need it to count the minimal time required
			pair<int, int> nodeIdx = q.front();
			int& nodeValue = matrix[nodeIdx.first][nodeIdx.second];

			q.pop();
			queueSize--;

			printf("Any node[%d][%d] = %d\n", nodeIdx.first, nodeIdx.second, nodeValue);
			printMatrix(matrix);

			printf("Queue size: %d\n", q.size());
			if (!visited[nodeIdx.first][nodeIdx.second]) {
				visited[nodeIdx.first][nodeIdx.second] = true;

				if (nodeValue == 1) {
					printf("Not-visisted node[%d][%d] = %d\n", nodeIdx.first, nodeIdx.second, nodeValue);
					nodeValue = 2;
				}
				if (nodeValue == 2) {
					for (const auto& dir : DIRECTIONS) {
						pair<int, int> adjNodeIdx{nodeIdx.first + dir.first, nodeIdx.second + dir.second};
						if (isValidRange(adjNodeIdx, rowSize, columnSize) && !visited[adjNodeIdx.first][adjNodeIdx.second]) {
							printf("Adj node[%d][%d] = %d\n", adjNodeIdx.first, adjNodeIdx.second, matrix[adjNodeIdx.first][adjNodeIdx.second]);
							q.push(adjNodeIdx);
						}
					}
				}
			}
		}

		minTime++;
		printf("Min time: %d\n\n", minTime);
	}

	if (isAnyRemainingFreshNode(matrix)) {
		minTime = -1;
	}

	return minTime;
}

int main() {
	vector<vector<int>> matrix = {
		{2, 1, 0, 2, 1},
		{1, 0, 1, 2, 1},
		{1, 0, 0, 2, 1}
	};

	// vector<vector<int>> matrix = {
	// 	{2, 1, 0, 2, 1},
	// 	{0, 0, 1, 2, 1},
	// 	{1, 0, 0, 2, 1}
	// };

	int rowSize = matrix.size();
	int columnSize = matrix[0].size();

	vector<bool> temp(columnSize, false);
	vector<vector<bool>> visited(rowSize, temp);

	int minTime = bfs(matrix, visited, rowSize, columnSize);
	printMatrix(matrix);
	printf("Min time: %d\n", minTime);

	return 0;
}
