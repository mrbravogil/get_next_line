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
