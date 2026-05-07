# GitHub Actions: Continuous Integration Guide

## Table of Contents
1. [Overview](#overview)
2. [What is GitHub Actions?](#what-is-github-actions)
3. [Workflow File Structure](#workflow-file-structure)
4. [Setting Up CI/CD](#setting-up-cicd)
5. [Understanding Our Workflow](#understanding-our-workflow)
6. [Monitoring and Debugging](#monitoring-and-debugging)
7. [Best Practices](#best-practices)
8. [Troubleshooting](#troubleshooting)

---

## Overview

### What This Does
Automatically builds and tests your C++ code every time you:
- Push code to GitHub
- Create a pull request
- Merge to main branch

### Benefits
✓ **Catch bugs early** - Tests run before code is merged  
✓ **Cross-platform testing** - Test on Windows, Linux, macOS  
✓ **Automated quality checks** - Static analysis, code style  
✓ **Code coverage tracking** - Monitor test coverage  
✓ **No manual testing** - Everything is automatic  

---

## What is GitHub Actions?

### Key Concepts

**Workflow**: A set of automated tasks (defined in YAML file)
```
File location: .github/workflows/cpp-build-test.yml
Triggered by: push, pull_request events
```

**Job**: A collection of steps that run on a runner
```
Jobs run in parallel by default
Can have dependencies between jobs
Example jobs: build-and-test, code-quality, coverage
```

**Step**: Individual commands or actions within a job
```
Example steps:
1. Checkout code
2. Set up compiler
3. Compile code
4. Run tests
5. Upload coverage
```

**Runner**: The machine where jobs run
```
Ubuntu (Linux): ubuntu-latest
Windows: windows-latest
macOS: macos-latest
```

### Simple Analogy
```
Workflow = Your testing routine
Job = Test session on one computer
Step = Individual test command
Runner = The computer running the tests
```

---

## Workflow File Structure

### File Location
```
your-repo/
├── .github/
│   └── workflows/
│       └── cpp-build-test.yml    ← This file
├── src/
│   ├── main.cpp
│   ├── twosum.cpp
│   ├── twosum.h
│   └── test_cases.cpp
└── docs/
    └── ...
```

### Basic YAML Structure

```yaml
name: C++ Build and Test                    # Workflow name
on:                                         # Trigger conditions
  push:
    branches: [ main, develop ]
  pull_request:
    branches: [ main ]

jobs:                                       # Define jobs
  build-and-test:
    name: Build and Test
    runs-on: ubuntu-latest                 # Runner OS
    
    steps:                                 # Steps in the job
    - name: Checkout code
      uses: actions/checkout@v3            # Use predefined action
    
    - name: Compile
      run: g++ -std=c++17 -o test test.cpp # Run command
    
    - name: Run tests
      run: ./test
```

---

## Setting Up CI/CD

### Step 1: File Already Exists
The workflow file has been created at:
```
.github/workflows/cpp-build-test.yml
```

### Step 2: Commit and Push
```bash
# Stage the workflow file
git add .github/workflows/cpp-build-test.yml

# Commit
git commit -m "Add GitHub Actions CI/CD workflow"

# Push to GitHub
git push origin DG11402-3-project0-planning
```

### Step 3: Verify Workflow
1. Go to your GitHub repository
2. Click **Actions** tab
3. You should see workflow runs listed
4. Each run shows build status

### What Triggers the Workflow?

**Automatic triggers**:
- Push to `main`, `develop`, or `DG11402-3-project0-planning` branch
- Create pull request to `main` or `develop`
- Changes to files in `src/` or `.github/workflows/`

**Manual trigger** (optional, requires setup):
- Can manually trigger from Actions tab

---

## Understanding Our Workflow

### Job 1: Build and Test (Multi-Platform)

**Platforms tested**: Windows, Linux, macOS

**For each platform**:
```yaml
steps:
  1. Checkout code                # Get your code
  2. Set up C++ compiler          # Install compiler if needed
  3. Compile test suite           # Compile test_cases.cpp
  4. Compile main application     # Compile main.cpp
  5. Run test suite               # Execute tests
  6. Display test results         # Show build info
```

**Key feature**: Matrix strategy
```yaml
matrix:
  os: [ubuntu-latest, windows-latest, macos-latest]
  # Runs job 3 times, once per OS
```

This ensures code works on all platforms! ✓

### Job 2: Code Quality Checks

**What it does**:
1. Runs `cppcheck` - Static code analyzer
2. Checks for code style issues
   - Trailing whitespace
   - Tab characters (should use spaces)

**Purpose**: Catch potential bugs and maintain code quality

### Job 3: Code Coverage Analysis

**What it does**:
1. Compiles with coverage flags
2. Runs tests
3. Generates coverage report
4. Uploads to Codecov (optional)

**Coverage report shows**:
- Which lines were executed
- Which functions are tested
- Overall coverage percentage

---

## Monitoring and Debugging

### Viewing Workflow Results

#### Step 1: Access Actions Tab
1. Go to GitHub repository
2. Click **Actions** tab
3. Select workflow run

#### Step 2: View Job Status
```
✓ PASS   - All steps passed
✗ FAIL   - At least one step failed
⊗ SKIP   - Job was skipped
⟳ IN PROGRESS - Currently running
```

#### Step 3: Check Logs
Click on any job or step to see:
- Commands executed
- Full output/errors
- Timing information
- Return codes

### Example: Viewing Test Output
```
Job: build-and-test (ubuntu-latest)
├── Checkout code ✓
├── Set up C++ compiler ✓
├── Compile test suite ✓
│   └── Output: Successfully compiled
├── Run test suite ✓
│   └── Output:
│       ✓ PASS - TC1: Valid pair
│       ✓ PASS - TC2: No solution
│       ✓ PASS - TC3: Empty array
│       ...
│       Success Rate: 100%
└── Display results ✓
```

### Debugging Failed Builds

**Common issues**:

1. **Compilation error on specific OS**
   - Click that job's logs
   - Look for error message
   - Fix platform-specific issue

2. **Test failures**
   - Click job → Step "Run test suite"
   - Look for failed tests
   - Debug and fix code locally first

3. **Coverage not generated**
   - Check OS is Linux (coverage requires gcov)
   - Verify compilation with `-coverage` flag

---

## Best Practices

### 1. Commit Structure
✓ Commit related changes together  
✓ Write meaningful commit messages  
✓ Keep commits focused and small  
```bash
git commit -m "Implement TwoSumHashTable and add comprehensive tests"
```

### 2. Pull Request Workflow
```
1. Create feature branch
   git checkout -b feature/new-implementation

2. Make changes and commit

3. Push branch
   git push origin feature/new-implementation

4. Create PR on GitHub
   - GitHub Actions runs automatically
   - Review test results before merging

5. Fix any failures

6. Merge to main once all checks pass
```

### 3. Workflow Optimization
✓ Fail fast - Stop on first error  
✓ Parallel jobs - Run independent jobs together  
✓ Cache dependencies - Reuse installed packages  
✓ Keep tests fast - < 1 minute total  

### 4. Status Badges
Add to your README.md:
```markdown
![Build Status](https://github.com/max-shen378/11402_CS5351_Project0/actions/workflows/cpp-build-test.yml/badge.svg)
```

This displays workflow status on repository home page.

---

## Advanced Features

### Adding Code Coverage Badge
```markdown
[![codecov](https://codecov.io/gh/max-shen378/11402_CS5351_Project0/branch/main/graph/badge.svg)](https://codecov.io/gh/max-shen378/11402_CS5351_Project0)
```

### Matrix Strategy with Conditions
```yaml
strategy:
  matrix:
    include:
      - os: ubuntu-latest
        compiler: g++
      - os: windows-latest
        compiler: msvc
      - os: macos-latest
        compiler: clang++
```

### Conditional Steps
```yaml
- name: Upload to Codecov
  if: runner.os == 'Linux'  # Only on Linux
  uses: codecov/codecov-action@v3
```

### Scheduled Workflows
```yaml
on:
  schedule:
    - cron: '0 0 * * *'  # Run daily at midnight
```

---

## Troubleshooting

### Issue: Workflow not running

**Possible causes**:
1. File not in correct location
   ```
   ✓ .github/workflows/cpp-build-test.yml
   ✗ .github/cpp-build-test.yml (wrong)
   ✗ workflows/cpp-build-test.yml (wrong)
   ```

2. File not committed
   ```bash
   git add .github/
   git commit -m "Add workflow"
   git push
   ```

3. Trigger conditions not met
   - Check `on:` section in workflow
   - Make sure branch matches
   - Ensure you have changes to `src/`

**Solution**:
1. Check file path is exact
2. Commit and push
3. Wait a few seconds for workflow to appear
4. Refresh GitHub Actions page

### Issue: Compilation fails on specific OS

**Ubuntu/Linux**:
- May need additional packages
- Solution: Add to `Set up tools` step
```yaml
- name: Install packages
  run: sudo apt-get install -y [package-name]
```

**Windows**:
- May need MSVC setup
- Solution: Already included in workflow

**macOS**:
- May need Xcode or tools
- Solution: Already included in workflow

### Issue: Tests pass locally but fail on CI

**Possible causes**:
1. Different compiler versions
   - Solution: Specify C++ standard explicitly
   ```cpp
   // Use only features available in C++17
   ```

2. Platform-specific behavior
   - Solution: Test on same platform locally
   - Or use Docker to match CI environment

3. Missing dependencies
   - Solution: Ensure all includes are available
   - Check file paths are portable

### Issue: Build takes too long

**Optimization tips**:
1. Skip unnecessary jobs (use `if:` conditions)
2. Cache compiler downloads
3. Reduce test cases
4. Run jobs in parallel

---

## Working with Pull Requests

### PR Workflow

```
1. Create feature branch
   git checkout -b implement-feature

2. Make changes
   # Edit files
   git add .
   git commit -m "Add new feature"

3. Push to GitHub
   git push origin implement-feature

4. Create PR on GitHub
   - GitHub automatically runs workflow
   - Wait for all checks to pass ✓

5. If checks fail:
   - Look at failed job logs
   - Fix code locally
   - Commit and push updates
   - Workflow automatically re-runs ✓

6. Once all pass, merge to main
   - Click "Merge pull request"
   - Confirm merge
```

### PR Status Checks

GitHub shows:
```
✓ build-and-test (ubuntu-latest)  PASSED
✓ build-and-test (windows-latest) PASSED
✓ build-and-test (macos-latest)   PASSED
✓ code-quality                     PASSED
✓ coverage                         PASSED

All checks passed - Ready to merge!
```

---

## Learning Resources

### Official Documentation
- [GitHub Actions Documentation](https://docs.github.com/en/actions)
- [GitHub Actions Quickstart](https://docs.github.com/en/actions/quickstart)
- [Workflow syntax for GitHub Actions](https://docs.github.com/en/actions/using-workflows/workflow-syntax-for-github-actions)

### YAML Basics
- [YAML Tutorial for Beginners](https://www.cloudbees.com/blog/yaml-tutorial-everything-you-need-get-started)
- [YAML Syntax Guide](https://yaml.org/start.html)

### C++ Workflows
- [C++ on GitHub Actions](https://docs.github.com/en/actions/guides/building-and-testing-cpp)

### Related Tools
- [CMake](https://cmake.org/) - Build system (optional)
- [Codecov](https://codecov.io/) - Coverage tracking
- [cppcheck](http://cppcheck.sourceforge.net/) - Static analysis

---

## Summary Checklist

✓ Workflow file created: `.github/workflows/cpp-build-test.yml`  
✓ Committed and pushed to repository  
✓ Workflow runs automatically on push/PR  
✓ Tests run on 3 platforms (Windows/Linux/macOS)  
✓ Code quality checks included  
✓ Coverage analysis enabled  
✓ Monitor results in GitHub Actions tab  
✓ Fix failures and re-push  

---

**Next Steps**:
1. Commit workflow file to repository
2. Monitor first workflow run in Actions tab
3. Fix any failures
4. Use as template for future projects

**Last Updated**: May 7, 2026  
**Version**: 1.0
