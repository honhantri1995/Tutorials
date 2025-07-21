#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

bool isValidLayout(const string& s, string& layout) {
	unordered_map<char, unordered_set<char>> adj;
	vector<bool> visited(26, false);

	for (int i = 0; i + 1 < s.size(); ++i) {
		char a = s[i], b = s[i + 1];
		adj[a].insert(b);
		adj[b].insert(a);
	}

	for (auto& [ch, neighbors] : adj) {
		if (neighbors.size() > 2) {
			return false;
		}
	}

	for (char start = 'a'; start <= 'z'; ++start) {
		if (!visited[start - 'a'] && adj[start].size() <= 1) {
			queue<char> q;
			q.push(start);

			while (!q.empty()) {
				char u = q.front(); q.pop();
				if (visited[u - 'a']) {
					continue;
				}
				visited[u - 'a'] = true;
				layout.push_back(u);

				for (char v : adj[u]) {
					if (!visited[v - 'a']) {
						q.push(v);
					}
				}
			}
		}
	}

	for (auto& [ch, _] : adj) {
		if (!visited[ch - 'a']) {
			return false;
		}
	}

	for (char ch = 'a'; ch <= 'z'; ++ch) {
		if (!visited[ch - 'a']) {
			layout.push_back(ch);
		}
	}

	return true;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		string layout = "";

		if (isValidLayout(s, layout)) {
			cout << "YES\n" << layout << '\n';
		} else {
			cout << "NO\n";
		}
	}

	return 0;
}