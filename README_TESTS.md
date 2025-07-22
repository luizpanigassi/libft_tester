# Libft Test Suite

A comprehensive test suite for testing all functions in your libft library.

**Note**: This test suite is designed to be placed in a `tester/` subdirectory of your libft project. It will automatically find and test the libft source files in the parent directory.

## Directory Structure

Your project should be organized like this:
```
libft/
├── ft_*.c          # Your libft source files
├── libft.h         # Your libft header file
├── Makefile        # Your original Makefile
└── tester/         # Test suite directory
    ├── test_libft.c
    ├── Makefile.test
    ├── run_tests.sh
    └── README_TESTS.md (this file)
```

## Overview

This test suite covers all mandatory and bonus functions in libft:

### Mandatory Functions
- **Character classification**: `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`
- **Character conversion**: `ft_toupper`, `ft_tolower`
- **String functions**: `ft_strlen`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strlcpy`, `ft_strlcat`, `ft_strnstr`, `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_strmapi`, `ft_striteri`, `ft_strdup`
- **Memory functions**: `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc`
- **Conversion functions**: `ft_atoi`, `ft_itoa`
- **File descriptor functions**: `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`

### Bonus Functions
- **Linked list functions**: `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`

## Files

- `test_libft.c` - Main test file with all test functions
- `Makefile.test` - Makefile for building and running tests
- `run_tests.sh` - Convenient script for running tests with various options
- `README_TESTS.md` - This documentation file

## Quick Start

**Important**: Make sure you're in the `tester/` directory before running these commands!

```bash
cd tester
```

### Method 1: Using the run script (Recommended)

```bash
# Run all tests (mandatory + bonus)
./run_tests.sh

# Run tests with norminette check first
./run_tests.sh --norm

# Check only norminette compliance
./run_tests.sh --norm-only

# Run only mandatory function tests with norminette
./run_tests.sh --mandatory --norm

# Run tests with valgrind (memory leak checking)
./run_tests.sh --valgrind

# Full comprehensive check (norminette + all tests + verbose)
./run_tests.sh --full --verbose
```

### Method 2: Using Make directly

```bash
# Build and run all tests
make -f Makefile.test test

# Check norminette compliance
make -f Makefile.test norm

# Check norminette with summary
make -f Makefile.test norm-check

# Run norminette check + tests
make -f Makefile.test full-check

# Build and run only mandatory tests
make -f Makefile.test test-mandatory

# Run with valgrind
make -f Makefile.test valgrind

# Just build (don't run)
make -f Makefile.test all
```

### Method 3: Manual compilation

```bash
# Check norminette first
norminette ../libft.h ../ft_*.c

