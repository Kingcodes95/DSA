#include <iostream>

void PrintArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
void BubbleSort(int arr[], int n) {
    // Create a Bool value to say if they are swapped yet in order to move to the next value
    bool swapped;

    // Need an outer loop to hit each initial element
    for (int i = 0; i < n; i++) {

        // Inner loop to compare adjacent elements
        for (int j = 0; j < n - i - 1; j++) { // n - i - 1 ensures you don't swap the same elements twice
            if (arr[j] > arr[j + 1]) {
                // Swap if the current element is greater than the next
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // If no elements were swapped in the inner loop, the array is sorted
        if (!swapped) { break; }

    }
}
int main() {

    int arr[] = {4, 23, 56, 21, 3, 1};

    int n = sizeof(arr) / sizeof(arr[0]);

    PrintArray(arr, n);

    BubbleSort(arr, n);

    PrintArray(arr, n);

    return 0;
}