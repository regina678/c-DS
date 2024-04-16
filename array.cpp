#include <iostream>
#include <algorithm>

int main() {
    int arr[] = {5, 2, 7, 1, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::sort(arr, arr + n);

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
