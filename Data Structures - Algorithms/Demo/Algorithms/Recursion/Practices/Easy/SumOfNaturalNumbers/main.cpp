#include <iostream>
using namespace std;

int sum(int num) {
    if (num < 1) {
        return 0;
    }
    return num + sum(num - 1);
}

int main() {
    cout << sum(5) << endl;
    return 0;
}