# Compile all source files with the test file
gcc -Wall -Wextra -Werror -g -I.. ../*.c test_libft.c -o test_libft

# Run the tests
./test_libft
```

## Understanding the Output

The test suite provides colored output:
- 🟢 **Green ✓**: Test passed
- 🔴 **Red ✗**: Test failed
- 🟡 **Yellow ⚠**: Test skipped (usually due to system limitations)
- 🟣 **Purple**: Norminette checking section

### Norminette Output
- ✅ **Green**: All files are norminette compliant
- ❌ **Red**: Norminette errors found (with details)
- ⚠️ **Yellow**: Norminette not installed

Example output:
```
=======================================
        NORMINETTE COMPLIANCE
=======================================
Checking norminette compliance...

✅ All files are norminette compliant!

=======================================
           RUNNING TESTS
=======================================
Running tests...

=== Testing ft_strlen ===
✓ ft_strlen("") should return 0
✓ ft_strlen("Hello") should return 5

=== TEST SUMMARY ===
Total tests: 143
Passed: 143
Failed: 0

=======================================
    🎉 ALL TESTS PASSED! 🎉
    ✅ NORMINETTE COMPLIANT ✅
=======================================
```

## Script Options

### run_tests.sh Options

| Option | Description |
|--------|-------------|
| `--norm` | Check norminette compliance before running tests |
| `--norm-only` | Only check norminette (don't run tests) |
| `--full` | Run norminette + all tests (same as `--norm`) |
| `--mandatory` | Test only mandatory functions |
| `--valgrind` | Run tests with memory leak detection |
| `--verbose` | Show detailed build output |
| `--help` | Display help message |

### Usage Examples

```bash
# Quick test run
./run_tests.sh

# Professional check (recommended for submission)
./run_tests.sh --norm --valgrind

# Debug failed tests
./run_tests.sh --verbose

# Check compliance only
./run_tests.sh --norm-only

# Test mandatory functions with full checking
./run_tests.sh --mandatory --norm --valgrind
```

## Norminette Integration

The test suite includes comprehensive norminette checking:

### Installing Norminette
If you don't have norminette installed:
```bash
pip3 install --user norminette
```

### Norminette Features
- **Automatic Detection**: Checks if norminette is installed
- **Comprehensive Checking**: Tests all `.c` files and `libft.h`
- **Error Highlighting**: Shows specific errors in red
- **Summary Reports**: Displays total error count
- **Integration**: Can run before tests to ensure compliance

### Makefile Norminette Targets
- `norm`: Verbose norminette check
- `norm-check`: Summary norminette check
- `full-check`: Norminette + tests combined

## Test Categories

### 1. Character Classification Tests
Tests all the `ft_is*` functions with various inputs including edge cases.

### 2. String Function Tests
Comprehensive testing of string manipulation functions with:
- Empty strings
- Normal cases
- Edge cases (NULL pointers, boundary conditions)
- Memory allocation tests

### 3. Memory Function Tests
Tests memory manipulation functions with:
- Overlapping memory regions
- Various data types
- Boundary conditions

### 4. Conversion Tests
Tests `ft_atoi` and `ft_itoa` with:
- Positive and negative numbers
- Edge cases (INT_MIN, INT_MAX)
- Invalid inputs

### 5. File Descriptor Tests
Tests output functions by:
- Writing to temporary files
- Reading back and verifying content
- Note: These tests may be skipped if file creation fails

### 6. Linked List Tests (Bonus)
Tests all list functions with:
- Empty lists
- Single node lists
- Multiple node lists
- Memory management

## Troubleshooting

### Norminette Issues
- **Not installed**: Run `pip3 install --user norminette`
- **Permission errors**: Try with `sudo` or use `--user` flag
- **Path issues**: Ensure `~/.local/bin` is in your PATH

### Build Errors
- Ensure you're running the tests from the `tester/` directory
- Ensure all your `.c` files are in the parent directory of the tester
- Check that your `libft.h` file is in the parent directory and contains all required function prototypes
- Verify your function signatures match the expected signatures

### Test Failures
- Read the specific test that failed
- Check your implementation against the test case
- Use `gdb` for debugging: `gdb ./test_libft`

### Memory Leaks
- Run with valgrind: `./run_tests.sh --valgrind`
- Fix any reported leaks in your implementations

### Directory Issues
- Make sure you're in the `tester/` directory when running tests
- Ensure your libft source files are in the parent directory
- The tester looks for `../libft.h` and `../ft_*.c` files

## Makefile Targets

| Target | Description |
|--------|-------------|
| `all` | Build the complete test suite |
| `test` | Build and run all tests |
| `mandatory` | Build test suite for mandatory functions only |
| `test-mandatory` | Build and run tests for mandatory functions only |
| `valgrind` | Run tests with valgrind |
| `norm` | Check norminette compliance (verbose) |
| `norm-check` | Check norminette compliance (summary) |
| `full-check` | Run norminette check + tests |
| `clean` | Remove object files |
| `fclean` | Remove object files and executables |
| `re` | Rebuild everything |
| `help` | Show available targets |

## Professional Workflow

For submission-ready code, use this workflow:

```bash
# 1. Check norminette compliance
./run_tests.sh --norm-only

# 2. Run comprehensive tests with memory checking
./run_tests.sh --norm --valgrind

# 3. Test mandatory functions only (if needed)
./run_tests.sh --mandatory --norm

# 4. Final verification
make -f Makefile.test full-check
```

## Adding Your Own Tests

You can extend the test suite by:

1. Adding new test functions following the pattern:
```c
void test_my_function(void) {
    printf(BLUE "\n=== Testing my_function ===\n" RESET);
    TEST_ASSERT(condition, "test description");
}
```

2. Calling your test function in `main()`

3. Using the `TEST_ASSERT` macro for assertions

## Tips

- Always run norminette before testing: `./run_tests.sh --norm`
- Use valgrind regularly to catch memory issues: `./run_tests.sh --valgrind`
- Test edge cases and boundary conditions
- Check return values and error handling
- Keep your code norminette compliant throughout development

## Requirements

- GCC compiler
- Your libft source files
- POSIX-compatible system (for file descriptor tests)
- Optional: Norminette (for code style checking)
- Optional: Valgrind (for memory leak detection)

## Installation Commands

```bash
# Install norminette
pip3 install --user norminette

# Install valgrind (Ubuntu/Debian)
sudo apt-get install valgrind

# Install valgrind (macOS)
brew install valgrind
```
