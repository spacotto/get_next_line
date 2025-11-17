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

## Testing
>[!TIP]
> Use the following command to create files with a specific amount of characters per line.

```< /dev/urandom tr -dc "[:print:]" | fold -w 5000 | head -c15000 > file.txt```

### Command Breakdown
`/dev/urandom` — A special file in Unix-like operating systems that provides **random numbers** from a cryptographically secure pseudorandom number generator (CSPRNG).

`"[:print:]"` — The ascii category of characters you want to include. 
- `alnum`: alphanumeric characters
- `alpha`: letters
- `upper`: uppercase letters
- `lower`: lowercase letters
- `digit`: digits
- 
