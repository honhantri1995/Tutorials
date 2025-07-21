#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <string>
using namespace std;

set<int> genPrimeNum() {
	const int MAX = 10000;
	vector<bool> isPrime(MAX, true);
	isPrime[0] = isPrime[1] = false;

	for (int i = 2; i * i < MAX; ++i) {
		if (isPrime[i]) {
			for (int j = i * i; j < MAX; j += i) {
				isPrime[j] = false;
			}
		}
	}

	set<int> primeNums;
	for (int i = 1000; i < MAX; ++i) {
		if (isPrime[i]) {
			primeNums.insert(i);
		}
	}
	return primeNums;
}

vector<int> getNeighbors(int num, const set<int>& primes) {
	vector<int> neighbors;
	string s = to_string(num);

	for (int i = 0; i < 4; ++i) {
		char original = s[i];
		for (char d = '0'; d <= '9'; ++d) {
			if (d == original) {
				continue;
			}
			s[i] = d;
			int next = stoi(s);
			if (next >= 1000 && primes.count(next)) {
				neighbors.push_back(next);
			}
		}
		s[i] = original;
	}

	// for (int n : neighbors) {
	// 	printf("%d ", n);
	// }

	return neighbors;
}

int findMinPrimePath(int start, int target, const set<int>& primes) {
	if (start == target) {
		return 0;
	}

	queue<pair<int, int>> q;
	set<int> visited;
	q.push({start, 0});
	visited.insert(start);

	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		for (const auto& neighbor : getNeighbors(p.first, primes)) {
			if (visited.count(neighbor)) {
				continue;
			}
			if (neighbor == target) {
				return p.second + 1;
			}
			visited.insert(neighbor);
			q.push({neighbor, p.second + 1});
		}
	}
	return -1;
}

int main() {
	int tcCount;
	cin >> tcCount;
	auto primes = genPrimeNum();

	for (int i = 0; i < tcCount; i++) {
		int num1, num2;
		cin >> num1;
		cin >> num2;
		int result = findMinPrimePath(num1, num2, primes);
		cout << (result == -1 ? "Impossible" : to_string(result)) << endl;
	}

	return 0;
}