# Two Sum
The Two Sum problem is a classic algorithmic challenge where you need to find two numbers in an array that add up to a specified target sum. It emphasizes efficient solutions using hash maps to achieve optimal time complexity.
## Requirements

### Programming Language & Data Structures
- **Language**: C++
- **Input Array**: `std::vector<int>`
- **Result Storage**: `std::vector<int>`

### Implementation
- Implement `TwoSumArray()` function
- Implement `TwoSumHashTable()` function

### Test Coverage
- Normal cases with standard inputs
- Edge cases: duplicates, negative numbers, zero values
- Boundary conditions: minimum/maximum array sizes
- Multiple valid solutions

### Code Quality
- Clean, well-commented implementation
- Document time and space complexity for each approach
- Comprehensive documentation

### CI/CD Pipeline
- GitHub Actions workflow for automated testing
- Run unit tests on every push and pull request
- Test both `TwoSumArray()` and `TwoSumHashTable()` implementations

### Containerization
- Dockerfile for containerized deployment
- Execute tests during Docker build process
- Package complete solution with dependencies
