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

void    ft_free(char **ptr)
{
    if (ptr && *ptr)
    {
        free(*ptr);
        *ptr = NULL;
    }
}

char	*fill_line(int fd, char *src, char *buffer)
{
	char 	*tmp;
	int		count;

	count = 1;
	while (count > 0)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		buffer[count] = '\0';
		if (!src)
			src = ft_strdup("");
		tmp = src;
		src = ft_strjoin(tmp, buffer);
		if (!src)
			return (NULL);
		free(tmp);
	}
	return(src);
}

char	*left_line(char **src)
{
	char 	*left;
	char	*line;
	int		i;
	
	i = 0;
	if (!src || !*src)
		return (NULL);
	while ((*src)[i] != '\n' && (*src)[i] != '\0')
		i++;
	if ((*src)[i] == '\n' )
	{
		line = ft_substr(*src, 0, i + 1);
		left = ft_substr(*src, i + 1, (ft_strlen(*src) - (i + 1)));
		if(!left || left[0] == '\0')
			free(left);
		*src = left;
		if (!*src || (*src)[0] == '\0')
			*src = NULL;
		return (line);
	}
	line = ft_strdup(*src);
	ft_free(src);
	return(line);
}

char	*get_next_line(int fd)
{
	static char *src;
	char 		*buf;
	char 		*line;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd == -1 || BUFFER_SIZE == 0 || read( fd, 0, 0) < 0)
	{	
		ft_free(&src);
        ft_free(&buf);
        return (NULL);
	}
	if (!buf)
		return (NULL);
	src = fill_line(fd, src, buf);
	if (!src)
		return (NULL);
	ft_free(&buf);
	line = left_line(&src);
	return (line);
}
