#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int maxTeams(const vector<int>& weights) {
	unordered_map<int, int> freq;
	for (int w : weights) {
		freq[w]++;
	}

	int max_teams = 0;

	for (int sum = 2; sum <= 200; ++sum) {
		int teams = 0;
		for (int i = 1; i <= sum / 2; ++i) {
			int j = sum - i;
			if (i == j) {
				teams += freq[i] / 2;
			} else {
				teams += min(freq[i], freq[j]);
			}
		}
		max_teams = max(max_teams, teams);
	}

	return max_teams;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<int> weights(N);
		for (int i = 0; i < N; ++i)
			cin >> weights[i];
		cout << maxTeams(weights) << endl;
	}
	return 0;
}