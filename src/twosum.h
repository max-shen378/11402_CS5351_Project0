#ifndef TWOSUM_H
#define TWOSUM_H

#include <vector>

/**
 * Brute Force Approach - O(n²) time, O(1) space
 * Suitable for small arrays or when space is critical
 */
std::vector<int> twoSumArray(std::vector<int>& nums, int target);

/**
 * Optimized Hash Table Approach - O(n) time, O(n) space
 * Suitable for large arrays when performance is critical
 */
std::vector<int> twoSumHashTable(std::vector<int>& nums, int target);

/**
 * Default Implementation - Uses Hash Table approach
 * Recommended for general use
 */
std::vector<int> twoSum(std::vector<int>& nums, int target);

#endif // TWOSUM_H
