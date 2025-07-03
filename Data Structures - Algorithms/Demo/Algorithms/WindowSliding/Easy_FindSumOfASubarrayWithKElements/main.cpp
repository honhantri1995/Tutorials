#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMaxSum(vector<int> vec, int k) {
    int curSum = 0;
    int maxSum = 0;

    if (vec.size() < k) {
        return -1;
    }

    for (int i = 0; i < k; i++) {
        curSum += vec[i];
    }
    maxSum = curSum;
    for (int i = 1; i < vec.size()-k+1; i++) {
        curSum = curSum - vec[i-1] + vec[i+k-1];
        maxSum = max(maxSum, curSum);
    }
    return maxSum;
}

int main() {
    // vector<int> vec = {5, 2, -1, 0, 3};
    // int k = 3;

    // vector<int> vec = {100, 200, 300, 400};
    // int k = 2;

    // vector<int> vec = {1, 4, 2, 10, 23, 3, 1, 0, 20};
    // int k = 4;

    vector<int> vec = {2, 3};
    int k = 3;

    int maxSum = findMaxSum(vec, k);
    cout << maxSum << endl;
    return 0;
}