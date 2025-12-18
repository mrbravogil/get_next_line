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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char *fill_line(int fd, char *src, char *buffer)
{
	char 	*tmp;
	int		count;

	count = 1;
	while (count > 0)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count == -1)
		{
			free(src);
			src = NULL;
			return (NULL);
		}
		if (count == 0)
		{
			return (NULL);
		}
		buffer[count] = '\0';
		if (!src)
			src = ft_strdup("");
		tmp = src;
		src = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break;
	}
	return(src);
}

char *left_line(char *dst)
{
	static char *src;
	int			i;

	i = 0;
	while (dst[i] != '\n' || dst[i])
	{
		i++;
	}
	if (dst[i] == 0 || dst[1] == 0)
		return (NULL);
	src = (char *)malloc((ft_strlen(dst) + 1) * sizeof(char));
	if (!src)
		return (NULL);
	src = ft_substr(dst, i + 1, (ft_strlen(dst) - i));
	free(src);
	src[i + 1] = '\0';
	return(src);
}

char *get_next_line(int fd)
{
	static char *src;
	char 		*buf;
	char 		*dst;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd == -1 || BUFFER_SIZE == 0 || read( fd, 0, 0) < 0)
	{	
		free(src);
        free(buf);
        src = NULL;
        buf = NULL;
        return (NULL);
	}
	if (!buf)
		return (NULL);
	dst = fill_line(fd, src, buf);
	if (!dst)
		return (NULL);
	free(buf);
	buf = NULL;
	src = left_line(dst);
	return (dst);
}

int main()
{
	int fd;
	char *buffer;
	int count = 0;
	buffer = (char *)malloc((1024) * sizeof(char));
	fd = open("text.txt", O_RDONLY);
	printf("El buffer tiene: %zd\n", read(fd, buffer, BUFFER_SIZE));
	get_next_line(fd);
	printf("El contador es: %d\n", count);
	printf("El buffer tiene: %zd\n", read(fd, buffer, sizeof(buffer)));
	
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