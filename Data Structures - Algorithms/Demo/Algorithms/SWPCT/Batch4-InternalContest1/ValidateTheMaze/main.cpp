#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <utility>
#include <unordered_set>
using namespace std;

void printMaze(const vector<vector<char>>& maze) {
	for (int rowIdx = 0; rowIdx < maze.size(); rowIdx++) {
		for (int colIdx = 0; colIdx < maze.at(rowIdx).size(); colIdx++) {
			printf("%c ", maze.at(rowIdx).at(colIdx));
		}
		printf("\n");
	}
}

vector<pair<int, int>> findEntryPoints(const vector<vector<char>>& maze) {
	int rowCount = maze.size();
	int colCount = maze[0].size();
	vector<pair<int, int>> openings;

	vector<bool> temp(colCount, false);
	vector<vector<bool>> visited(rowCount, temp);

	// Check top and bottom rowCount
	for (int col = 0; col < colCount; ++col) {
		if (maze[0][col] == '.') {
			if (!visited[0][col]) {
				openings.emplace_back(0, col);
				visited[0][col] = true;
			}
		}
		if (maze[rowCount - 1][col] == '.') {
			if (!visited[rowCount - 1][col]) {
				openings.emplace_back(rowCount - 1, col);
				visited[rowCount - 1][col] = true;
			}
		}
	}

	// Check left and right columns (excluding already checked)
	for (int row = 1; row < rowCount - 1; ++row) {
		if (maze[row][0] == '.') {
			if (!visited[row][0]) {
				openings.emplace_back(row, 0);
				visited[row][0] = true;
			}
		}
		if (maze[row][colCount - 1] == '.') {
			if (!visited[row][colCount - 1]) {
				openings.emplace_back(row, colCount - 1);
				visited[row][colCount - 1] = true;
			}
		}
	}

	// for (const auto& node : openings) {
	// 	printf("Entry point = [%d][%d]\n", node.first, node.second);
	// }

    return openings;
}

const vector<pair<int, int>> DIRECTIONS = {
	{1, 0},	{0, 1},	{-1, 0}, {0, -1},
};

bool isValidRange(pair<int, int> pos, int rowSize, int columnSize) {
	return ((pos.first >= 0) && (pos.second >= 0) && (pos.first < rowSize) && (pos.second < columnSize));
}

bool bfs(const vector<vector<char>>& maze, const pair<int, int> sourceIdx, vector<vector<bool>>& visited, int rowSize, int columnSize, vector<pair<int, int>> entryNodes) {
	queue<pair<int, int>> nodeIdxQueue;
	nodeIdxQueue.push(sourceIdx);

	while (!nodeIdxQueue.empty()) {
		pair<int, int> nodeIdx = nodeIdxQueue.front();
		nodeIdxQueue.pop();

		if (!visited[nodeIdx.first][nodeIdx.second]) {
			visited[nodeIdx.first][nodeIdx.second] = true;

			char nodeValue = maze[nodeIdx.first][nodeIdx.second];
			if (nodeValue == '.') {
				for (int idx = 0; idx < entryNodes.size(); idx++) {	// start from second item
					auto entryNode = entryNodes[idx];
					if ((nodeIdx.first == entryNode.first && nodeIdx.second == entryNode.second)
						&& (nodeIdx.first != sourceIdx.first || nodeIdx.second != sourceIdx.second)) {
						return true;
					}
				}

				for (const auto& dir : DIRECTIONS) {
					pair<int, int> adjNodeIdx{nodeIdx.first + dir.first, nodeIdx.second + dir.second};
					if (isValidRange(adjNodeIdx, rowSize, columnSize) && !visited[adjNodeIdx.first][adjNodeIdx.second]) {
						// printf("Adj node[%d][%d] = %c\n", adjNodeIdx.first, adjNodeIdx.second, maze[adjNodeIdx.first][adjNodeIdx.second]);
						nodeIdxQueue.push(adjNodeIdx);
					}
				}
			}
		}
	}
	return false;
}

int validateMaze(const vector<vector<char>>& maze) {
	bool validate = false;
	auto entryNodes = findEntryPoints(maze);

	if (entryNodes.size() == 2) {
		int rowCount = maze.size();
		int colCount = maze[0].size();

		vector<bool> temp(colCount, false);
		vector<vector<bool>> visited(rowCount, temp);

		for (const auto& entryNode : entryNodes) {
			if (bfs(maze, entryNode, visited, rowCount, colCount, entryNodes)) {
				validate = true;
			}
		}
	}
	return validate;
}

int main() {
	int tcCount;
	cin >> tcCount;
	for (int tcIdx = 0; tcIdx < tcCount; tcIdx++) {
		int mazeRowCount;
		int mazeColumnCount;
		cin >> mazeRowCount;
		cin >> mazeColumnCount;

		vector<vector<char>> maze;		// matrix
		for (int rowIdx = 0; rowIdx < mazeRowCount; rowIdx++) {
			string rowValue;
			cin >> rowValue;

			vector<char> rowOfMaze;
			for (int colIdx = 0; colIdx < mazeColumnCount; colIdx++) {
				rowOfMaze.push_back(rowValue.at(colIdx));
			}
			maze.push_back(rowOfMaze);
		}
		// printMaze(maze);
		if (validateMaze(maze)) {
			cout << "valid" << endl;
		} else {
			cout << "invalid" << endl;
		}
	}

	// printf("\nEND\n");
	return 0;
}