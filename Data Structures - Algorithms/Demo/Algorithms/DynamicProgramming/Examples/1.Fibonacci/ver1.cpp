#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int fibo(int n, vector<pair<int, int>>& dupItems, string depth) {       // O(n)
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

    for (const auto item : dupItems) {
        if (item.first == n) {
            printf("%sDuplicate: %d\n", depth.c_str(), n);
            return item.second;
        }
    }

    int result = fibo(n - 1, dupItems, depth + "  ") + fibo(n - 2, dupItems, depth + "  ");
    printf("%sReturn call to fibo(%d)\n", depth.c_str(), n);
    printf("%sReturn value: fibo(%d) + fibo(%d) = %d\n", depth.c_str(), n - 1, n - 2, result);

    dupItems.emplace_back(n, result);

    return result;
}

int main() {
    int n = 6;
    vector<pair<int, int>> dupItems = {};       // Memoization check list
    int fibo_num = fibo(n, dupItems, "");
    printf("%dth number in Fibo sequence: %d\n", n, fibo_num);
    return 0;
}
