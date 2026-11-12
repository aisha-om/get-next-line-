/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By:  aabufarw <aabufarw@student.42.fr>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/06 13:04:11 by  aabufarw        #+#    #+#              */
/*   Updated: 2026/11/09 21:48:50 by  aabufarw       ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*string;

	string = "my name is aisha multi line text this is a test file 42 is the best school";
	fd = open("mytest.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	write(fd, string, ft_strlen(string));
	close(fd);
	fd = open("my.txt", O_RDWR);
	char	*line = get_next_line(fd);

	printf("%s", line);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
