/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   get_next_line.c                                   :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By:  aabufarw <aabufarw@student.42.fr>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/06 12:41:19 by  aabufarw        #+#    #+#              */
/*   Updated: 2026/11/15 19:46:44 by  aabufarw       ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*container_static;
	char		*one_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
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

static char	*read_file(int fd, char *stash)
{
	char	*buffer;

	if (!stash)
		stash = ft_calloc(1, 1);
	if (!stash)
		return (NULL);
	buffer = (char *) ft_calloc((size_t) BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
	{
		free(stash);
		return (NULL);
	}
	return (fill_buffer(fd, stash, buffer));
}

static char	*fill_buffer(int fd, char *stash, char *buffer)
{
	int		bytes;
	char	*temp;

	bytes = 1;
	while (!ft_strchr(stash, '\n') && bytes > 0)
	{
		bytes = (int) read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			free(stash);
			return (NULL);
		}
		buffer[bytes] = '\0';
		temp = ft_strjoin(stash, buffer);
		free(stash);
		stash = temp;
		if (!stash)
		{
			free(buffer);
			return (NULL);
		}
	}
	free(buffer);
	return (stash);
}

static char	*find_line(char *stash)
{
	char	*one_line;
	int		i;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	one_line = ft_calloc(i + 2, sizeof(char));
	if (!one_line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		one_line[i] = stash[i];
		i++;
	}
	if (stash[i] && stash[i] == '\n')
		one_line[i++] = '\n';
	return (one_line);
}

static char	*find_remaining(char *stash)
{
	int		i;
	int		j;
	char	*leftover;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	leftover = ft_calloc((ft_strlen(stash) - i + 1), sizeof(char));
	if (!leftover)
	{
		free(stash);
		return (NULL);
	}
	i++;
	j = 0;
	while (stash[i])
		leftover[j++] = stash[i++];
	free(stash);
	return (leftover);
}
