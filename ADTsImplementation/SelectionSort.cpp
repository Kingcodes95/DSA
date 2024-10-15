#include <iostream>
void SelectionSort(int arr[], int n) {
    // Loop over each element in the array
    for (int i = 0; i < n - 1; i++) {
        // Assume the current index is the minimum
        int minIndex = i;

        // In the inner loop Find the minimum element in the unsorted portion
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            std::swap(arr[i], arr[minIndex]);
        }
    }
}
void printList(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
int main() {

    int arr[] = {5, 20, 99, 18, 21, 21, 56, 93, 100, 399};
    int n = sizeof(arr) / sizeof(arr[0]);

    printList(arr, n);
    SelectionSort(arr, n);
    printList(arr, n);

    return 0;
}