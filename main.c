#include "get_next_line.h"

int main()
{
	int fd;
	char *line;
	fd = open("text.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("Esta es la primera linea: %s", line);
	free(line);
	line = get_next_line(fd);
	printf("Esta es la segunda linea: %s", line);
	free(line);
	line = get_next_line(fd);
	printf("Esta es la tercera linea: %s", line);
	free(line);
	line = get_next_line(fd);
	printf("Esta es la cuarta linea: %s", line);
	free(line);
	line = get_next_line(fd);
	printf("Esta es la quinta linea: %s", line);
	free(line);
	line = get_next_line(fd);
	printf("Esta es la sexta linea: %s", line);
	free(line);
	line = get_next_line(fd);
	printf("Esta es la septima linea: %s", line);
	free(line);
	close(fd);
	return (0);
}