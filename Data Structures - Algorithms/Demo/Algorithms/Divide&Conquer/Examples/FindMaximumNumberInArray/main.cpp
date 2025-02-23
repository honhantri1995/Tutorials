#include <iostream>
#include <algorithm>
using namespace std;


/*
                        3 1 4 1 5 9 2 6 5 3
        3 1 4 1 5                              9 2 6 5 3
    3 1        4 1 5
    3 1       4     1 5
    3 1       4    1     5
*/

int findMax(int arr[], int startIdx, int endIdx, string depth) {
    printf("%sCall findMax(%d, %d)\n", depth.c_str(), startIdx, endIdx);
    if (startIdx == endIdx) {
        printf("%sBase case. Max = %d\n", depth.c_str(), arr[startIdx]);
        return arr[startIdx];
    }
    int midIdx = (endIdx + startIdx)/2;

    int leftMax = findMax(arr, startIdx, midIdx, depth + " ");
    printf("%sReturn call to findMax(%d, %d)\n", depth.c_str(), startIdx, endIdx);
    int rightMax = findMax(arr, midIdx + 1, endIdx, depth + " ");
    printf("%sReturn call to findMax(%d, %d)\n", depth.c_str(), startIdx, endIdx);

    return std::max(leftMax, rightMax);
}

int main() {
    int arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    int size = sizeof(arr)/sizeof(arr[0]);
    int startIdx = 0;
    int endIdx = size - 1;
    int max = findMax(arr, startIdx, endIdx, "");
    cout << "Max: " << max << endl;
    return 0;
}