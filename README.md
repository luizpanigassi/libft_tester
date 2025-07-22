# 📚 Libft - My C Standard Library Implementation

[![42 School](https://img.shields.io/badge/42-School-000000?style=flat&logo=42&logoColor=white)](https://42.fr/)
[![C](https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Norminette](https://img.shields.io/badge/Norminette-OK-brightgreen)](https://github.com/42School/norminette)
[![Tests](https://img.shields.io/badge/Tests-143%2F143-brightgreen)](#testing)

> A complete reimplementation of essential C standard library functions, plus additional utility functions for string manipulation, memory management, and linked list operations.

## 🎯 Project Overview

**Libft** is the first project at 42 School where we recreate some of the most important functions from the C standard library. This library serves as the foundation for many future projects at 42, teaching fundamental programming concepts like memory management, string manipulation, and data structures.

### ✨ Key Features

- 🔧 **34 Mandatory Functions** - Core libc functions reimplemented from scratch
- 🎁 **9 Bonus Functions** - Complete linked list manipulation suite
- 🧪 **Comprehensive Test Suite** - 143 automated tests with 100% pass rate
- 📖 **Full Documentation** - Detailed function descriptions and usage examples
- 🛡️ **Memory Safe** - No memory leaks, tested with Valgrind
- ✅ **Norminette Compliant** - Follows 42's strict coding standards

## 📋 Function Categories

<details>
<summary><b>🔤 Character Classification & Conversion (7 functions)</b></summary>

| Function | Description | Standard Equivalent |
|----------|-------------|-------------------|
| `ft_isalpha` | Checks if character is alphabetic | `isalpha` |
| `ft_isdigit` | Checks if character is a digit | `isdigit` |
| `ft_isalnum` | Checks if character is alphanumeric | `isalnum` |
| `ft_isascii` | Checks if character is ASCII | `isascii` |
| `ft_isprint` | Checks if character is printable | `isprint` |
| `ft_toupper` | Converts to uppercase | `toupper` |
| `ft_tolower` | Converts to lowercase | `tolower` |

</details>

<details>
<summary><b>🧵 String Manipulation (13 functions)</b></summary>

| Function | Description | Standard Equivalent |
|----------|-------------|-------------------|
| `ft_strlen` | Calculate string length | `strlen` |
| `ft_strchr` | Locate character in string | `strchr` |
| `ft_strrchr` | Locate character from end | `strrchr` |
| `ft_strncmp` | Compare strings (n bytes) | `strncmp` |
| `ft_strlcpy` | Safe string copy | `strlcpy` |
| `ft_strlcat` | Safe string concatenation | `strlcat` |
| `ft_strnstr` | Locate substring | `strnstr` |
| `ft_strdup` | Duplicate string | `strdup` |
| `ft_substr` | Extract substring | *(custom)* |
| `ft_strjoin` | Join two strings | *(custom)* |
| `ft_strtrim` | Trim characters from string | *(custom)* |
| `ft_split` | Split string by delimiter | *(custom)* |
| `ft_strmapi` | Apply function to each character | *(custom)* |
| `ft_striteri` | Apply function to each character (void) | *(custom)* |

</details>

<details>
<summary><b>🧠 Memory Management (6 functions)</b></summary>

| Function | Description | Standard Equivalent |
|----------|-------------|-------------------|
| `ft_memset` | Fill memory with byte value | `memset` |
| `ft_bzero` | Set memory to zero | `bzero` |
| `ft_memcpy` | Copy memory area | `memcpy` |
| `ft_memmove` | Copy memory (handles overlap) | `memmove` |
| `ft_memchr` | Locate byte in memory | `memchr` |
| `ft_memcmp` | Compare memory areas | `memcmp` |
| `ft_calloc` | Allocate and zero memory | `calloc` |

</details>

<details>
<summary><b>🔄 Conversion Functions (2 functions)</b></summary>

| Function | Description | Standard Equivalent |
|----------|-------------|-------------------|
| `ft_atoi` | String to integer | `atoi` |
| `ft_itoa` | Integer to string | *(custom)* |

</details>

<details>
<summary><b>📄 File Descriptor Functions (4 functions)</b></summary>

| Function | Description |
|----------|-------------|
| `ft_putchar_fd` | Output character to file descriptor |
| `ft_putstr_fd` | Output string to file descriptor |
| `ft_putendl_fd` | Output string + newline to file descriptor |
| `ft_putnbr_fd` | Output number to file descriptor |

</details>

<details>
<summary><b>🔗 Linked List Functions - Bonus (9 functions)</b></summary>

| Function | Description |
|----------|-------------|
| `ft_lstnew` | Create new list element |
| `ft_lstadd_front` | Add element at beginning |
| `ft_lstadd_back` | Add element at end |
| `ft_lstsize` | Count list elements |
| `ft_lstlast` | Return last element |
| `ft_lstdelone` | Delete single element |
| `ft_lstclear` | Delete entire list |
| `ft_lstiter` | Apply function to each element |
| `ft_lstmap` | Apply function and create new list |

</details>

## 🚀 Quick Start

### Prerequisites
- GCC compiler
- Make
- Git

### Installation

```bash
# Clone the repository
git clone https://github.com/yourusername/libft.git
cd libft

# Build the library
make

# The static library libft.a is now ready to use!
```

### Usage Example

```c
#include "libft.h"
#include <stdio.h>

int main(void)
{
    char *str = ft_strdup("Hello, 42!");
    char *trimmed = ft_strtrim("   Hello World   ", " ");
    char **split = ft_split("apple,banana,cherry", ',');
    
    printf("Original: %s\n", str);
    printf("Trimmed: %s\n", trimmed);
    printf("Split[0]: %s\n", split[0]);
    
    free(str);
    free(trimmed);
    // Don't forget to free split array...
    
    return (0);
}
```

Compile with your program:
```bash
gcc -Wall -Wextra -Werror main.c -L. -lft -o my_program
```

## 🧪 Testing

This project includes a comprehensive test suite with **143 tests** covering all functions.

### Running Tests

```bash
# Navigate to test directory
cd tester

# Run all tests (mandatory + bonus)
./run_tests.sh

# Run only mandatory function tests  
./run_tests.sh --mandatory

# Run with memory leak detection
./run_tests.sh --valgrind
```

### Test Results
- ✅ **143/143 tests passing**
- ✅ **Zero memory leaks**
- ✅ **All edge cases covered**
- ✅ **Norminette compliant**

![Test Results](https://img.shields.io/badge/Tests-143%2F143%20Passed-brightgreen)

## 📁 Project Structure

```
libft/
├── 📄 libft.h           # Header file with all prototypes
├── 🔧 Makefile          # Build system
├── 📚 README.md         # This file
├── 📝 README_TESTER.md  # Test overview
├── 🗂️ ft_*.c            # Source files (42 functions)
└── 🧪 tester/           # Comprehensive test suite
    ├── test_libft.c     # Main test file
    ├── Makefile.test    # Test build system  
    ├── run_tests.sh     # Test runner script
    └── README_TESTS.md  # Detailed test documentation
```

## 🛠️ Build System

The Makefile includes all standard targets:

```bash
make          # Build libft.a
make clean    # Remove object files
make fclean   # Remove object files and libft.a
make re       # Rebuild everything
make bonus    # Build with bonus functions
```

### Compiler Flags
- `-Wall -Wextra -Werror` - Maximum warning level
- Norminette compliant code style
- No global variables
- No forbidden functions

## 🔧 Implementation Details

### Memory Management
- All heap-allocated memory is properly freed
- No buffer overflows or memory leaks
- Robust error handling for malloc failures

### String Functions
- Safe string operations with length bounds
- Proper handling of NULL pointers
- Efficient algorithms optimized for common use cases

### Linked Lists
- Generic `void *` content for maximum flexibility
- Complete CRUD operations
- Functional programming approach with map/iter functions

## 📖 Documentation

Each function is thoroughly documented with:
- Purpose and behavior description
- Parameter specifications
- Return value details
- Usage examples
- Edge case handling

## 🎓 Learning Objectives

This project taught me:
- **Memory Management**: Dynamic allocation, avoiding leaks
- **String Manipulation**: Safe and efficient string operations  
- **Data Structures**: Implementing and manipulating linked lists
- **Algorithm Design**: Optimizing for performance and readability
- **Testing**: Writing comprehensive test suites
- **Documentation**: Creating clear, professional documentation

## 🔍 Key Challenges Solved

1. **ft_split**: Dynamic memory allocation for variable-length arrays
2. **ft_strtrim**: Efficient trimming from both ends
3. **ft_lstmap**: Functional list transformation with error handling
4. **Memory Safety**: Zero leaks across all 143 tests
5. **Edge Cases**: Handling NULL pointers, empty strings, boundary conditions

## 📊 Code Quality

- ✅ **0 compilation warnings**
- ✅ **0 memory leaks** (Valgrind tested)
- ✅ **100% Norminette compliance**
- ✅ **Comprehensive error handling**
- ✅ **Optimized algorithms**

## 🤝 Contributing

This is a 42 School project, but feedback and suggestions are welcome! Feel free to:
- Report bugs
- Suggest improvements
- Share your own implementations

## 📜 License

This project is part of the 42 School curriculum. Feel free to study the code, but please don't copy it for your own 42 projects. Learning comes from doing! 🎓

## 👨‍💻 Author

**luinasci** - [42 Student](https://profile.intra.42.fr/users/luinasci)

---
