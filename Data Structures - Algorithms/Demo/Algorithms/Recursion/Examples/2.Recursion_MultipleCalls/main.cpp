#include <iostream>
using namespace std;

void fn(int n) {
    if (n > 2) {
        fn(n - 1);
        fn(n - 2);
        fn(n - 3);
    }

    cout << n << " ";
}

int main() {
    fn(5);
    return 0;
}
