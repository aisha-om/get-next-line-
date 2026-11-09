*This project has been created as part of the 42 curriculum by aabufarw.*

# get_next_line

## Description

`get_next_line` is a project at 42 that consists of writing a C function that reads a line from a file descriptor, returning one line at a time until reaching the end of the file or encountering an error.

The main goal of this project is to learn about **static variables** in C, dynamic memory allocation, buffer management, and efficiently handling multiple file descriptors.

---

## Instructions

### 1. Using it in your code

To use the function in your code, simply include its header:

```c
#include "get_next_line.h"
```

And, when compiling your code, add the source files along with the required `BUFFER_SIZE` macro flag:

```shell
cc -Wall -Wextra -Werror -D BUFFER_SIZE=<size> get_next_line.c get_next_line_utils.c main.c
```

### 2. Testing

You only have to edit the `get_next_line.c` file and uncomment the `main` function and headers inside it (or use a separate `main.c` file). You can edit `test.txt` to put another text if you wish to test other cases.

**Mandatory Part Execution:**

```shell
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=xx get_next_line.c get_next_line_utils.c && ./a.out
```

**Bonus Part Execution:**

```shell
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=xx get_next_line_bonus.c get_next_line_utils_bonus.c && ./a.out
```
*(Replace `xx` with your desired buffer size).*

---

## Third-Party Testers & Tools

You can also use these third-party testing suites and containers to fully test the project:

* [Tripouille/gnlTester](https://github.com/Tripouille/gnlTester) — Automated unit tests for mandatory and bonus parts.
* [opsec-infosec/42-ValgrindContainer](https://github.com/opsec-infosec/42-ValgrindContainer) — Containerized environment for testing memory leaks with Valgrind.

---

### Algorithm Explanation & Justification

### Selected Approach: Static Stash Buffer

#### 1. Overview
The algorithm behind `get_next_line` relies on a **static variable** acting as a persistent buffer stash across multiple function calls. The function continuously reads blocks of data of size `BUFFER_SIZE` using `read()` into a temporary buffer and appends them to the static stash until a newline character (`\n`) or End-of-File (`EOF`) is detected.

#### 2. Justification & Complexity Analysis
* **Time Complexity:** $O(N)$ where $N$ is the number of characters read until a newline character or EOF is encountered. Line extraction operates in linear time.
* **Space Complexity:** $O(B + L)$ where $B$ is the `BUFFER_SIZE` and $L$ is the length of the extracted line preserved in memory.
* **Memory Management:** Memory allocated during read cycles is pruned immediately after extracting a line. Remaining data stays in the static stash, ensuring zero memory leaks upon function completion or unexpected read errors.

#### 3. Flow of Execution
1. **Validation:** Verifies valid parameters (`fd >= 0`, `BUFFER_SIZE > 0`, and valid read buffer).
2. **Buffer Reading:** Executes `read(fd, buffer, BUFFER_SIZE)` iteratively, joining bytes into the static stash until a `\n` or EOF is present.
3. **Line Extraction:** Slices the stash string up to and including the first `\n`.
4. **Stash Update:** Preserves the remaining unread text after `\n` in the static stash for the next call.

---

## Resources

### Documentation & References

* [C Static Variables - GeeksforGeeks](https://www.geeksforgeeks.org/static-variables-in-c/)
* [Linux Programmer's Manual - `read(2)`](https://man7.org/linux/man-pages/man2/read.2.html)
* [42 Norm Guidelines](https://github.com/42School/norminette)

### AI Usage Disclosure

AI (Large Language Model) assistance was used during this project for:

* **Debugging & Edge-Case Analysis:** Identifying edge cases such as memory leak pathways when handling invalid file descriptors or premature `read()` errors.
* **Documentation Structuring:** Formatting and organizing the `README.md` file in compliance with 42 curriculum standards.

*No core algorithms or function implementations were blindly copied; all logic was implemented, reviewed, and tested independently.*
