// Two Sum implementations: Brute Force Array and Optimized Hash Table approaches

#include <vector>
#include <unordered_map>

/**
 * APPROACH 1: Brute Force Array Method
 * 
 * Finds two indices in the array that add up to the target using nested loops.
 * Time Complexity: O(n²)
 * Space Complexity: O(1)
 * 
 * Pros:
 *  - No extra space needed
 *  - Simple and straightforward
 * 
 * Cons:
 *  - Slower for large arrays
 *  - Many redundant checks
 * 
 * @param nums The array of integers
 * @param target The target sum
 * @return Vector containing the two indices, or empty vector if no solution
 */
std::vector<int> twoSumArray(std::vector<int>& nums, int target) {
    if (nums.size() < 2) {
        return {}; // Not enough elements
    }

    // Check all pairs
    for (int i = 0; i < nums.size() - 1; ++i) {
        for (int j = i + 1; j < nums.size(); ++j) {
            // If current pair sums to target, return indices
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }

    return {}; // No solution found
}

/**
 * APPROACH 2: Hash Table Method (Optimized)
 * 
 * Finds two indices using a hash map for single-pass lookup.
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * 
 * Pros:
 *  - Much faster for large arrays
 *  - Single pass through array
 *  - Guaranteed O(n) performance
 * 
 * Cons:
 *  - Requires O(n) extra space for hash map
 * 
 * Algorithm:
 *  1. Iterate through array once
 *  2. For each element, calculate complement (target - current)
 *  3. Check if complement exists in hash map
 *  4. If yes, return indices
 *  5. If no, store current element in hash map
 * 
 * @param nums The array of integers
 * @param target The target sum
 * @return Vector containing the two indices, or empty vector if no solution
 */
std::vector<int> twoSumHashTable(std::vector<int>& nums, int target) {
    if (nums.size() < 2) {
        return {}; // Not enough elements
    }

    // Map stores: <value, index>
    std::unordered_map<int, int> numMap;

    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];

        // Check if complement exists in map
        if (numMap.find(complement) != numMap.end()) {
            return {numMap[complement], i};
        }

        // Store current number and index
        numMap[nums[i]] = i;
    }

    return {}; // No solution found
}

/**
 * DEFAULT IMPLEMENTATION: Uses optimized hash table approach
 * 
 * This wrapper function calls the optimized hash table implementation.
 * It maintains backward compatibility with existing code.
 * 
 * @param nums The array of integers
 * @param target The target sum
 * @return Vector containing the two indices, or empty vector if no solution
 */
std::vector<int> twoSum(std::vector<int>& nums, int target) {
    return twoSumHashTable(nums, target);
}