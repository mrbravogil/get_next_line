/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabravo- <mabravo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 13:53:01 by mabravo-          #+#    #+#             */
/*   Updated: 2025/12/15 13:53:03 by mabravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_read(int fd, void *buffer, size_t buffersize)
{
	static int count;
	count = read(fd, buffer, buffersize);
	return (count);
}

char *get_next_line(int fd)
{
	char 		*src;
	char		buffer[1024];
	static int	count;
	int			i;

	count = 0;
	i = 0;
	src = "";
	if (fd == -1)
		return(NULL);
	
	else
	{
		count = ft_read(fd, src, BUFFER_SIZE);
	}
	/*while(src[i] != '\n' || src[i] != '\0')
	{
		count += read(fd, src, BUFFER_SIZE);
		fill_line(fd, dst, src);
		set_line(dst);
		i++;
	}

	ft_putstr(dst);*/
	return (dst);
}

int main()
{
	int fd;
	char buffer[1024];
	fd = open("text.txt", O_RDONLY);
	printf("%d\n", ft_read(fd, buffer, BUFFER_SIZE));
	printf("%d", ft_read(fd, buffer, sizeof(buffer)));
	return (0);
}

/*
 hola. com.o es.tas?./n/

 malloc(str, BUFF SIZE) = len 
 malloc(str2, len + buff size)
 copy str en str2,
 free(str)

 ret (str)

 open()*/