# About get_next_line
>[!CAUTION]
>The original project requires all the files to be at the **root**. Moreover, it DOES NOT require Makefiles. I use them to speed up the testing process.

### Definition
`char *get_next_line(int fd)`
>[!NOTE]
>A function that returns a line read from a file descriptor.

### Parameters
The file descriptor to read from.

### Return Value
**Read line**
- Standard behaviour
  
**NULL** 
- There is nothing else to read
- An error occurred
  - Invalid input
  - Read error

>[!NOTE]
> The returned line should include the terminating `\n` character, **except when the end of the file is reached** and the file does not end with a `\n` character.

### Flowchart
![flowchart](https://github.com/spacotto/get_next_line/blob/main/get_next_line_flowchart.png)

# Key Concepts
>[!CAUTION]
>When building the function, the majority of people start by reading into the buffer. However, it is better to assume that your buffer has already been filled, and you're looking for the next `\n`.

## Buffer
A buffer is a **temporary storage area in memory** used to hold data being transferred between different components.

Buffers are typically implemented as **arrays** or **pointers**, such as `char *buffer` or `char buffer`, and serve to temporarily store input or output data, reducing the need for constant direct access to external sources and thereby improving efficiency.

## File Descriptor (FD)
A file descriptor is an **integer value** that **uniquely identifies an open file or I/O** stream within a process, serving as a low-level handle for the operating system to manage access to resources such as files, sockets, and pipes. It is **returned** by the `open()` system call and is used with other low-level I/O functions like `read()`, `write()`, and `close()`.

The C language provides **three standard file descriptors** by default: 
- `0` for standard input (`stdin`);
- `1` for standard output (`stdout`);
- `2` for standard error (`stderr`).

File descriptors are managed through system calls: 
- `open()` opens a file and returns a descriptor;
- `read()` and `write()` perform I/O operations using the descriptor;
- `close()` terminates access and releases system resources.
A file descriptor value of `-1` indicates an **error** occurred during the operation.

## Static Variable
### Definition
A **static variable** is a variable that **retains its value** between function calls and exists **for the entire lifetime of the program**. It's allocated once in memory and persists until program termination. 

### Key Differences from Non-Static Variables
| Aspect            | Static Variables                         | Non-Static Variables                  |
| :---------------- | :--------------------------------------- | :------------------------------------ |
| Lifetime          | Entire program duration                  | Limited to **scope** (function/block) |
| Memory allocation | Once, at program start                   | Each time scope is entered            |
| Default value     | Initialised to 0 (if not explicitly set) | Contains garbage value                |
| Value persistence | Retained between calls                   | Lost when scope ceases to exit        |

>[!WARNING]
>If you use a static **structure**, you need to initialise all its elements in order.

### Common Use Cases
1. Function Call Counters
2. Singleton Pattern
3. Caching/Memoisation (optimisation)
4. Configuration Constants
5. State Preservation

# Testing
>[!IMPORTANT]
>For testing, I've created specific mains based on `(int argc, char **argv)`. This allows me to provide (1) the number of lines I want to get, and (2) the source files I want to use **without recompiling** every time. Hence, the **Makefile** creates a **program**, not a function archive.

>[!CAUTION]
>Both the buffer size and the line size can be of very different values. Thus, I've included a list of buffer and line sizes worth considering.

>[!TIP]
>Since the mandatory function does not support multiple fd management, I recommend creating a file containing all the line cases and reading it in full. On the other hand, to test the bonus function, it might be useful to create one file for each line typology.

## Test Cases

### Line Sizes
- No line (e.g.: an empty file)
- Empty line, as in a line made of `\n` only
- Small line (less than 10 bytes)
- Medium line (more than 10 bytes but less than 1024)
- Big line (more than 1024 bytes)

>[!TIP]
>For each line size, create a test file with (1) **only one** line and (2) the **same line repeated** multiple times.

### Buffer Sizes `-D BUFFER_SIZE=xxx`
- `BUFFER_SIZE` is the **minimum** size (1)
- `BUFFER_SIZE` is a **small** size (single-digit size != 1 but less than 10) 
- `BUFFER_SIZE` is a **medium** size (up to 1024 bytes)
- `BUFFER_SIZE` is a **large** size (more than 1024 bytes)
- `BUFFER_SIZE` is the **same length as the line**
- `BUFFER_SIZE` is **1 byte less** than the line
- `BUFFER_SIZE` is **1 byte more** than the line

## How to Generate Files
>[!TIP]
> Use the following command to create files with a specific number of characters per line.

```< /dev/urandom tr -dc "[:print:]" | fold -w 1024 | head -n 4 > file.txt```

### Command Breakdown
| Command Parameter | Description                                                                                                                                            |
| :---------------- | :----------------------------------------------------------------------------------------------------------------------------------------------------- |
| `/dev/urandom`    | A special file in Unix-like operating systems that provides **random numbers** from a cryptographically secure pseudorandom number generator (CSPRNG). |
| `"[:print:]"`     | The ASCII category of characters you want to include (printable characters in the example).                                                            | 
| `fold -w 1024`    | Fills lines with n characters (1024 in the example).                                                                                                   |
| `head -n 4`       | Outputs n amount of lines (4 in the example).                                                                                                          |
| `file.txt`        | Redirects the final output to a file (file.txt in the example).                                                                                        |

>[!NOTE]
>If you use `head -c` instead of `head -n`, you can set the **total amount of characters** included in the file.

>[!TIP]
>The available ascii categories of characters follow the same logic of the `isalpha` group of functions: `alnum` (alphanumeric characters), `alpha` (letters), `upper` (uppercase letters), `lower` (lowercase letters), `digit` (digits), `graph` (printable characters except space), `punct` (punctuation characters), `xdigit` (hexadecimal characters).
