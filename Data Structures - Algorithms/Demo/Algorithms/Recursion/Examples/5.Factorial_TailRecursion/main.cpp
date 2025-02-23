#include <iostream>
using namespace std;

// A tail recursive function to calculate factorial
unsigned fac(unsigned int n, unsigned int a) {
    if (n <= 1) {
        return a;
    }

    return fac(n - 1, n * a);
}

// A wrapper over fac
unsigned int factorial(unsigned int n) {
    return fac(n, 1);
}

int main() {
    cout << factorial(5);
    return 0;
}
