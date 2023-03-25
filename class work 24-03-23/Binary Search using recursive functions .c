#include <stdio.h>

// Function to perform binary search recursively
int binarySearch(int arr[], int left, int right, int key) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        // If the element is present at the middle
        if (arr[mid] == key)
            return mid;

        // If the element is smaller than mid, then it can only be present in left subarray
        if (arr[mid] > key)
            return binarySearch(arr, left, mid - 1, key);

        // Else the element can only be present in right subarray
        return binarySearch(arr, mid + 1, right, key);
    }

    // Element is not present in array
    return -1;
}

int main() {
    int arr[] = { 2, 5, 8, 12, 16, 23, 38, 56, 72, 91 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 16;
    int index = binarySearch(arr, 0, n - 1, key);
    if (index != -1)
        printf("Element %d is present at index %d", key, index);
    else
        printf("Element %d is not present in the array", key);
    return 0;
}
