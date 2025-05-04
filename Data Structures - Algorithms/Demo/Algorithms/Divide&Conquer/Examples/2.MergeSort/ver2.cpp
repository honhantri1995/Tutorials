#include <iostream>
#include <vector>
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

// This function resolves subproblems and merge them. It takes O(n)
// So the total time complexity for the whole program is O(n logn)
void sort(int arr[], int midIdx, int startIdx, int endIdx) {        // O(n)
    int n1 = midIdx - startIdx + 1;
    int n2 = endIdx - midIdx;

    // Create temp vectors
    vector<int> L(n1), R(n2);

    // Copy data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[startIdx + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[midIdx + 1 + j];

    int i = 0, j = 0;
    int k = startIdx;

    // Merge the temp vectors back into arr[startIdx..endIdx]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int arr[], int startIdx, int endIdx, string depth) {         // O(logn)
    printf("%sCall sort(%d, %d)\n", depth.c_str(), startIdx, endIdx);
    if (startIdx == endIdx) {
        printf("%sBase case\n", depth.c_str());
        return;
    }
    int midIdx = (endIdx + startIdx)/2;

    mergesort(arr, startIdx, midIdx, depth + " ");
    printf("%sReturn call to sort(%d, %d)\n", depth.c_str(), startIdx, endIdx);

    mergesort(arr, midIdx + 1, endIdx, depth + " ");
    printf("%sReturn call to sort(%d, %d)\n", depth.c_str(), startIdx, endIdx);

    sort(arr, midIdx, startIdx, endIdx);
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