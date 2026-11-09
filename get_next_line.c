/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   get_next_line.c                                   :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By:  aabufarw <aabufarw@student.42.fr>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/06 12:41:19 by  aabufarw        #+#    #+#              */
/*   Updated: 2026/11/09 19:42:55 by  aabufarw       ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*joinandfree(char *resultant, char *appender)
{
	char	*temp;

	temp = ft_strjoin(resultant, appender);
	free(resultant);
	return (temp);
}

char	*find_remaining(char *resultant)
{
	int		i;
	int		j;
	char	*remstatic;

	i = 0;
	while (resultant[i] && resultant[i] != '\n')
		i++;
	if (!resultant[i])
	{
		free(resultant);
		return (NULL);
	}
	remstatic = ft_calloc((ft_strlen(resultant) - i + 1), sizeof(char));
	if (!remstatic)
	{
		free(resultant);
		return (NULL);
	}
	i++;
	j = 0;
	while (resultant[i])
		remstatic[j++] = resultant[i++];
	free(resultant);
	return (remstatic);
}

char	*find_line(char *resultant)
{
	char	*one_line;
	int		i;

	i = 0;
	if (!resultant[i])
		return (NULL);
	while (resultant[i] && resultant[i] != '\n')
		i++;
	one_line = ft_calloc(i + 2, sizeof(char));
	if (!one_line)
		return (NULL);
	i = 0;
	while (resultant[i] && resultant[i] != '\n')
	{
		one_line[i] = resultant[i];
		i++;
	}
	if (resultant[i] && resultant[i] == '\n')
		one_line[i++] = '\n';
	return (one_line);
}

static char	*fill_buffer(int fd, char *res, char *buff)
{
	int	bytes;

	bytes = 1;
	while (!ft_strchr(res, '\n') && bytes > 0)
	{
		bytes = (int) read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buff);
			free(res);
			return (NULL);
		}
		buff[bytes] = '\0';
		res = joinandfree(res, buff);
		if (!res)
		{
			free(buff);
			return (NULL);
		}
	}
	free(buff);
	return (res);
}

char	*read_file(int fd, char *resultant)
{
	char	*appender;

	if (!resultant)
		resultant = ft_calloc(1, 1);
	if (!resultant)
		return (NULL);
	appender = malloc(sizeof(char) * ((size_t) BUFFER_SIZE + 1));
	if (!appender)
	{
		free(resultant);
		return (NULL);
	}
	return (fill_buffer(fd, resultant, appender));
}

char	*get_next_line(int fd)
{
	static char	*container_static;
	char		*one_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647 || read(fd, 0, 0) < 0)
		return (NULL);
	container_static = read_file(fd, container_static);
	if (!container_static || container_static[0] == '\0')
	{
		free(container_static);
		container_static = NULL;
		return (NULL);
	}
	one_line = find_line(container_static);
	container_static = find_remaining(container_static);
	return (one_line);
}
