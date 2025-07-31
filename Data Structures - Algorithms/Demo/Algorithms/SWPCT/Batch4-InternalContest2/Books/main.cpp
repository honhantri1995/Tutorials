#include <iostream>
#include <vector>
using namespace std;

int main() {
	unsigned int n, t;
	cin >> n >> t;
	vector<unsigned int> a(n);
	for (unsigned int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	unsigned int left = 0;
	unsigned int right = 0;
	unsigned int sum = 0;
	unsigned int maxBookCount = 0;

	while (right < n) {
		sum += a[right];
		while (sum > t) {
			sum -= a[left];
			++left;
		}
		maxBookCount = max(maxBookCount, right - left + 1);
		++right;
	}

	cout << maxBookCount << endl;
	return 0;
}