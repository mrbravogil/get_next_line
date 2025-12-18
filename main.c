#include "get_next_line.h"

int main()
{
	int fd;
	fd = open("text.txt", O_RDONLY);
	printf("Esta es la primera linea: %s", get_next_line(fd));
	printf("Esta es la segunda linea: %s", get_next_line(fd));
	printf("Esta es la tercera linea: %s", get_next_line(fd));
	printf("Esta es la cuarta linea: %s", get_next_line(fd));
	printf("Esta es la quinta linea: %s", get_next_line(fd));
	printf("Esta es la sexta linea: %s", get_next_line(fd));
	return (0);
}