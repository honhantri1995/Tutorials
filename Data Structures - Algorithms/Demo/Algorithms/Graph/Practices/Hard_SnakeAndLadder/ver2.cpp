#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

void printQueue(const queue<vector<int>>& queue) {
	auto tmpQueue = queue;
	while (!tmpQueue.empty()) {
		printf("{%d, %d} ", tmpQueue.front()[0], tmpQueue.front()[1]);
		tmpQueue.pop();
	}
}

int bfs(const vector<int> source, const vector<int> dest,
		const vector<int>& teleports,
		vector<bool>& visited
) {
	int diceThrowCount = 0;
	queue<vector<int>> queue;
	queue.push(source);

	while (!queue.empty()) {
		int queueSize = queue.size();
		while (queueSize > 0) {
			vector<int> item = queue.front();
			int node = item[0];
			int neighbor = item[1];
			cout << "Visiting node: " << node << endl;
			queue.pop();
			queueSize--;

			if (!visited[neighbor]) {
				visited[neighbor] = true;
				for (int dice = 6; dice > 0; dice--) {
					neighbor = node + dice;
					if (neighbor > dest[0]) {
						return diceThrowCount + 1;
					}
					if (teleports[neighbor] != -1) {	// If current node is base of any ladder or mount of any snake, then teleport
						cout << "\tTeleport from " << neighbor << " to " << teleports[neighbor] << endl;
						neighbor = teleports[neighbor];
					}
					// if (!visited[node]) {
						queue.push({node, neighbor});
						cout << "\t\tPush node: {" << node << ", " << neighbor << "}" << ". Queue: "; printQueue(queue); cout << endl;
					// }
				}
			}
		}
		diceThrowCount++;
		cout << "Increase dice throw count: " << diceThrowCount << endl;
	}
	return diceThrowCount;
}

int main() {
	vector<int> source = {1, -1}; 
	vector<int> dest = {30, -1};
	int boardSize = 30;
	vector<int> teleports(boardSize, -1);
	teleports[3]  = 22;		// base and top of ladder
	teleports[5]  = 8;
	teleports[11] = 26;
	teleports[20] = 29;

	teleports[27] = 1;		// mout and tail of snake
	teleports[17] = 4;
	teleports[21] = 9;
	teleports[19] = 8;

	// int source = 3; int dest = 30; int boardSize = 30;
	// vector<pair<int, int>> teleports = {
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
	// vector<pair<int, int>> teleports = {
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

	vector<bool> visited(boardSize, false);
	cout << bfs(source, dest, teleports, visited) << endl;
	return 0;
}