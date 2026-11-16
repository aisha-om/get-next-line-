/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: aabufarw <aabufarw@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/06 13:04:11 by aabufarw         #+#    #+#              */
/*   Updated: 2026/11/16 15:40:00 by aabufarw        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd1;
	int		fd2;
	char	*string1;
	char	*string2;
	char	*line1;
	char	*line2;

	string1 = "my name is aisha multi line textaishanoorreem";
	string2 = "my fd2 is opened\n";
	fd1 = open("mytest.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	fd2 = open("my.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	write(fd1, string1, ft_strlen(string1));
	write(fd2, string2, ft_strlen(string2));
	close(fd1);
	close(fd2);
	fd1 = open("mytest.txt", O_RDWR);
	fd2 = open("my.txt", O_RDWR);
	line1 = get_next_line(fd1);
	line2 = get_next_line(fd2);
	printf("%s", line1);
	while (line1)
	{
		printf("%s", line1);
		free(line1);
		line1 = get_next_line(fd1);
	}
	printf("%s", line2);
	while (line2)
	{
		printf("%s", line2);
		free(line2);
		line2 = get_next_line(fd1);
	}
	close(fd1);
	close(fd2);
}
