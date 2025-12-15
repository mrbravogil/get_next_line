

# get_next_line
Proyecto llevado a cabo durante el Cursus de Campus 42, Málaga. Recreación 
de la función get_next_line en C.

"buffersize" (tamaño de búfer) se refiere al número de bytes en una región de memoria temporal (el búfer) para almacenar datos, crucial para I/O, y se gestiona con sizeof, malloc/realloc, y funciones como fgets() para controlar desbordamientos, usando constantes como BUFSIZ o definiendo el tamaño para optimizar rendimiento y seguridad. 

https://labex.io/tutorials/c-how-to-manage-input-buffer-in-c-418766


man getline
#include <stdio.h>

       ssize_t getline(char **lineptr, size_t *n, FILE *stream)
