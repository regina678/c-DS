#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

int main() {
    std::stack<int> myStack;
    myStack.push(5);
    myStack.push(2);
    myStack.push(7);
    myStack.push(1);
    myStack.push(9);

    std::vector<int> tempVector;
    while (!myStack.empty()) {
        tempVector.push_back(myStack.top());
        myStack.pop();
    }

    std::sort(tempVector.begin(), tempVector.end());

    for (int i = tempVector.size() - 1; i >= 0; --i) {
        myStack.push(tempVector[i]);
    }

    std::cout << "Sorted stack: ";
    while (!myStack.empty()) {
        std::cout << myStack.top() << " ";
        myStack.pop();
    }
    std::cout << std::endl;

    return 0;
}
