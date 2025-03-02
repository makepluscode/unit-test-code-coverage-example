# Unit Testing and Code Coverage with Google Test and lcov

This README provides a step-by-step guide to set up unit testing with Google Test and measure code coverage using lcov.

## Prerequisites

- CMake (version 3.10 or higher)
- GCC/G++ compiler
- lcov (for code coverage reporting)

## Getting Started

### 1. Clone the Repository

```bash
git clone https://github.com/yourusername/your-project.git
cd your-project
```

### 2. Build the Project

```bash
# Create a build directory
mkdir build
cd build

# Configure with CMake
cmake ..

# Build the project
make
```

### 3. Run the Tests

```bash
# Run the test executable
./gtest_example
```

This will execute all the unit tests and display the results in the terminal.

## Measuring Code Coverage

### 1. Reset Coverage Data

Before running tests for coverage, reset any existing coverage data:

```bash
# In the build directory
lcov --zerocounters --directory .
```

### 2. Run Tests for Coverage

```bash
# Run the test executable
./gtest_example
```

### 3. Collect Coverage Data

```bash
# Capture coverage information
lcov --capture --directory . --output-file coverage_raw.info --rc lcov_branch_coverage=1 --ignore-errors inconsistent,unsupported
```

### 4. Filter Out External Code

Remove system libraries and Google Test code from the coverage report:

```bash
lcov --remove coverage_raw.info '/usr/*' '*/_deps/*' '*/googletest/*' -o coverage.info
```

### 5. Generate HTML Report

```bash
genhtml coverage.info --output-directory coverage_report
```

### 6. View the Coverage Report

Open the HTML report in your browser:

```bash
# On macOS
open coverage_report/index.html

# On Linux
xdg-open coverage_report/index.html
```

## Understanding the Coverage Report

The HTML report provides:

- Overall coverage percentage
- File-by-file coverage breakdown
- Line-by-line coverage highlighting
- Branch coverage information

Green lines indicate covered code, while red lines show uncovered code.

## Troubleshooting

If you encounter errors with lcov:

1. Make sure your CMakeLists.txt includes coverage flags:
   ```cmake
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
   set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
   ```

2. Try adding error-ignore options to lcov commands:
   ```bash
   lcov --capture --directory . --output-file coverage_raw.info --ignore-errors inconsistent,unsupported
   ```

3. Check if .gcno and .gcda files are generated:
   ```bash
   find . -name "*.gcno"
   find . -name "*.gcda"
   ```

## Project Structure

```
your-project/
├── src/                  # Source code
├── test/                 # Test files
├── CMakeLists.txt        # Build configuration
└── coverage_report/      # Generated coverage report
```

## Additional Resources

- [Google Test Documentation](https://google.github.io/googletest/)
- [lcov Documentation](http://ltp.sourceforge.net/coverage/lcov.php)
