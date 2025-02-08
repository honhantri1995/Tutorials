#include <iostream>
using namespace std;

void func(int n) {
	if (n > 2) {
		func(n - 1);
		func(n - 2);
		func(n - 3);
	}

	cout << n << endl;
}

int main() {
	func(5);
	return 0;
}
