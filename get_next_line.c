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

void	ft_free(char **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

char	*fill_line(int fd, char *src, char *buffer)
{
	char		*tmp;
	ssize_t		count;

	count = 1;
	while (count > 0 && (!src || !ft_strchr(src, '\n')))
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count <= 0)
			break ;
		buffer[count] = '\0';
		if (!src)
			src = ft_strdup("");
		tmp = src;
		src = ft_strjoin(tmp, buffer);
		free(tmp);
		if (!src)
			return (NULL);
	}
	return (src);
}

char	*check_loop(char **src, int i)
{
	char	*left;
	char	*line;
	ssize_t	len;

	len = ft_strlen(*src);
	line = ft_substr(*src, 0, i + 1);
	if (!line)
		return (NULL);
	if ((ssize_t)(i + 1) >= len)
		left = ft_strdup("");
	else
		left = ft_substr(*src, i + 1, (ft_strlen(*src) - (i + 1)));
	free(*src);
	if (!left || left[0] == '\0')
	{
		free(left);
		*src = NULL;
	}
	else
		*src = left;
	return (line);
}

char	*left_line(char **src)
{
	char	*line;
	int		i;

	i = 0;
	if (!src || !*src)
		return (NULL);
	while ((*src)[i] != '\n' && (*src)[i] != '\0')
		i++;
	if ((*src)[i] == '\n' )
	{
		line = check_loop(src, i);
		return (line);
	}
	line = ft_strdup(*src);
	ft_free(src);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*src;
	char		*buf;
	char		*line;

	if (fd == -1 || BUFFER_SIZE == 0 || read(fd, 0, 0) < 0)
	{
		ft_free(&src);
		return (NULL);
	}
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	src = fill_line(fd, src, buf);
	free(buf);
	if (!src || src[0] == '\0')
	{
		ft_free(&src);
		return (NULL);
	}
	
	line = left_line(&src);
	return (line);
}
