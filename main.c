/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabufarw <aabufarw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 13:04:11 by aabufarw          #+#    #+#             */
/*   Updated: 2026/11/16 13:35:56 by aabufarw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*string;
	char	*line;

	string = "my name is aisha multi line textaishanoorreem";
	fd = open("mytest.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	write(fd, string, ft_strlen(string));
	close(fd);
	fd = open("mytest.txt", O_RDWR);
	line = get_next_line(fd);
	printf("%s", line);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
