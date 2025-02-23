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

void print(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// This is Bubble Sort, it takes O(n^2)
// So the total time complexity for the whole program is O(n^2 logn)
// This is considerably worse than a standard merge sort which operates in O(n logn)
void sort(int arr[], int startIdx, int endIdx) {        // O(n^2)
    while (1) {
        bool found = false;
        for (int i = startIdx; i <= endIdx; i++) {
            if ((i < endIdx) && (arr[i] > arr[i+1])) {
                std::swap(arr[i], arr[i+1]);
                found = true;
            }
        }
        if (!found) {
            break;
        }
    }
}

void mergesort(int arr[], int startIdx, int endIdx, string depth) {         // O(logn)
    printf("%sCall sort(%d, %d)\n", depth.c_str(), startIdx, endIdx);
    if (startIdx == endIdx) {
        printf("%sBase case, %d %d\n", depth.c_str(), arr[startIdx], arr[endIdx+1]);

        // Optional
        if (arr[startIdx] > arr[endIdx+1]) {
            std::swap(arr[startIdx], arr[endIdx+1]);
        }
        return;
    }
    int midIdx = (endIdx + startIdx)/2;

    mergesort(arr, startIdx, midIdx, depth + " ");
    printf("%sReturn call to sort(%d, %d)\n", depth.c_str(), startIdx, endIdx);

    mergesort(arr, midIdx + 1, endIdx, depth + " ");
    printf("%sReturn call to sort(%d, %d)\n", depth.c_str(), startIdx, endIdx);

    sort(arr, startIdx, endIdx);
}

int main() {
    int arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    // int arr[] = {7, 2, 3, 5, 6, 1, 4};
    int size = sizeof(arr)/sizeof(arr[0]);
    int startIdx = 0;
    int endIdx = size - 1;
    mergesort(arr, startIdx, endIdx, "");
    print(arr, size);
    return 0;
}