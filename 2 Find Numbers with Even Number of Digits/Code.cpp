#include <iostream> // For input/output operations (cout, endl)
#include <vector>   // For using std::vector
#include <string>   // For std::to_string (if using that approach)
#include <algorithm> // Not strictly needed for this problem

class Solution {
public:
    int findNumbers(std::vector<int>& nums) {
        int count = 0;
        for (int i : nums) {
            // Your original logic for checking even number of digits:
            // This specifically checks for 2-digit numbers (10-99),
            // 4-digit numbers (1000-9999), or the single 6-digit number 100000.
            if ((i > 9 && i < 100) || (i > 999 && i < 10000) || (i == 100000)) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    Solution sol;

    // Test cases
    std::vector<int> nums1 = {12, 345, 2, 6, 7896};
    std::cout << "Test 1: nums = [12, 345, 2, 6, 7896]" << std::endl;
    std::cout << "Numbers with even digits (your logic): " << sol.findNumbers(nums1) << std::endl; // Expected: 2 (12, 7896)

    std::vector<int> nums2 = {555, 901, 482, 1771};
    std::cout << "\nTest 2: nums = [555, 901, 482, 1771]" << std::endl;
    std::cout << "Numbers with even digits (your logic): " << sol.findNumbers(nums2) << std::endl; // Expected: 2 (482 - no, 3 digits; 1771 - yes, 4 digits)

    // Let's refine the expectation for nums2 with your logic:
    // 555 (3 digits) - No
    // 901 (3 digits) - No
    // 482 (3 digits) - No
    // 1771 (4 digits) - Yes
    // Expected output for nums2 with your logic: 1

    std::vector<int> nums3 = {1, 10, 100, 1000, 10000, 100000};
    std::cout << "\nTest 3: nums = [1, 10, 100, 1000, 10000, 100000]" << std::endl;
    std::cout << "Numbers with even digits (your logic): " << sol.findNumbers(nums3) << std::endl; // Expected: 3 (10, 1000, 100000)

    return 0;
}