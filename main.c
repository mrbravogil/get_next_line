#include "get_next_line.h"

int main()
{
	int fd;
	char *line;
	fd = open("text.txt", O_RDONLY);
	// creacion de un bucle para recorrer todo el texto
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
