#include <iostream>
#include <string>
#include <unordered_map>

bool areAnagrams(const std::string& str1, const std::string& str2) {
    // If lengths of strings are not equal, they cannot be anagrams
    if (str1.length() != str2.length()) {
        return false;
    }

    // Create a map to store character frequencies of str1
    std::unordered_map<char, int> charFrequency;

    // Count character frequencies in str1
    for (char c : str1) {
        charFrequency[c]++;
    }

    // Iterate through str2 and decrement character frequencies in the map
    for (char c : str2) {
        // If character doesn't exist in the map or frequency becomes 0, return false
        if (charFrequency.find(c) == charFrequency.end() || charFrequency[c] == 0) {
            return false;
        }
        charFrequency[c]--;
    }

    // If all characters in str2 are accounted for in str1, return true
    return true;
}

int main() {
    std::string str1, str2;
    std::cout << "Enter the first string: ";
    std::cin >> str1;
    std::cout << "Enter the second string: ";
    std::cin >> str2;

    if (areAnagrams(str1, str2)) {
        std::cout << "The strings are anagrams." << std::endl;
    } else {
        std::cout << "The strings are not anagrams." << std::endl;
    }

    return 0;
}
