#include <iostream>
#include <list>

int main() {
    std::list<int> myList = {5, 2, 7, 1, 9};
    myList.sort();

    std::cout << "Sorted list: ";
    for (const auto& elem : myList) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
