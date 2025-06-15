#include <iostream>
using namespace std;

// A function to perform binary search on a sorted array
int BinarySearch(int arr[], int size, int target) {
    // Initialize the left and right pointers
    int left = 0;
    int right = size - 1;

    // Loop until the left pointer is less than or equal to the right pointer
    while (left <= right) {
        // Find the middle index
        int mid = (left + right) / 2;

        // Check if the target is equal to the middle element
        if (target == arr[mid]) {
        // Return the index of the element
        return mid;
        }
        // If the target is less than the middle element, move the right pointer to the left of the middle
        else if (target < arr[mid]) {
        right = mid - 1;
        }
        // If the target is greater than the middle element, move the left pointer to the right of the middle
        else {
        left = mid + 1;
        }
    }

    // Return -1 if the element is not found
    return -1;
}

int main() {
    // Declare an array of any size and sort it in ascending order
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Declare a target element to search for
    int target = 23;

    // Call the BinarySearch function and store the result
    int result = BinarySearch(arr, size, target);

    // Display a message based on the result
    if (result == -1) {
        cout << "Element not found" << endl;
    }
    else {
        cout << "Element found at index " << result << endl;
    }

    return 0;
}
