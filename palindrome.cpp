#include <iostream>
#include <string>
#include <cctype>

bool isPalindrome(const std::string& str) {
    // Initialize two pointers, one pointing to the start of the string and one to the end
    int i = 0;
    int j = str.length() - 1;

    while (i < j) {
        // Ignore non-alphanumeric characters from both ends
        while (i < j && !std::isalnum(str[i])) {
            i++;
        }
        while (i < j && !std::isalnum(str[j])) {
            j--;
        }
        // If characters at both pointers are not equal, return false
        if (std::tolower(str[i]) != std::tolower(str[j])) {
            return false;
        }
        // Move pointers towards each other
        i++;
        j--;
    }
    // If all characters are checked and found to be equal, return true
    return true;
}

int main() {
    std::string str;
    std::cout << "Enter a string: ";
    std::getline(std::cin, str);

    if (isPalindrome(str)) {
        std::cout << "The string is a palindrome." << std::endl;
    } else {
        std::cout << "The string is not a palindrome." << std::endl;
    }

    return 0;
}
