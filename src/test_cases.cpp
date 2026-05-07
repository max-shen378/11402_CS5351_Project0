#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <chrono>
#include "../src/twosum.h"

/**
 * Test Suite for Two Sum Implementation
 * 
 * This file contains comprehensive unit tests for both the brute force
 * and hash table implementations of the Two Sum algorithm.
 * 
 * Compile with: g++ -std=c++17 test_cases.cpp ../src/twosum.cpp -o test_runner
 * Run with: ./test_runner
 */

// Color codes for terminal output
#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

// Test counter
int testsRun = 0;
int testsPassed = 0;
int testsFailed = 0;

/**
 * Helper function to print test results
 */
void printTestResult(const std::string& testName, bool passed, const std::string& expected = "", const std::string& actual = "") {
    testsRun++;
    if (passed) {
        testsPassed++;
        std::cout << GREEN << "✓ PASS" << RESET << " - " << testName << std::endl;
    } else {
        testsFailed++;
        std::cout << RED << "✗ FAIL" << RESET << " - " << testName << std::endl;
        if (!expected.empty() && !actual.empty()) {
            std::cout << "  Expected: " << expected << " | Actual: " << actual << std::endl;
        }
    }
}

/**
 * Helper function to print vector
 */
std::string vectorToString(const std::vector<int>& vec) {
    if (vec.empty()) return "[]";
    std::string result = "[";
    for (int i = 0; i < vec.size(); ++i) {
        result += std::to_string(vec[i]);
        if (i < vec.size() - 1) result += ", ";
    }
    result += "]";
    return result;
}

/**
 * Helper function to run tests on both implementations
 */
void runTestOnBoth(const std::string& testName,
                   std::vector<int> nums,
                   int target,
                   const std::vector<int>& expected) {
    // Test Array implementation
    std::vector<int> result1 = twoSumArray(nums, target);
    bool passed1 = (result1 == expected);
    printTestResult(testName + " (Array)", passed1, vectorToString(expected), vectorToString(result1));

    // Test HashTable implementation
    result1 = nums; // Reset nums
    std::vector<int> result2 = twoSumHashTable(nums, target);
    bool passed2 = (result2 == expected);
    printTestResult(testName + " (HashTable)", passed2, vectorToString(expected), vectorToString(result2));
}

// ============================================================================
// TEST SUITE 1: BASIC FUNCTIONALITY TESTS
// ============================================================================

void testBasicFunctionality() {
    std::cout << YELLOW << "\n=== TEST SUITE 1: BASIC FUNCTIONALITY ===" << RESET << std::endl;

    // TC1: Valid pair exists - simple case
    {
        std::vector<int> nums = {2, 7, 11, 15};
        int target = 9;
        std::vector<int> expected = {0, 1};
        runTestOnBoth("TC1: Valid pair (2+7=9)", nums, target, expected);
    }

    // TC2: Valid pair with different positions
    {
        std::vector<int> nums = {3, 2, 4};
        int target = 6;
        std::vector<int> expected = {1, 2};
        runTestOnBoth("TC2: Valid pair (2+4=6)", nums, target, expected);
    }

    // TC3: No valid pair exists
    {
        std::vector<int> nums = {1, 2, 3};
        int target = 10;
        std::vector<int> expected = {};
        runTestOnBoth("TC3: No solution exists", nums, target, expected);
    }

    // TC4: Multiple valid pairs - should return first
    {
        std::vector<int> nums = {1, 2, 3, 4, 5};
        int target = 6;
        std::vector<int> expected = {0, 5}; // 1 + 5 or 2 + 4
        // Note: This test may need adjustment based on implementation specifics
        runTestOnBoth("TC4: Multiple pairs possible", nums, target, {1, 3}); // 2 + 4
    }
}

// ============================================================================
// TEST SUITE 2: EDGE CASES
// ============================================================================

void testEdgeCases() {
    std::cout << YELLOW << "\n=== TEST SUITE 2: EDGE CASES ===" << RESET << std::endl;

    // TC5: Empty array
    {
        std::vector<int> nums = {};
        int target = 5;
        std::vector<int> expected = {};
        runTestOnBoth("TC5: Empty array", nums, target, expected);
    }

    // TC6: Single element
    {
        std::vector<int> nums = {5};
        int target = 10;
        std::vector<int> expected = {};
        runTestOnBoth("TC6: Single element", nums, target, expected);
    }

    // TC7: Two elements valid
    {
        std::vector<int> nums = {1, 2};
        int target = 3;
        std::vector<int> expected = {0, 1};
        runTestOnBoth("TC7: Exactly two elements (valid)", nums, target, expected);
    }

    // TC8: Two elements invalid
    {
        std::vector<int> nums = {1, 2};
        int target = 10;
        std::vector<int> expected = {};
        runTestOnBoth("TC8: Exactly two elements (invalid)", nums, target, expected);
    }
}

// ============================================================================
// TEST SUITE 3: NEGATIVE NUMBERS
// ============================================================================

void testNegativeNumbers() {
    std::cout << YELLOW << "\n=== TEST SUITE 3: NEGATIVE NUMBERS ===" << RESET << std::endl;

    // TC9: All negative numbers
    {
        std::vector<int> nums = {-1, -2, -3, -5};
        int target = -8;
        std::vector<int> expected = {2, 3}; // -3 + -5 = -8
        runTestOnBoth("TC9: All negative numbers", nums, target, expected);
    }

    // TC10: Mix of positive and negative
    {
        std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
        int target = 0;
        std::vector<int> expected = {0, 2}; // -1 + 1 = 0
        runTestOnBoth("TC10: Mixed positive/negative", nums, target, expected);
    }

    // TC11: Target is negative
    {
        std::vector<int> nums = {1, 2, 3, 4, 5};
        int target = -5;
        std::vector<int> expected = {};
        runTestOnBoth("TC11: Negative target (no solution)", nums, target, expected);
    }
}

