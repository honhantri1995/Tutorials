#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
	// Get input and save to map
	int q;
	int k;
	cin >> q >> k;
	unordered_map<string, int> celebMap;
	for (int i = 0; i < q; i++) {
		string name;
		int expense;
		cin >> name;
		cin >> expense;

		// Way 1: Add an item of friend name and expense of each one to map
		//        If friend appears 2+, adding sum of expense
		// auto it = celebMap.find(name);
		// if (it == celebMap.end()) {
		// 	celebMap.emplace(name, expense);
		// } else {
		// 	celebMap[name] = expense + it->second;
		// }

		// Way 2:
		celebMap[name] += expense;

	}

	// Copy all expenses in map to a vector
	vector<int> expenses;
	expenses.reserve(celebMap.size());
	for (const auto& celeb : celebMap) {
		expenses.emplace_back(celeb.second);
	}

	// Sort the vector in descending order
	std::sort(expenses.begin(), expenses.end(), std::greater<int>());

	// Find max money to spare based on K
	int maxSpare = 0;
	for (int i = 0; i < k && i < expenses.size(); i++) {
		maxSpare += expenses[i];
	}
	cout << maxSpare << endl;

	return 0;
}