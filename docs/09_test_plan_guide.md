# Comprehensive Test Planning Guide

## Table of Contents
1. [Test Plan Overview](#test-plan-overview)
2. [Test Strategy](#test-strategy)
3. [Test Cases](#test-cases)
4. [Test Execution](#test-execution)
5. [Test Coverage](#test-coverage)
6. [Best Practices](#best-practices)

---

## Test Plan Overview

### Purpose
This document defines a comprehensive testing strategy for the Two Sum implementation to ensure:
- **Correctness**: Algorithm produces correct results
- **Reliability**: Handles edge cases gracefully
- **Performance**: Meets performance requirements
- **Maintainability**: Code is well-tested and documented

### Scope
- Core twoSum algorithm (both Array and HashTable implementations)
- Input validation
- Edge cases and boundary conditions
- Performance characteristics
- Integration with main application

### Testing Levels
| Level | Type | Coverage |
|-------|------|----------|
| **Unit Testing** | Individual functions | 80%+ |
| **Integration Testing** | Component interactions | Verify data flow |
| **Performance Testing** | Algorithm efficiency | Verify O(n) and O(n²) |
| **Acceptance Testing** | User requirements | All test cases |

---

## Test Strategy

### 1. Unit Testing Strategy

**Objective**: Test individual functions in isolation

**Test Structure**:
```cpp
// Each test follows this pattern:
void testName() {
    // Arrange: Set up test data
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    std::vector<int> expected = {0, 1};
    
    // Act: Execute the function
    std::vector<int> result = twoSum(nums, target);
    
    // Assert: Verify the result
    assert(result == expected);
}
```

### 2. Test Classification

Tests are organized into **6 test suites**:

#### Suite 1: Basic Functionality (4 tests)
- Valid pair exists and is found
- Multiple valid pairs (returns first)
- No valid pair exists
- Different array configurations

#### Suite 2: Edge Cases (4 tests)
- Empty array
- Single element array
- Two element array (valid/invalid)
- Minimum and maximum array sizes

#### Suite 3: Negative Numbers (3 tests)
- All negative numbers
- Mixed positive and negative
- Negative target sum

#### Suite 4: Duplicate Values (3 tests)
- Duplicate values with valid sum
- All identical values
- Multiple different duplicates

#### Suite 5: Boundary Conditions (4 tests)
- Zero as element
- Zero as target
- Large numbers (up to 2^31-1)
- Large arrays (100+ elements)

#### Suite 6: Special Cases (2 tests)
- Double the first element (impossible)
- Consecutive numbers

**Total: 20+ test cases**

---

## Test Cases

### TC1: Valid Pair Found
```
Input:  nums = [2, 7, 11, 15], target = 9
Output: [0, 1]
Why:    nums[0] + nums[1] = 2 + 7 = 9
```

### TC2: No Solution
```
Input:  nums = [1, 2, 3], target = 10
Output: []
Why:    No two elements sum to 10
```

### TC3: Empty Array
```
Input:  nums = [], target = 5
Output: []
Why:    Cannot find two elements in empty array
```

### TC4: Negative Numbers
```
Input:  nums = [-1, -2, -3, -5], target = -8
Output: [2, 3]
Why:    -3 + -5 = -8
```

### TC5: Duplicate Values
```
Input:  nums = [5, 5, 10], target = 10
Output: [0, 1]
Why:    5 + 5 = 10
```

### TC6: Large Array
```
Input:  nums = [1, 2, 3, ..., 100], target = 101
Output: [0, 99]
Why:    1 + 100 = 101
```

---

## Test Execution

### Local Testing

#### Compile the test suite:
```bash
# On Linux/macOS with g++
g++ -std=c++17 -o test_runner src/test_cases.cpp src/twosum.cpp

# On Windows with MSVC
cl /EHsc /std:c++17 src\test_cases.cpp src\twosum.cpp /Fe:test_runner.exe
```

#### Run the tests:
```bash
# Linux/macOS
./test_runner

# Windows
test_runner.exe
```

#### Expected output:
```
╔══════════════════════════════════════════════════════╗
║         TWO SUM ALGORITHM - COMPREHENSIVE TEST SUITE ║
╚══════════════════════════════════════════════════════╝

=== TEST SUITE 1: BASIC FUNCTIONALITY ===
✓ PASS - TC1: Valid pair (2+7=9) (Array)
✓ PASS - TC1: Valid pair (2+7=9) (HashTable)
✓ PASS - TC2: Valid pair (2+4=6) (Array)
✓ PASS - TC2: Valid pair (2+4=6) (HashTable)
...

╔══════════════════════════════════════════════════════╗
║                    TEST SUMMARY                      ║
╚══════════════════════════════════════════════════════╝
Total Tests:   40
Passed:        40
Failed:        0
Success Rate:  100%
```

---

## Test Coverage

### Coverage Metrics

| Component | Coverage | Status |
|-----------|----------|--------|
| twoSumArray | 100% | ✓ Complete |
| twoSumHashTable | 100% | ✓ Complete |
| twoSum (wrapper) | 100% | ✓ Complete |
| Edge cases | 100% | ✓ Complete |

### Code Coverage Analysis

Use gcov/lcov (Linux) to measure coverage:
```bash
# Compile with coverage flags
g++ -std=c++17 --coverage -o test_runner src/test_cases.cpp src/twosum.cpp

# Run tests
./test_runner

# Generate coverage report
gcov src/twosum.cpp
lcov --capture --directory . --output-file coverage.info
lcov --list coverage.info
```

---

## Performance Testing

### Algorithm Comparison

| Approach | Time Complexity | Space Complexity | Best For |
|----------|-----------------|------------------|----------|
| **Array (Brute Force)** | O(n²) | O(1) | Small arrays, space-critical |
| **HashTable (Optimized)** | O(n) | O(n) | Large arrays, speed-critical |

### Benchmark Test

```cpp
// Test with various array sizes
void benchmarkPerformance() {
    for (int size = 100; size <= 100000; size *= 10) {
        std::vector<int> nums;
        for (int i = 0; i < size; ++i) {
            nums.push_back(i);
        }
        
        // Measure Array implementation
        auto start1 = std::chrono::high_resolution_clock::now();
        twoSumArray(nums, size - 1);
        auto end1 = std::chrono::high_resolution_clock::now();
        
        // Measure HashTable implementation
        auto start2 = std::chrono::high_resolution_clock::now();
        twoSumHashTable(nums, size - 1);
        auto end2 = std::chrono::high_resolution_clock::now();
        
        std::cout << "Size: " << size
                  << " | Array: " << (end1 - start1).count() << "ns"
                  << " | HashTable: " << (end2 - start2).count() << "ns" << std::endl;
    }
}
```

---

## Best Practices

### 1. Test Organization
✓ Group related tests into test suites  
✓ Use descriptive test names (TC + description)  
✓ Comment the purpose of complex tests  
✓ Maintain consistent test structure (Arrange-Act-Assert)  

### 2. Test Data Design
✓ Use realistic data sets  
✓ Include boundary values  
✓ Test both positive and negative cases  
✓ Include edge cases (empty, single element, etc.)  

### 3. Assertion Best Practices
✓ One assertion per test (or group related assertions)  
✓ Use clear, meaningful error messages  
✓ Test both success and failure paths  
✓ Verify side effects if any  

### 4. Test Maintenance
✓ Keep tests simple and focused  
✓ Avoid test interdependencies  
✓ Update tests when requirements change  
✓ Review test coverage regularly  

### 5. Continuous Integration
✓ Run tests automatically on every commit  
✓ Generate coverage reports  
✓ Fail the build on test failures  
✓ Keep test suite fast (< 1 minute)  

---

## Documentation for Each Test

### Example Test Documentation
```
Test: TC1 - Valid Pair Found
Objective: Verify algorithm finds correct indices for valid pair
Input: nums = [2, 7, 11, 15], target = 9
Expected: [0, 1]
Coverage: Basic functionality
Pre-requisites: Array of integers, valid target sum
Post-conditions: Correct indices returned, no modifications to input
Status: PASS
```

---

## Troubleshooting

### Test Compilation Issues

**Problem**: `fatal error C1083: Cannot open include file`
```
Solution: Ensure twosum.h is in the include path
- Use absolute path in #include
- Check file exists in correct directory
```

**Problem**: Linker errors
```
Solution: Ensure all source files are compiled together
g++ -std=c++17 test_cases.cpp twosum.cpp -o test_runner
                ↑                 ↑
         must include both source files
```

### Test Execution Issues

**Problem**: Tests fail unexpectedly
```
Solution:
1. Check test assumptions
2. Verify input data
3. Debug with cout statements
4. Use debugger (gdb/lldb)
```

---

## Next Steps

1. **Run local tests** to verify implementation
2. **Check code coverage** and aim for >80%
3. **Integrate with CI/CD** (see GitHub Actions guide)
4. **Monitor performance** for large datasets
5. **Document any failures** and fixes
6. **Maintain test suite** as code evolves

---

**Last Updated**: May 7, 2026  
**Version**: 1.0
