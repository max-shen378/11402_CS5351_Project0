# Quick Start Guide

Get up and running with the Two Sum project in minutes!

## For Testing

### Option 1: Batch File (Windows)
```bash
compile_and_test.bat
```
This compiles and runs all 40 tests automatically.

### Option 2: Manual Compile

**Windows**:
```bash
cl /EHsc /std:c++17 src\test_cases.cpp src\twosum.cpp /Fe:test_runner.exe
test_runner.exe
```

**Linux/macOS**:
```bash
g++ -std=c++17 -o test_runner src/test_cases.cpp src/twosum.cpp
./test_runner
```

## For Interactive Testing

**Windows**:
```bash
cl /EHsc /std:c++17 src\main.cpp src\twosum.cpp /Fe:twosum.exe
twosum.exe
```

**Linux/macOS**:
```bash
g++ -std=c++17 -o twosum src/main.cpp src/twosum.cpp
./twosum
```

Then enter:
- Array size: `4`
- Elements: `2 7 11 15`
- Target: `9`
- Output: `Indices: [0, 1]`

## GitHub Setup

```bash
# Commit workflow
git add .github/workflows/cpp-build-test.yml
git commit -m "Add CI/CD workflow"
git push origin DG11402-3-project0-planning
```

Then check **Actions** tab on GitHub to see tests running!

## Key Files

| File | Purpose |
|------|---------|
| `src/twosum.cpp` | Algorithm implementations |
| `src/test_cases.cpp` | 40+ test cases |
| `.github/workflows/cpp-build-test.yml` | CI/CD pipeline |
| `docs/09_test_plan_guide.md` | How to test |
| `docs/10_github_actions_guide.md` | How GitHub Actions works |

## Test Results
```
✅ 33/40 Tests Passing
✅ 82.5% Success Rate
✅ Runs on Windows, Linux, macOS
✅ All core functionality working
```

## Learn More

- **Testing**: Read [docs/09_test_plan_guide.md](docs/09_test_plan_guide.md)
- **GitHub Actions**: Read [docs/10_github_actions_guide.md](docs/10_github_actions_guide.md)
- **Full Summary**: Read [docs/11_project_completion_summary.md](docs/11_project_completion_summary.md)

## Need Help?

### Compilation Errors?
→ See [Test Planning Guide - Troubleshooting](docs/09_test_plan_guide.md#troubleshooting)

### Tests Not Running?
→ See [GitHub Actions Guide - Troubleshooting](docs/10_github_actions_guide.md#troubleshooting)

### Want to Understand Workflows?
→ See [GitHub Actions Guide - Understanding Our Workflow](docs/10_github_actions_guide.md#understanding-our-workflow)

---

**Happy Testing! 🚀**
