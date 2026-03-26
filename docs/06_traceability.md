
# Traceability Matrix

## Overview
This document maps requirements to implementation artifacts for the Two Sum project.

## Requirements Traceability

| ID | Requirement | Implementation | Test | Status |
|---|---|---|---|---|
| REQ-001 | Accept array of integers | `twoSum()` function signature | `test_input_handling` | ✓ |
| REQ-002 | Accept target sum value | `twoSum(nums, target)` parameter | `test_target_parameter` | ✓ |
| REQ-003 | Return indices of two numbers | Return type: `int[]` or `List<int>` | `test_return_indices` | ✓ |
| REQ-004 | Handle no solution case | Return `[-1, -1]` or `null` | `test_no_solution` | ✓ |
| REQ-005 | O(n) time complexity | Hash map implementation | `test_performance` | ✓ |
| REQ-006 | Assume one valid answer | Single pair guarantee | `test_unique_solution` | ✓ |

## Code-to-Test Mapping

| Source File | Test File | Coverage |
|---|---|---|
| `src/twoSum.py` | `tests/test_twoSum.py` | Core algorithm |
| `src/twoSum.java` | `tests/TwoSumTest.java` | Java implementation |

## Design Decisions

- **Algorithm**: Hash map for O(n) lookup
- **Edge Cases**: Duplicates, negative numbers, empty arrays
- **Language Support**: Python, Java
