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

void	ft_free(char *ptr)
{
	free(ptr);
	ptr = NULL;
}

char	*fill_line(int fd, char *src, char *buffer)
{
	char 	*tmp;
	int		count;

	count = 1;
	while (count > 0)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count == -1)
		{
			ft_free(src);
			return (NULL);
		}
		if (count == 0)
			break ;
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

char	*left_line(char **dst)
{
	char 	*left;
	char	*line;
	int		i;
	
	i = 0;
	if (!dst || !*dst)
		return (NULL);
	while ((*dst)[i] != '\n' && (*dst)[i] != '\0')
		i++;
	if ((*dst)[i] == '\n' )
	{
		line = ft_substr(*dst, 0, i + 1);
		left = ft_substr(*dst, i + 1, (ft_strlen(*dst) - (i + 1)));
		*dst = left;
		if (*dst && (*dst)[0] == '\0')
			ft_free(*dst);
		return (line);
	}
	line = ft_strdup(*dst);
	ft_free(*dst);
	return(line);
}

char *get_next_line(int fd)
{
	static char *src;
	char 		*buf;
	char 		*line;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd == -1 || BUFFER_SIZE == 0 || read( fd, 0, 0) < 0)
	{	
		ft_free(src);
        ft_free(buf);
        return (NULL);
	}
	if (!buf)
		return (NULL);
	src = fill_line(fd, src, buf);
	if (!src)
		return (NULL);
	ft_free(buf);
	line = left_line(&src);
	return (line);
}
