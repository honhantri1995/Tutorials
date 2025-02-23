#include <iostream>
#include <vector>
using namespace std;

// s[0] = 0
// s[1] = 1
// s[2] = s[1] + s[0] = 0 + 1 = 1
// s[3] = s[2] + s[1] = 1 + 1 = 2
// s[4] = s[3] + s[2] = 2 + 1 = 3
int fibo(int n) {
    vector<int> sequence = {};
    sequence.emplace_back(0);
    sequence.emplace_back(1);

    int result = 0;
    for (int idx = 2; idx <= n; idx++) {
        sequence.emplace_back(sequence[idx - 1] + sequence[idx - 2]);
        result = sequence[idx];
    }
    return result;
}


int main() {
    int n = 6;
    int fibo_num = fibo(n);
    printf("%dth number in Fibo sequence: %d\n", n, fibo_num);
    return 0;
}
