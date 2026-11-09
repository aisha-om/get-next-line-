/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   get_next_line_utils.c                             :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By:  aabufarw <aabufarw@student.42.fr>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/06 12:41:03 by  aabufarw        #+#    #+#              */
/*   Updated: 2026/11/08 14:49:14 by  aabufarw       ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dest;
	const unsigned char	*srcc;
	size_t				i;

	if (!dst && !src)
		return (NULL);
	dest = (unsigned char *) dst;
	srcc = (const unsigned char *) src;
	i = 0;
	while (i < n)
	{
		dest[i] = srcc[i];
		i++;
	}
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	joined = (char *) malloc(len1 + len2 + 1);
	if (!joined)
		return (NULL);
	ft_memcpy(joined, s1, len1);
	ft_memcpy(joined + len1, s2, len2 + 1);
	return (joined);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char) c)
			return ((char *) s);
		s++;
	}
	if ((unsigned char)*s == (unsigned char) c)
		return ((char *) s);
	return (NULL);
}

void	*ft_memset(void *ptr, int value, size_t len)
{
	unsigned char	*str;
	unsigned char	t;
	size_t			i;

	str = (unsigned char *) ptr;
	t = (unsigned char) value;
	i = 0;
	while (i < len)
	{
		str[i] = t;
		i++;
	}
	return (str);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	total_size;

	if (count == 0 || size == 0)
		return (malloc(0));
	if (count && size > (size_t) - 1 / count)
		return (NULL);
	total_size = count * size;
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, '\0', total_size);
	return (ptr);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