// ============================================================================
// TEST SUITE 4: DUPLICATE VALUES
// ============================================================================

void testDuplicateValues() {
    std::cout << YELLOW << "\n=== TEST SUITE 4: DUPLICATE VALUES ===" << RESET << std::endl;

    // TC12: Duplicate values - first occurrence
    {
        std::vector<int> nums = {5, 5, 10};
        int target = 10;
        std::vector<int> expected = {0, 1}; // 5 + 5 = 10
        runTestOnBoth("TC12: Duplicate values (5+5=10)", nums, target, expected);
    }

    // TC13: Many duplicate values
    {
        std::vector<int> nums = {1, 1, 1, 1};
        int target = 2;
        std::vector<int> expected = {0, 1}; // 1 + 1 = 2
        runTestOnBoth("TC13: All same values", nums, target, expected);
    }

    // TC14: Duplicates with different target
    {
        std::vector<int> nums = {2, 2, 3, 3, 4, 4};
        int target = 6;
        std::vector<int> expected = {0, 2}; // 2 + 4 = 6 or others
        runTestOnBoth("TC14: Multiple duplicates", nums, target, expected);
    }
}

// ============================================================================
// TEST SUITE 5: BOUNDARY CONDITIONS
// ============================================================================

void testBoundaryConditions() {
    std::cout << YELLOW << "\n=== TEST SUITE 5: BOUNDARY CONDITIONS ===" << RESET << std::endl;

    // TC15: Zero as element
    {
        std::vector<int> nums = {0, 1, 2, 3};
        int target = 1;
        std::vector<int> expected = {0, 1}; // 0 + 1 = 1
        runTestOnBoth("TC15: Zero as element", nums, target, expected);
    }

    // TC16: Zero as target
    {
        std::vector<int> nums = {-2, -1, 0, 1, 2};
        int target = 0;
        std::vector<int> expected = {0, 4}; // -2 + 2 = 0
        runTestOnBoth("TC16: Zero as target", nums, target, expected);
    }

    // TC17: Large numbers
    {
        std::vector<int> nums = {1000000, 2000000, 3000000, 4000000};
        int target = 3000000;
        std::vector<int> expected = {0, 1}; // 1000000 + 2000000 = 3000000
        runTestOnBoth("TC17: Large numbers", nums, target, expected);
    }

    // TC18: Large array
    {
        std::vector<int> nums;
        for (int i = 1; i <= 100; ++i) {
            nums.push_back(i);
        }
        int target = 101;
        std::vector<int> expected = {0, 99}; // 1 + 100 = 101
        runTestOnBoth("TC18: Large array (100 elements)", nums, target, expected);
    }
}

// ============================================================================
// TEST SUITE 6: SPECIAL CASES
// ============================================================================

void testSpecialCases() {
    std::cout << YELLOW << "\n=== TEST SUITE 6: SPECIAL CASES ===" << RESET << std::endl;

    // TC19: Double the first element
    {
        std::vector<int> nums = {1, 2, 3, 4};
        int target = 2;
        std::vector<int> expected = {0, 0}; // Cannot use same element twice - should be empty
        // Actually this should return empty because we can't use index 0 twice
        std::vector<int> expected2 = {};
        runTestOnBoth("TC19: Target requires same index twice", nums, target, expected2);
    }

    // TC20: Consecutive numbers
    {
        std::vector<int> nums = {1, 2, 3, 4, 5};
        int target = 7;
        std::vector<int> expected = {2, 4}; // 3 + 4 = 7
        runTestOnBoth("TC20: Consecutive numbers", nums, target, expected);
    }
}

// ============================================================================
// MAIN TEST RUNNER
// ============================================================================

int main() {
    std::cout << YELLOW << "╔══════════════════════════════════════════════════════╗" << RESET << std::endl;
    std::cout << YELLOW << "║         TWO SUM ALGORITHM - COMPREHENSIVE TEST SUITE ║" << RESET << std::endl;
    std::cout << YELLOW << "╚══════════════════════════════════════════════════════╝" << RESET << std::endl;

    // Run all test suites
    testBasicFunctionality();
    testEdgeCases();
    testNegativeNumbers();
    testDuplicateValues();
    testBoundaryConditions();
    testSpecialCases();

    // Print summary
    std::cout << YELLOW << "\n╔══════════════════════════════════════════════════════╗" << RESET << std::endl;
    std::cout << YELLOW << "║                    TEST SUMMARY                      ║" << RESET << std::endl;
    std::cout << YELLOW << "╚══════════════════════════════════════════════════════╝" << RESET << std::endl;
    std::cout << "Total Tests:   " << testsRun << std::endl;
    std::cout << GREEN << "Passed:        " << testsPassed << RESET << std::endl;
    std::cout << (testsFailed > 0 ? RED : GREEN) << "Failed:        " << testsFailed << RESET << std::endl;
    std::cout << "Success Rate:  " << (testsRun > 0 ? (testsPassed * 100.0 / testsRun) : 0) << "%" << std::endl;

    std::cout << std::endl;
    return (testsFailed == 0) ? 0 : 1;
}
