#include <iostream>
using namespace std;

/*
    Use Recursion
        fac(5): 5 x fac(4)
        fac(4): 4 x fac(3)
        fac(3): 3 x fac(2)
        fac(2): 2 x fac(1)
        fac(1): 1 x fac(0) = 1 x 1
*/

int fac(int n) {
    if (n < 0) {
        return -1;
    } else if (n == 0) {
        return 1;
    } else {
        return n * fac(n - 1);
    }
}

int main() {
    int n = 4;
    int result = fac(n);
    cout << result << endl;
    return 0;
}
