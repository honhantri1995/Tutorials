#include <iostream>
#include <algorithm>
using namespace std;

int findCoinCount(int arr[], int size, int change) {
    int count = 0;
    int curChange = change;
    for (int i = 0; i < size; i++) {
        if (curChange == 0) {
            break;
        } else if (curChange < 0) {
            cout << "FAIL" << endl;
            break;
        }
        int curMax = arr[i];

        while (curChange >= curMax) {
            count++;
            curChange -= curMax;
        }
    }
    return count;
}

int main() {
    int arr[] = {1, 2, 5, 10};
    int change = 39;
    // int arr[] = {18, 1, 10};
    // int change = 20;

    int size = sizeof(arr)/sizeof(arr[0]);
    std::sort(arr, arr + size, std::greater<int>());
    int count = findCoinCount(arr, size, change);
    cout << "Max coin for change " << change << " is " << count << endl;
    return 0;
}