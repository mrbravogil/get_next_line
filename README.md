# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    README.md                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#   By: mabravo- <mabravo-@student.42malaga.com>   +#+  +:+       +#+          #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/15 13:58:07 by mabravo-          #+#    #+#              #
#    Updated: 2025/12/15 13:58:10 by mabravo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

_This project has been created as part of the 42 curriculum by mabravo-_

# GET_NEXT_LINE

## Description
**get_next_line** is a 42 Common Core project whose objective is to implement a function capable of reading a file descriptor line by line.  
Each call to the function returns the next line of a file, including the terminating newline character (`\n`) when present, until the end of file is reached.

The main challenge of this project lies in handling buffered input, memory management, and preserving unread data between function calls using static variables.

This project strengthens understanding of:
- File descriptors and the `read()` system call
- Static variables in C
- Dynamic memory allocation
- String manipulation
- Pointer and double-pointer logic

## Algorithm Explanation

The algorithm is based on incremental buffered reading combined with persistent state tracking.

Core Idea

- Read chunks of data of size BUFFER_SIZE from a file descriptor.

- Accumulate the data until a newline (\n) is found.

- Return the line up to and including the newline.

- Preserve any remaining data for the next function call.

Key Design Decisions
1. Static Buffer (src)

A static pointer is used to store leftover data between calls.
This allows the function to remember unread characters without re-reading the file.

2. Buffered Reading (fill_line)

The function repeatedly reads from the file descriptor and appends the data to src until:

- A newline is found, or

- End of file is reached.

This ensures efficiency by minimizing system calls.

3. Line Extraction (left_line)

Once enough data is available:

- The current line is extracted.

- The remaining data is saved back into src.

- A double pointer is required so the original src pointer can be updated outside the function scope.

4. Memory Safety

All allocated memory is:

- Freed when no longer needed

- Set to NULL when it may persist beyond the current scope

This avoids memory leaks and dangling pointers.

This approach is justified because it:

- Respects the project constraints

- Works for any BUFFER_SIZE

Correctly handles files with or without trailing newlines

Is efficient and deterministic

## Function Overview
### **String Utilities**

**ft_strlen**
Counts the number of characters in a string.

**ft_strdup**
Allocates memory and duplicates a string character by character.

**ft_substr**
Creates a substring starting at a given index with a specified length, handling edge cases safely.

**ft_strjoin**
Concatenates two strings into a newly allocated one.

### **Memory Utility**

**ft_free**
Frees a pointer and sets it to NULL.
Used when the pointer:

- Lives beyond the current scope

- Is static or global

- Is accessible through a double pointer

### **Core Functions**

**fill_line**
Reads from a file descriptor into a buffer and appends it to the persistent string until reading stops.

**left_line**
Extracts a single line from the stored string and updates the remaining content.
Uses a double pointer to ensure changes persist.

**get_next_line**
Orchestrates the entire process:

- Validates input

- Reads data

- Extracts a line

- Preserves leftover data for the next call

## Resources

- man read

- man open
- Libft project

- 42 Network documentation on get_next_line

- Various C programming articles and forums discussing buffered I/O

## Instructions

This project does not generate a library. The following `main.c` is an example of how you can use this project:

```
#include "get_next_line.h"

int main()
{
	int fd;
	char *line;
	int i = 1;
	fd = open("text.txt", O_RDONLY);
	// creacion de un bucle para recorrer todo el texto
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%d. Linea: %s", i,line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (0);
}
```
Compile with the following command:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c
```
