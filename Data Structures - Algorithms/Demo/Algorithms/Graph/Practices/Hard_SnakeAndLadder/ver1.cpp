#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

void printQueue(const queue<int>& queue) {
	auto tmpQueue = queue;
	while (!tmpQueue.empty()) {
		printf("%d ", tmpQueue.front());
		tmpQueue.pop();
	}
}

bool findLadder(int node,
			   const vector<pair<int, int>>& ladders,
			   const vector<pair<int, int>>& snakes,
			   queue<int>& queue,
			   vector<int>& visited) {
	bool foundLadder = false;
	for (const auto& ladder : ladders) {
		if (node == ladder.first) {						// ladder base
			bool foundSnakeMount = false;
			for (const auto& snake : snakes) {
				if (ladder.second == snake.second) {	// top of ladder is snake mount
					foundSnakeMount = true;
					break;
				}
			}
			if (!foundSnakeMount && !visited[ladder.second]) {
				foundLadder = true;
				queue.push(ladder.second);		// choose top of ladder
				cout << "\t\tPush ladder item: " << ladder.second << ". Queue: "; printQueue(queue); cout << endl;
				break;
			}
		}
	}
	return foundLadder;
}

void throwDice(const int boardSize, int node,
			   const vector<pair<int, int>>& ladders,
			   const vector<pair<int, int>>& snakes,
			   queue<int>& queue,
			   vector<int>& visited) {
	int queueSize = queue.size();

	cout << "\tFinding ladder..." << endl;
	bool foundLadder = false;
	for (int dice = 6; dice > 0; dice--) {
		int newNode = node+dice;
		if (newNode <= boardSize) {
			foundLadder |= findLadder(newNode, ladders, snakes, queue, visited);
		}
	}

	if (!foundLadder) {
		cout << "\tFinding non-ladder..." << endl;
		for (int dice = 6; dice > 0; dice--) {
			int newNode = node+dice;
			if (newNode <= boardSize) {
				bool foundSnakeMount = false;
				for (const auto& snake : snakes) {
					if (newNode == snake.second) {				// snake mount
						foundSnakeMount = true;
						break;
					}
				}
				if (!foundSnakeMount && !visited[newNode]) {
					queue.push(newNode);
					cout << "\t\tPush non-ladder item: " << newNode << ". Queue: "; printQueue(queue); cout << endl;
				}
			}
		}
	}
}

int bfs(const int boardSize, const int source, const int dest,
		const vector<pair<int, int>>& ladders,
		const vector<pair<int, int>>& snakes,
		vector<int>& visited
) {
	int diceThrowCount = 0;
	queue<int> queue;
	queue.push(source);

	while (!queue.empty()) {
		int queueSize = queue.size();
		while (queueSize > 0) {
			int node = queue.front();
			cout << "Visiting node: " << node << endl;
			queue.pop();
			queueSize--;
			if (node + 6 >= dest) {
				diceThrowCount++;
				return diceThrowCount;
			}
			if (!visited[node]) {
				visited[node] = true;
				// Check if current node is base of any ladder
				// If not, have to throw dice
				if (!findLadder(node, ladders, snakes, queue, visited)) {
					throwDice(boardSize, node, ladders, snakes, queue, visited);
				} else {
					diceThrowCount--;
				}
			}
		}
		diceThrowCount++;
		cout << "Increase dice throw count: " << diceThrowCount << endl;
	}
	return diceThrowCount;
}

int main() {
	int source = 1; int dest = 30; int boardSize = 30;
	vector<pair<int, int>> ladders = {
		{3, 22},	// base and top
		{5, 8},
		{11, 26},
		{20, 29}
	};
	vector<pair<int, int>> snakes = {
		{1, 27},	// tail and mount
		{4, 17},
		{9, 21},
		{8, 19}
	};

	// int source = 3; int dest = 30; int boardSize = 30;
	// vector<pair<int, int>> ladders = {
	// 	{3, 22},	// base and top
	// 	{5, 8},
	// 	{11, 26},
	// 	{20, 29}
	// };
	// vector<pair<int, int>> snakes = {
	// 	{1, 27},	// tail and mount
	// 	{4, 17},
	// 	{9, 21},
	// 	{8, 19}
	// };

	// int source = 1; int dest = 30; int boardSize = 30;
	// vector<pair<int, int>> ladders = {
	// 	{3, 22},	// base and top
	// 	{5, 8},
	// 	{11, 26},
	// 	{20, 29}
	// };
	// vector<pair<int, int>> snakes = {
	// 	{1, 22},	// tail and mount
	// 	{4, 17},
	// 	{9, 26},
	// 	{8, 19}
	// };

	vector<int> visited(boardSize, false);
	cout << bfs(boardSize, source, dest, ladders, snakes, visited) << endl;
	return 0;
}