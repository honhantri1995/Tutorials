#include <iostream>
using namespace std;

// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(int array[], int left, int mid, int right)
{
	int subLeftArrLength = mid - left + 1;
	int subRightArrLength = right - mid;

	// Create temp arrays
	int* leftArr = new int[subLeftArrLength];
	int* rightArr = new int[subRightArrLength];

	// Copy data to temp arrays
	for (int i = 0; i < subLeftArrLength; i++)
		leftArr[i] = array[left + i];
	for (int j = 0; j < subRightArrLength; j++)
		rightArr[j] = array[mid + 1 + j];

	int subArr1Idx = 0;
	int subArr2Idx = 0;
	int mergedArrIdx = left;

	// Sort and merge the temp arrays back into array
	while (subArr1Idx < subLeftArrLength && subArr2Idx < subRightArrLength) {
		if (leftArr[subArr1Idx] <= rightArr[subArr2Idx]) {
			array[mergedArrIdx] = leftArr[subArr1Idx];
			subArr1Idx++;
		}
		else {
			array[mergedArrIdx] = rightArr[subArr2Idx];
			subArr2Idx++;
		}
		mergedArrIdx++;
	}

	// Copy the remaining elements of left[], if there are any
	while (subArr1Idx < subLeftArrLength) {
		array[mergedArrIdx] = leftArr[subArr1Idx];
		subArr1Idx++;
		mergedArrIdx++;
	}

	// Copy the remaining elements of right[], if there are any
	while (subArr2Idx < subRightArrLength) {
		array[mergedArrIdx] = rightArr[subArr2Idx];
		subArr2Idx++;
		mergedArrIdx++;
	}
	delete[] leftArr;
	delete[] rightArr;
}

void mergeSort(int array[], int left, int right)
{
	if (left >= right)
		return;

	// calculate the middle index of the array being divided
	//  (right - left): length of the subarray
	//  ((right - left) / 2): middle index within this subarray
	int mid = left + ((right - left) / 2);

	mergeSort(array, left, mid);
	mergeSort(array, mid + 1, right);
	merge(array, left, mid, right);
}

void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
}

int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);

	mergeSort(arr, 0, n - 1);

	cout << "Sorted array is:\n";
	printArray(arr, n);
	return 0;
}
