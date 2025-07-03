#include <iostream>
#include <vector>
using namespace std;

int trapWater(std::vector<int> arr, int l, int r) {
    int lmax = arr[l];
    int rmax = arr[r];
    int sum = 0;

    while (l < r) {
        if (lmax <= rmax) {
            l += 1;
            if (arr[l] > lmax) {
                lmax = arr[l];
            } else {
                sum += min(lmax, rmax) - arr[l];
            }
        } else {
            r -= 1;
            if (arr[r] > rmax) {
                rmax = arr[r];
            } else {
                sum += min(lmax, rmax) - arr[r];
            }
        }
    }

    return sum;
}

int main() {
    std::vector<std::vector<int>> vecs = {
        {2, 1, 0, 3, 2, 1, 4, 2, 3},    // output: 7
        {3, 0, 2, 0, 4},                // output: 7
        {4, 0, 3, 0, 1, 2},             // output: 6
        {4, 0, 5, 3, 0, 1, 2},          // output: 7
        {1, 2, 3}                       // output: 0
    };

    for (const auto& vec : vecs) {
        int left = 0;
        int right = vec.size() - 1;
        int trappedWater = trapWater(vec, left, right);
        cout << trappedWater << endl;
    }
    return 0;
}