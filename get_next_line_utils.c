/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabravo- <mabravo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 13:53:11 by mabravo-          #+#    #+#             */
/*   Updated: 2025/12/15 13:53:14 by mabravo-         ###   ########.fr       */
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

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	d;

	d = (unsigned char) c;
	i = 0;
	while (s[i])
	{
		if (s[i] == d)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (s[i] == d)
		return ((char *)&s[i]);
	return (0);
}

char	*ft_strdup(const char *s)
{
	size_t		len;
	int			i;
	char		*s2;

	len = ft_strlen(s);
	s2 = (char *)malloc((len + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	i = 0;
	while (s[i])
	{
		s2[i] = s[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	size_t	i;
	char	*s2;

	i = 0;
	if (!s)
		return (0);
	size = ft_strlen(s);
	if (start > size)
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	s2 = malloc((len + 1) * sizeof(char));
	if (!s2)
		return (0);
	while (i < len)
	{
		s2[i] = s[start + i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int	j;

	j = 0;
	if (!s1 || !s2)
		return (0);
	s3 = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!s3)
		return (0);
	while (*s1)
	{
		s3[j++] = *s1++;
	}
	while (*s2)
	{
		s3[j++] = *s2++;
	}
	s3[j] = '\0';
	return (s3);
}



