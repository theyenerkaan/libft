# libft - Custom C Standard Library

A comprehensive reimplementation of essential C standard library functions, built from scratch as part of 42 School's curriculum. This project provides a solid foundation for future C projects with memory-safe, well-tested utility functions covering string manipulation, memory operations, character checks, and linked list management.

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Project Structure](#project-structure)
- [Installation](#installation)
- [Usage](#usage)
- [Technical Details](#technical-details)
- [Function Reference](#function-reference)
- [Limitations & Notes](#limitations--notes)
- [License](#license)

## Overview

`libft` is a foundational C library project that reimplements critical functions from the standard C library (`libc`) without using the originals. This project serves as both a learning exercise in low-level C programming and a reusable library for future 42 projects.

**Problem solved**: Provides developers with a custom, portable, and well-understood implementation of standard library functions, eliminating the "black box" nature of system libraries and ensuring predictable behavior across platforms.

**Why it exists**: 
- Master memory management and pointer manipulation
- Understand the implementation details of standard library functions
- Build a personal toolkit for future C projects
- Demonstrate proficiency in systems programming fundamentals

**High-level behavior**: The library compiles into a static archive (`libft.a`) that can be linked with any C program, providing drop-in replacements for standard functions plus additional utility functions for string processing and linked list operations.

## Features

### Standard Library Functions (libc)

**Character Classification & Conversion**
- Character type checking (alpha, digit, alnum, ascii, print)
- Case conversion (toupper, tolower)

**String Manipulation**
- String length, comparison, and searching
- String copying with size limits (strlcpy, strlcat)
- String duplication and substring extraction
- Character search (strchr, strrchr, strnstr)

**Memory Operations**
- Raw memory manipulation (memset, memcpy, memmove)
- Memory comparison and searching (memcmp, memchr)
- Zero-initialization (bzero, calloc)

**Type Conversion**
- String to integer (atoi)
- Integer to string (itoa)

### Additional Utility Functions

**Advanced String Operations**
- `ft_substr` - Extract substring with bounds checking
- `ft_strjoin` - Concatenate two strings into new allocation
- `ft_strtrim` - Remove specified characters from string ends
- `ft_split` - Split string by delimiter into array
- `ft_strmapi` - Apply function to each character
- `ft_striteri` - Apply function with index to each character

**File Descriptor Output**
- `ft_putchar_fd` - Write character to file descriptor
- `ft_putstr_fd` - Write string to file descriptor
- `ft_putendl_fd` - Write string with newline to file descriptor
- `ft_putnbr_fd` - Write integer to file descriptor

### Bonus: Linked List Implementation

**Single-Linked List Operations**
- `ft_lstnew` - Create new list node
- `ft_lstadd_front` / `ft_lstadd_back` - Add nodes at list ends
- `ft_lstsize` - Count list elements
- `ft_lstlast` - Get last node
- `ft_lstdelone` - Delete single node with custom deleter
- `ft_lstclear` - Clear entire list with custom deleter
- `ft_lstiter` - Iterate over list applying function
- `ft_lstmap` - Map function over list creating new list

## Project Structure

```
libft/
├── libft.h                    # Header with all function prototypes
├── Makefile                   # Build configuration
│
├── ft_isalpha.c              # Character classification functions
├── ft_isdigit.c
├── ft_isalnum.c
├── ft_isascii.c
├── ft_isprint.c
├── ft_toupper.c
├── ft_tolower.c
│
├── ft_strlen.c               # String manipulation functions
├── ft_strchr.c
├── ft_strrchr.c
├── ft_strncmp.c
├── ft_strlcpy.c
├── ft_strlcat.c
├── ft_strnstr.c
├── ft_strdup.c
│
├── ft_memset.c               # Memory operation functions
├── ft_bzero.c
├── ft_memcpy.c
├── ft_memmove.c
├── ft_memchr.c
├── ft_memcmp.c
├── ft_calloc.c
│
├── ft_atoi.c                 # Conversion functions
├── ft_itoa.c
│
├── ft_substr.c               # Additional string utilities
├── ft_strjoin.c
├── ft_strtrim.c
├── ft_split.c
├── ft_strmapi.c
├── ft_striteri.c
│
├── ft_putchar_fd.c           # File descriptor output
├── ft_putstr_fd.c
├── ft_putendl_fd.c
├── ft_putnbr_fd.c
│
└── ft_lst*_bonus.c           # Linked list functions (bonus)
    ├── ft_lstnew_bonus.c
    ├── ft_lstadd_front_bonus.c
    ├── ft_lstsize_bonus.c
    ├── ft_lstlast_bonus.c
    ├── ft_lstadd_back_bonus.c
    ├── ft_lstdelone_bonus.c
    ├── ft_lstclear_bonus.c
    ├── ft_lstiter_bonus.c
    └── ft_lstmap_bonus.c
```

### Key Components

**libft.h** - Central header file containing:
- All function prototypes
- `t_list` structure definition for linked lists
- Required standard library includes (`stdlib.h`, `unistd.h`)

**Makefile** - Automated build system with targets:
- `make` / `make all` - Compile mandatory functions
- `make bonus` - Compile with bonus linked list functions
- `make clean` - Remove object files
- `make fclean` - Remove objects and library archive
- `make re` - Rebuild from scratch

## Installation

### Prerequisites

- **Compiler**: GCC or Clang
- **Build System**: GNU Make
- **OS**: Any UNIX-like system (Linux, macOS, BSD)

### Building the Library

```bash
# Clone the repository
git clone <repository-url>
cd libft

# Build mandatory functions only
make

# Build with bonus functions (linked lists)
make bonus

# Clean build artifacts
make clean

# Remove all generated files
make fclean

# Rebuild from scratch
make re
```

### Compilation Output

- **libft.a** - Static library archive ready for linking
- **\*.o** - Object files (intermediate compilation artifacts)

## Usage

### Linking with Your Project

```bash
# Compile your project with libft
gcc -Wall -Wextra -Werror main.c -L. -lft -o my_program

# Or include object files directly
gcc -Wall -Wextra -Werror main.c libft.a -o my_program
```

### Integration Example

```c
#include "libft.h"
#include <stdio.h>

int main(void)
{
    char *str;
    char **split_result;
    int i;

    // String duplication with memory allocation
    str = ft_strdup("Hello, World!");
    printf("Duplicated: %s\n", str);
    free(str);

    // String splitting into array
    split_result = ft_split("apple,banana,cherry", ',');
    i = 0;
    while (split_result[i])
    {
        printf("Token %d: %s\n", i, split_result[i]);
        free(split_result[i]);
        i++;
    }
    free(split_result);

    // Integer conversion
    printf("atoi(\"42\"): %d\n", ft_atoi("42"));
    
    str = ft_itoa(-2147483648);
    printf("itoa(INT_MIN): %s\n", str);
    free(str);

    // Linked list operations (bonus)
    t_list *list = ft_lstnew("First");
    ft_lstadd_back(&list, ft_lstnew("Second"));
    ft_lstadd_back(&list, ft_lstnew("Third"));
    printf("List size: %d\n", ft_lstsize(list));

    return 0;
}
```

### Common Use Cases

**String Processing:**
```c
char *trimmed = ft_strtrim("  Hello  ", " ");
char *joined = ft_strjoin("Hello, ", "World!");
char *sub = ft_substr("Hello World", 6, 5); // "World"
```

**Memory Operations:**
```c
char buffer[100];
ft_memset(buffer, 0, sizeof(buffer));
ft_memcpy(dest, src, 50);
```

**File Output:**
```c
ft_putstr_fd("Error: ", 2);  // stderr
ft_putnbr_fd(errno, 2);
ft_putchar_fd('\n', 2);
```

## Technical Details

### Compilation Flags

```makefile
CFLAGS = -Wall -Wextra -Werror
```

- **-Wall**: Enable all standard warnings
- **-Wextra**: Enable extra warning checks
- **-Werror**: Treat all warnings as errors (enforces clean code)

### Memory Management Philosophy

**Manual Memory Management:**
- All dynamically allocated strings must be freed by caller
- Functions return `NULL` on allocation failures
- No hidden allocations or memory leaks
- Clear ownership semantics documented

**Safety Patterns:**
```c
// NULL pointer checks before dereferencing
if (!dst && !src)
    return (NULL);

// Allocation failure handling
new = malloc(sizeof(type));
if (!new)
    return (NULL);

// Proper cleanup on error paths
if (!result) {
    free(intermediate);
    return (NULL);
}
```

### Key Algorithms & Techniques

#### ft_split - String Tokenization
**Algorithm:**
1. Count delimiters to determine array size
2. Allocate array of string pointers
3. For each token: calculate length, allocate, copy
4. On allocation failure: free all previous allocations (no leaks)

**Complexity:**
- Time: O(n) where n = string length
- Space: O(n) for token storage

#### ft_memmove - Overlap-Safe Memory Copy
**Algorithm:**
- Detects memory overlap direction
- Copies forward if `dst < src`, backward if `dst > src`
- Prevents data corruption during overlapping copies

**Why not ft_memcpy?**
- `memcpy` undefined behavior on overlaps
- `memmove` guarantees correctness for all cases

#### ft_itoa - Integer to String Conversion
**Algorithm:**
1. Handle edge case: INT_MIN (-2147483648)
2. Count digits including sign
3. Allocate string buffer
4. Fill buffer from right to left (reverse digit extraction)

**Edge cases handled:**
- Negative numbers (including INT_MIN)
- Zero
- Maximum positive integers

### Linked List Implementation (Bonus)

**Structure Definition:**
```c
typedef struct s_list
{
    void            *content;  // Generic data pointer
    struct s_list   *next;     // Next node pointer
}                   t_list;
```

**Design Decisions:**
- **Generic content**: Uses `void*` for type flexibility
- **Single-linked**: Forward traversal only (simpler, less memory)
- **No sentinel nodes**: NULL indicates list end
- **Custom deleters**: User provides cleanup function for content

**Memory Management:**
```c
// Creating and destroying lists
t_list *node = ft_lstnew(data);
ft_lstdelone(node, free);     // Delete single node
ft_lstclear(&head, free);     // Delete entire list
```

### Function Pointer Usage

Several functions use function pointers for flexibility:

```c
// ft_strmapi: transform each character
char transform(unsigned int i, char c) {
    return c + i;  // Example transformation
}
char *result = ft_strmapi("abc", transform);

// ft_lstiter: apply action to each node
void print_content(void *content) {
    printf("%s\n", (char*)content);
}
ft_lstiter(list, print_content);

// ft_lstmap: map function over list
void *duplicate_string(void *content) {
    return ft_strdup((char*)content);
}
t_list *new_list = ft_lstmap(list, duplicate_string, free);
```

### Performance Considerations

**Optimized Implementations:**
- **ft_memcpy**: Byte-by-byte copy (simple, portable)
- **ft_strlen**: Single-pass linear scan
- **ft_split**: Single allocation per token (no realloc)

**Trade-offs:**
- Prioritizes correctness and readability over micro-optimizations
- No assembly or SIMD optimizations (portability)
- Suitable for general-purpose use, not performance-critical paths

## Function Reference

### Character Functions (9 functions)
| Function | Description | Returns |
|----------|-------------|---------|
| `ft_isalpha` | Check if alphabetic | 1 if true, 0 otherwise |
| `ft_isdigit` | Check if digit (0-9) | 1 if true, 0 otherwise |
| `ft_isalnum` | Check if alphanumeric | 1 if true, 0 otherwise |
| `ft_isascii` | Check if ASCII (0-127) | 1 if true, 0 otherwise |
| `ft_isprint` | Check if printable | 1 if true, 0 otherwise |
| `ft_toupper` | Convert to uppercase | Uppercase character |
| `ft_tolower` | Convert to lowercase | Lowercase character |

### String Functions (13 functions)
| Function | Description | Returns |
|----------|-------------|---------|
| `ft_strlen` | Calculate string length | Length (size_t) |
| `ft_strchr` | Find first char occurrence | Pointer or NULL |
| `ft_strrchr` | Find last char occurrence | Pointer or NULL |
| `ft_strncmp` | Compare strings (n bytes) | Difference value |
| `ft_strlcpy` | Copy string with size limit | Copied length |
| `ft_strlcat` | Concatenate with size limit | Total length |
| `ft_strnstr` | Find substring (n bytes) | Pointer or NULL |
| `ft_strdup` | Duplicate string | New string or NULL |
| `ft_substr` | Extract substring | New string or NULL |
| `ft_strjoin` | Concatenate two strings | New string or NULL |
| `ft_strtrim` | Trim characters from ends | New string or NULL |
| `ft_split` | Split by delimiter | Array of strings or NULL |
| `ft_strmapi` | Map function over string | New string or NULL |
| `ft_striteri` | Apply function with index | void |

### Memory Functions (6 functions)
| Function | Description | Returns |
|----------|-------------|---------|
| `ft_memset` | Fill memory with byte | Pointer to memory |
| `ft_bzero` | Zero-fill memory | void |
| `ft_memcpy` | Copy memory (no overlap) | Destination pointer |
| `ft_memmove` | Copy memory (overlap-safe) | Destination pointer |
| `ft_memchr` | Search byte in memory | Pointer or NULL |
| `ft_memcmp` | Compare memory regions | Difference value |
| `ft_calloc` | Allocate zero-initialized | Pointer or NULL |

### Conversion Functions (2 functions)
| Function | Description | Returns |
|----------|-------------|---------|
| `ft_atoi` | String to integer | Integer value |
| `ft_itoa` | Integer to string | New string or NULL |

### File Descriptor Functions (4 functions)
| Function | Description | Returns |
|----------|-------------|---------|
| `ft_putchar_fd` | Write char to FD | void |
| `ft_putstr_fd` | Write string to FD | void |
| `ft_putendl_fd` | Write string + newline to FD | void |
| `ft_putnbr_fd` | Write integer to FD | void |

### Linked List Functions - Bonus (9 functions)
| Function | Description | Returns |
|----------|-------------|---------|
| `ft_lstnew` | Create new node | New node or NULL |
| `ft_lstadd_front` | Add node at beginning | void |
| `ft_lstadd_back` | Add node at end | void |
| `ft_lstsize` | Count list nodes | Size (int) |
| `ft_lstlast` | Get last node | Last node or NULL |
| `ft_lstdelone` | Delete single node | void |
| `ft_lstclear` | Delete entire list | void |
| `ft_lstiter` | Iterate applying function | void |
| `ft_lstmap` | Map function creating new list | New list or NULL |

## Limitations & Notes

### Known Limitations

1. **No thread safety**: Functions use no synchronization primitives
   - Not safe for concurrent access from multiple threads
   - Caller must implement locking if needed

2. **No wide character support**: Only standard ASCII/char
   - No `wchar_t` or Unicode handling
   - Limited to single-byte character encodings

3. **Static allocations in ft_itoa**: Fixed buffer size
   - Sufficient for 32-bit integers
   - Would need modification for 64-bit or arbitrary precision

4. **Linked list is single-linked only**
   - No backward traversal
   - No doubly-linked list implementation
   - O(n) access to arbitrary elements

5. **No locale support**: Character functions assume C locale
   - `toupper`/`tolower` only handle ASCII
   - No locale-aware string comparison

### Edge Cases Handled

**Memory Safety:**
- NULL pointer checks in all functions
- Allocation failure returns NULL consistently
- No buffer overflows (all copies size-limited)

**Numeric Edge Cases:**
- `ft_atoi`: Handles INT_MIN/INT_MAX, leading whitespace, signs
- `ft_itoa`: Special handling for INT_MIN (-2147483648)
- Overflow behavior matches standard library

**String Edge Cases:**
- Empty strings ("") handled correctly
- Zero-length operations return valid results
- Overlapping memory regions (ft_memmove)

### 42 School Constraints

**Mandatory Requirements:**
- **Norm compliant**: Strict coding standards (25 lines per function, etc.)
- **No forbidden functions**: Only approved libc functions allowed
- **No memory leaks**: Verified with Valgrind/leak sanitizer
- **Compilation flags**: Must compile with `-Wall -Wextra -Werror`
- **Makefile rules**: Must not relink unnecessarily

**Bonus Requirements:**
- Linked list functions in separate `*_bonus.c` files
- Must compile without affecting mandatory part
- Additional data structures beyond requirements

## Best Practices Demonstrated

### Code Quality
- **Consistent naming**: All functions prefixed with `ft_`
- **Clear interfaces**: Simple, predictable function signatures
- **Documentation**: Header file serves as complete reference
- **Modularity**: One function per file (easy to maintain)

### Memory Management
- **Explicit ownership**: Caller always owns returned allocations
- **Defensive programming**: Check all allocations, handle failures
- **No hidden state**: Functions are pure where possible
- **Proper cleanup**: Helper functions for error paths (e.g., `delete` in ft_split)

### Portability
- **Standard C**: No compiler-specific extensions
- **POSIX compatible**: Uses only standard headers
- **Endian-neutral**: Byte-by-byte operations
- **Platform independent**: No OS-specific code

## Testing Recommendations

```bash
# Compile with debugging symbols
gcc -Wall -Wextra -Werror -g main.c libft.a -o test

# Run with memory leak detection
valgrind --leak-check=full --show-leak-kinds=all ./test

# Run with address sanitizer
gcc -Wall -Wextra -Werror -fsanitize=address main.c libft.a -o test
./test
```

## License

This project is for educational purposes as part of the 42 School curriculum. The implementation is original work adhering to strict academic integrity standards.

---

**Technical Highlights for Recruiters:**

This project demonstrates proficiency in:
- **Systems programming fundamentals** - Low-level C implementation of standard library
- **Memory management** - Manual allocation, deallocation, and leak prevention
- **Data structures** - Linked list implementation with generic content
- **Algorithm implementation** - String parsing, tokenization, memory operations
- **API design** - Clean, consistent interfaces following Unix conventions
- **Build automation** - Makefile with proper dependency management
- **Code quality** - Norm-compliant, warning-free compilation
- **Edge case handling** - Robust input validation and error handling

Relevant for roles in: **Systems Programming, Embedded Systems, Operating Systems Development, C/C++ Development, Low-Level Libraries, Kernel Development, Firmware Engineering**
