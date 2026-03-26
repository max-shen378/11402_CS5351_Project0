
# Acceptance Test

## Overview
This document defines the acceptance criteria for the Two Sum implementation project.

## Test Cases

### Test Case 1: Valid Solution Found
**Given:** An array of integers and a target sum
**When:** The two sum function is called
**Then:** Return indices of two numbers that add up to the target

**Example:**
```
Input: nums = [2, 7, 11, 15], target = 9
Expected Output: [0, 1]
```

### Test Case 2: No Solution Exists
**Given:** An array where no two numbers sum to target
**When:** The two sum function is called
**Then:** Return an appropriate error or empty result

**Example:**
```
Input: nums = [1, 2, 3], target = 10
Expected Output: [] or error
```

### Test Case 3: Negative Numbers
**Given:** An array containing negative integers
**When:** The two sum function is called
**Then:** Correctly identify pairs including negatives

**Example:**
```
Input: nums = [-1, -2, -3, 5, 6], target = 4
Expected Output: [2, 4] (indices of -3 and 7, or valid pair)
```

### Test Case 4: Duplicate Values
**Given:** An array with duplicate numbers
**When:** The two sum function is called
**Then:** Return valid indices (same number cannot be used twice)

## Acceptance Criteria
- ✓ All test cases pass
- ✓ Time complexity is O(n) or better
- ✓ Code is well-documented
- ✓ Edge cases handled appropriately
