// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// /*
//                         3 1 4 1 5 9 2 6 5 3
//         3 1 4 1 5                              9 2 6 5 3
//     3 1        4 1 5
//     3 1       4     1 5
//     3 1       4    1     5
// */

// void print(vector<int> arr) {
//     for (int i = 0; i < arr.size(); i++) {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }

// vector<int> outArr = {};

// void quicksort(vector<int> inputArr, string depth) {         // O(logn)
//     printf("%sCall sort\n", depth.c_str());
//     if (inputArr.size() == 1) {
//         printf("%sBase case\n", depth.c_str());
//         outArr.emplace_back(inputArr[0]);
//         print(outArr);
//         return;
//     }

//     if (inputArr.size() == 0) {
//         return;
//     }

//     vector<int> leftArr = {};
//     vector<int> rightArr = {};

//     int pivot = inputArr[inputArr.size() - 1];
//     printf("%spivot = %d\n", depth.c_str(), pivot);

//     for (auto it = inputArr.begin(); it != inputArr.end(); ++it) {
//         if (*it < pivot) {
//             printf("%sleft *it = %d\n", depth.c_str(), *it);
//             // print(leftArr);
//             leftArr.emplace_back(*it);
//         } else if (*it > pivot) {
//             printf("%sright *it = %d\n", depth.c_str(), *it);
//             // print(rightArr);
//             rightArr.emplace_back(*it);
//         }
//         //  else {
//         //     outArr.emplace_back(pivot);
//         // }
//     }

//     // if (leftArr.size() == 0) {

//     // }

//     quicksort(leftArr, depth + "  ");
//     printf("%sReturn call to sort. leftPivot = %d\n", depth.c_str(), pivot);

//     quicksort(rightArr, depth + "  ");
//     printf("%sReturn call to sort. rightPivot = %d\n", depth.c_str(), pivot);

// }

// int main() {
//     // int arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
//     // int arr[] = {7, 2, 3, 5, 6, 1, 4};
//     // int size = sizeof(arr)/sizeof(arr[0]);
//     // int startIdx = 0;
//     // int endIdx = size - 1;
//     // int pivot = arr[size-1];

//     // vector<int> arr = {7, 2, 3, 5, 6, 1, 4};
//     vector<int> inputArr = {1, 8, 3, 9, 4, 5, 7};

//     quicksort(inputArr, "");
//     print(outArr);
//     return 0;
// }