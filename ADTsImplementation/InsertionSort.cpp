#include <iostream>
void InsertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {    // The outer loop starts from the second element while the inner loop starts from the first
        int key = arr[i];            // This is the element to be inserted in the sort
        int j = i - 1;               // j is the current index that is right behind i

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];     // Shifts element to the right
            j--;
        }
        arr[j + 1] = key;            // Insert the key element in correct space
    }   
}
void PrintList(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
int main() {

    int arr[] = {500, 53, 12, 5, 23, 11, 599, 900, 485, 4, 44, 56};
    int n = sizeof(arr) / sizeof(arr[0]);

    PrintList(arr, n);
    InsertionSort(arr, n);
    PrintList(arr, n);

    return 0;
}