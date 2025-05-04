#include <iostream>
#include <utility>
using namespace std;

std::pair<int, int> findPair(int arr[], int size, int sum) {
    std::pair<int, int> pair{-1, -1};
    int leftIdx = 0;
    int rightIdx = size - 1;
    int tmpSum = 0;
    while (leftIdx < rightIdx) {
        tmpSum = arr[leftIdx] + arr[rightIdx];
        if (tmpSum < sum) {
            leftIdx++;
        } else if (tmpSum > sum) {
            rightIdx--;
        } else {
            pair.first = arr[leftIdx];
            pair.second = arr[rightIdx];
            break;
        }
    }
    return pair;
}

int main() {
    int arr[] = {10, 20, 23, 30, 35, 40, 50};
    int sum = 75;
    auto pair = findPair(arr, sizeof(arr)/sizeof(arr[0]), sum);
    cout << pair.first << ", " << pair.second << endl;
    return 0;
}