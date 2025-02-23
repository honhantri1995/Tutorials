#include <iostream>
using namespace std;

int fibo(int n, string depth) {         // On(2^n)
    printf("%sCall fibo(%d)\n", depth.c_str(), n);
    if (n < 0) {
        printf("%sBase case\n", depth.c_str());
        return -1;
    } else if (n == 0) {
        printf("%sBase case\n", depth.c_str());
        return 0;
    } else if (n == 1) {
        printf("%sBase case\n", depth.c_str());
        return 1;
    }
    int result = fibo(n - 1, depth + "  ") + fibo(n - 2, depth + "  ");
    printf("%sReturn call to fibo(%d)\n", depth.c_str(), n);
    printf("%sReturn value: fibo(%d) + fibo(%d) = %d\n", depth.c_str(), n - 1, n - 2, result);
    return result;
}

int main() {
    int n = 6;
    int fibo_num = fibo(n, "");
    printf("%dth number in Fibo sequence: %d\n", n, fibo_num);
    return 0;
}
