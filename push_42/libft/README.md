*This project has been created as part of the 42 curriculum by criredon.*

# Libft
 
## Description
 
Libft is the first project of the 42 Common Core.
Its objective is to reimplement a subset of the C Standard Library while building a solid understanding of memory management, pointers, strings, and linked lists.

### Features Overview
 
The library currently provides usefull functions for different purposes: character handling, string inspection, string manipulation, memory management, data conversion, file descriptor output, and linked list utilities.
 
#### Character Classification
 
| Function | Description |
|----------|-------------|
| `ft_isalpha` | Checks whether a character is alphabetic. |
| `ft_isdigit` | Checks whether a character is a decimal digit. |
| `ft_isalnum` | Checks whether a character is alphanumeric. |
| `ft_isascii` | Checks whether a character belongs to the ASCII set. |
| `ft_isprint` | Checks whether a character is printable, including space. |
 
#### Character Conversion
 
| Function | Description |
|----------|-------------|
| `ft_toupper` | Converts a lowercase letter to uppercase. |
| `ft_tolower` | Converts an uppercase letter to lowercase. |
 
#### String Inspection
 
| Function | Description |
|----------|-------------|
| `ft_strlen` | Returns the number of characters in a string (length). |
| `ft_strchr` | Returns a pointer to the first occurrence of a character in a string. |
| `ft_strrchr` | Returns a pointer to the last occurrence of a character in a string. |
| `ft_strnstr` | Searches for a substring within the first *n* characters of a string. |
| `ft_strncmp` | Compares two strings up to *n* characters. |
 
#### String Manipulation
 
| Function | Description |
|----------|-------------|
| `ft_strlcpy` | Copies a string into a destination buffer with size protection. |
| `ft_strlcat` | Appends a string to a destination buffer with size protection. |
| `ft_strdup` | Allocates and returns a duplicate of a string. |
| `ft_substr` | Allocates and returns a substring starting at a given index. |
| `ft_strjoin` | Allocates and returns the concatenation of two strings. |
| `ft_strtrim` | Allocates and returns a string after removing a specific character. |
| `ft_split` | Splits a string into an array using a delimiter character. |
| `ft_strmapi` | Creates a new string by applying a function to each character. |
| `ft_striteri` | Applies a function to each character of a string. |
 
#### Memory Management
 
| Function | Description |
|----------|-------------|
| `ft_bzero` | Sets a block of memory to zero. |
| `ft_memset` | Fills a block of memory with a specified byte value. |
| `ft_memcpy` | Copies a block of memory between non-overlapping regions. |
| `ft_memmove` | Copies a block of memory safely between overlapping regions. |
| `ft_memchr` | Searches for the first occurrence of a byte within a memory block. |
| `ft_memcmp` | Compares two memory blocks byte by byte. |
| `ft_calloc` | Allocates memory for an array and initializes it to zero. |
 
#### Data Conversion
 
| Function | Description |
|----------|-------------|
| `ft_atoi` | Converts the initial portion of a string to an integer. |
| `ft_itoa` | Allocates and returns the string representation of an integer. |
 
#### File Descriptor Output
 
| Function | Description |
|----------|-------------|
| `ft_putchar_fd` | Writes a character to a file descriptor. |
| `ft_putstr_fd` | Writes a string to a file descriptor. |
| `ft_putendl_fd` | Writes a string followed by a newline to a file descriptor. |
| `ft_putnbr_fd` | Writes the decimal of an integer to a file descriptor. |

 
#### Linked Lists
 
| Function | Description |
|----------|-------------|
| `ft_lstnew` | Creates a new linked list node. |
| `ft_lstadd_front` | Inserts a node at the beginning of a list. |
| `ft_lstadd_back` | Appends a node to the end of a list. |
| `ft_lstsize` | Returns the number of nodes in a list. |
| `ft_lstlast` | Returns the last node of a list. |
| `ft_lstdelone` | Deletes a single node using the provided delete function. |
| `ft_lstclear` | Deletes and frees all nodes in a list. |
| `ft_lstiter` | Applies a function to the content of every node in a list. |
| `ft_lstmap` | Creates a new list by applying a function to each node of an existing list. |

## Instructions
 
```bash
make          # compile and build libft.a
make clean    # remove object files
make fclean   # remove object files and libft.a
make re       # rebuild the project
```
### Output

Successfull compilation generates the static library: libft.a

To use in another project:
```bash
cc -Wall -Wextra -Werror your_file.c libft.a -o output
```

## Resources

### References

The implementation of this project is based on the official 42 project specification and supported by trusted references for the C language. The main references were:

**42 Piscine** | Notes, exercises, and concepts acquired during the 42 Piscine, serving as the foundation for many of the algorithms and coding practices used in this project.

**42 Libft Subject** Official project specification defining the required functions, authorized library calls, coding constraints, and evaluation criteria. https://github.com/42school/norminette

**The Open Group POSIX.1-2024** Official POSIX specification describing the behavior of standard C library functions and UNIX system interfaces. https://pubs.opengroup.org/onlinepubs/9799919799/nframe.html

**Harvard CS50x** Harvard University's Introduction to Computer Science. Its C programming module provides an excellent foundation for memory, pointers, algorithms, and systems programming. https://cs50.harvard.edu/x/

### AI usage

Artificial Intelligence was used as a learning companion throughout the development of this project. All implementations were manually written, reviewed, tested, and understood before being committed. AI tools such Claude, Chat GPT and Gemini were used for:

- Explaining C language concepts (pointers, memory management, recursion, etc.).
- Clarifying the behavior of standard libc and POSIX functions.
- Discussing algorithms before implementation.
- Identifying edge cases and test scenarios.
- Explaining compiler errors, warnings, and undefined behavior.
- Assisting in writing project documentation (`README.md` and function manuals).

The final code, as well as the algorithmic logic, the design decisions, and the implementation of edge case tests were completed made by the author.

## Author

**Cristina Redondo (criredon)**  
42 Madrid