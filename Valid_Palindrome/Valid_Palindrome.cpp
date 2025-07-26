#include <iostream> // For input/output operations (cout, cin)
#include <string>   // For using std::string
#include <algorithm> // For std::tolower (though isalnum doesn't need it)
#include <cctype>   // For isalnum and tolower

class Solution {
public:
    bool isPalindrome(std::string s) {
        int l = 0;
        int r = s.length() - 1;
        while (l < r) {
            while (l < r && !std::isalnum(s[l])) {
                ++l;
            }
            while (l < r && !std::isalnum(s[r])) {
                --r;
            }

            if (l < r && std::tolower(s[l]) != std::tolower(s[r])) {
                return false;
            }

            ++l;
            --r;
        }
        return true; // Corrected: original had 'True' which is Pythonic
    }
};

int main() {
    Solution sol;

    // Test cases
    std::cout << "Test 1: \"A man, a plan, a canal: Panama\"" << std::endl;
    std::cout << "Is palindrome: " << (sol.isPalindrome("A man, a plan, a canal: Panama") ? "true" : "false") << std::endl; // Expected: true

    std::cout << "\nTest 2: \"race a car\"" << std::endl;
    std::cout << "Is palindrome: " << (sol.isPalindrome("race a car") ? "true" : "false") << std::endl; // Expected: false

    std::cout << "\nTest 3: \" \"" << std::endl;
    std::cout << "Is palindrome: " << (sol.isPalindrome(" ") ? "true" : "false") << std::endl; // Expected: true

    std::cout << "\nTest 4: \"0P\"" << std::endl;
    std::cout << "Is palindrome: " << (sol.isPalindrome("0P") ? "true" : "false") << std::endl; // Expected: false

    return 0;
}