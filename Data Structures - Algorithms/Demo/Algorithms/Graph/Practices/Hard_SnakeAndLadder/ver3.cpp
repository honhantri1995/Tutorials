#include <iostream>
#include <vector>
#include <map>
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

int bfs(const int boardSize, const int source, const int dest,
		const vector<int>& teleports,
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

			if (!visited[node]) {
				visited[node] = true;
				for (int dice = 6; dice > 0; dice--) {
					int newNode = node + dice;
					if (newNode > boardSize) {
						return diceThrowCount + 1;
					}
					// If current node is base of any ladder or mount of any snake, then teleport
					if (teleports[newNode] != -1) {
						cout << "\tTeleport from " << newNode << " to " << teleports[newNode] << endl;
						newNode = teleports[newNode];
						// diceThrowCount--;
					}
					if (!visited[newNode]) {
						queue.push(newNode);
						cout << "\tPush node: " << newNode << ". Queue: "; printQueue(queue); cout << endl;
					}
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
	// vector<int> teleports(boardSize, -1);
	// teleports[3] = 22;	// base and top of ladder
	// teleports[5] = 8;
	// teleports[11] = 26;
	// teleports[20] = 29;
	// teleports[1] = 27;	// mout and tail of snake
	// teleports[4] = 17;
	// teleports[9] = 21;
	// teleports[8] = 19;

	// int source = 1; int dest = 30; int boardSize = 30;
	// vector<int> teleports(boardSize, -1);
	// teleports[3] = 22;	// base and top of ladder
	// teleports[5] = 8;
	// teleports[11] = 26;
	// teleports[20] = 29;
	// teleports[1] = 22;	// mout and tail of snake
	// teleports[4] = 17;
	// teleports[9] = 26;
	// teleports[8] = 19;

	vector<int> visited(boardSize, false);
	cout << bfs(boardSize, source, dest, teleports, visited) << endl;
	return 0;
}