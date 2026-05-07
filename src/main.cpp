#include <iostream>
#include <vector>
#include "twosum.h"

// Main program to call the two sum function
int main() {
    int n;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    std::vector<int> nums(n);
    std::cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }

    int target;
    std::cout << "Enter the target sum: ";
    std::cin >> target;

    std::vector<int> result = twoSum(nums, target);

    if (result.empty()) {
        std::cout << "No two sum solution found." << std::endl;
    } else {
        std::cout << "Indices: [" << result[0] << ", " << result[1] << "]" << std::endl;
    }

    return 0;
}