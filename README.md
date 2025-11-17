# get_next_line
>[!IMPORTANT]
> Why get_next_line? It's a good way to introduce us to **static variables**.

## Static Variable
### Definition
A **static variable** is a variable that **retains its value** between function calls and exists **for the entire lifetime of the program**. It's allocated once in memory and persists until program termination. 

### Key Differences from Non-Static Variables
| Aspect            | Static Variables                         | Non-Static Variables                  |
| :---------------- | :--------------------------------------- | :------------------------------------ |
| Lifetime          | Entire program duration                  | Limited to **scope** (function/block) |
| Memory allocation | Once, at program start                   | Each time scope is entered            |
| Default value     | Initialized to 0 (if not explicitly set) | Contains garbage value                |
| Value persistence | Retained between calls                   | Lost when scope ceases to exit        |

### Common Use Cases
1. Function Call Counters
2. Singleton Pattern
3. Caching/Memoisation (optimisation)
4. Configuration Constants
5. State Preservation

## **Behaviour**
- **General Behaviour:** A function that returns a line read from a file descriptor
- **Parameters:** The file descriptor to read from.
- **Return value:**
  - Read line (correct behavior)
  - NULL (there is nothing else to read, or an error occurred)

>[!NOTE]
> The returned line should include the terminating `\n` character, **except when the end of the file is reached** and the file does not end with a `\n` character.

## Testing
>[!TIP]
> Use the following command to create files with a specific amount of characters per line.

```< /dev/urandom tr -dc "[:print:]" | fold -w 1024 | head -n 4 > file.txt```

### Command Breakdown
| Command Parameter | Description |
| :---------------- | :---------- |
| `/dev/urandom`    | A special file in Unix-like operating systems that provides **random numbers** from a cryptographically secure pseudorandom number generator (CSPRNG). |
| `"[:print:]"`     | The ascii category of characters you want to include (printable characters in the example).                                                            | 
| `fold -w 1024`    | Fills lines with n characters (1024 in the example).                                                                                                   |
| `head -n 4`       | Outputs n amount of lines (4 in the example).                                                                                                          |
| `file.txt`        | Redirects the final output to a file (file.txt in the example).                                                                                        |

>[!NOTE]
>If your use `head -c` instead of `head -n`, you can set the **total amount of characters** included in the file.

>[!TIP]
>The available ascii categories of characters follow the same logic of the `isalpha` group of functions: `alnum` (alphanumeric characters), `alpha` (letters), `upper` (uppercase letters), `lower` (lowercase letters), `digit` (digits), `graph` (printable characters except space), `punct` (punctuation characters), `xdigit` (hexadecimal characters). 
