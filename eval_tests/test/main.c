/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 17:45:21 by jhakonie          #+#    #+#             */
/*   Updated: 2022/02/14 14:16:18 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../../libft/libft.h"
#include "../../get_next_line.h"
#include <stdio.h>

int main(int ac, char **av)
{
	char *line;
	int fd;
	int fd2;
	int fd3;
	int x = 1;
	size_t i = 0;

	line = NULL;
	fd = 0;
	if (ac == 2 && ft_strcmp(av[1], "stdin") != 0)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			printf("open() failed\n");
		while (i < 100 && x == 1)
		{
			x = get_next_line(fd, &line);
			if (x == -1)
				printf("error, gnl returns |%d|", x);

			else if (x == 1)
			{
				printf("Line is: |%s|\n", line);
				ft_strdel(&line);
			}
			else if (x == 0)
			{
				printf("Gnl returns |%d| Nothing left to read.\n", x);
				printf("Line is: |%s|\n", line);
ft_strdel(&line);
			}
			i++;
		}
	}
	else if (ac == 1)
		printf("Too few arguments.\nTo test with echo, write:\necho 'some text' | ./test_gnl stdin\n");
	else if (ac == 2 && ft_strcmp(av[1], "stdin") == 0)
	{
		while (x == 1 && i < 10)
		{
			x = get_next_line(fd, &line);
			if (x == -1)
				printf("error, gnl returns |%d|", x);
			else if (x == 1)
			{
				printf("Line is: |%s|\n", line);
				ft_strdel(&line);
			}
			else if (x == 0)
			{
				printf("Gnl returns |%d| Nothing left to read.\n", x);
				printf("Line is: |%s|\n", line);
ft_strdel(&line);
			}
			i++;
		}
	}
	else if (ac == 3 && ft_strcmp(av[1], "error") == 0)
	{
		fd = open(av[2], O_RDONLY);
		if (fd == -1)
		{
			printf("If you gave it a filename that isn't a file: open() failed and fd is -1\n");
			printf("Then we try to call GNL with this fd = |%d|\n", fd);
			while (x == 1 && i < 10)
			{
				x = get_next_line(fd, &line);
				if (x == -1)
					printf("GNL returns: |%d| and fd is: |%d|\n", x, fd);
				else if (x == 1)
				{
					printf("Line is: |%s|\n", line);
					ft_strdel(&line);
				}
				else if (x == 0)
				{
					printf("Gnl returns |%d| Nothing left to read.\n", x);
					printf("Line is: |%s|\n", line);
				}
				i++;
			}
		}
		i = 0;
		if (fd >= 0)
		{
			printf("If you gave it a real file name, it is opened and fd is: |%d|\n", fd);
			printf("But then we close the fd |%d| and try to call GNL with the same fd\n", fd);
			if (close(fd) == 0)
				printf("closed fd: |%d|\n", fd);
			while (x == 1 && i < 10)
			{
				x = get_next_line(fd, &line);
				if (x == -1)
					printf("error, Gnl returns |%d| and fd is |%d|\n", x, fd);
				else if (x == 1)
				{
					printf("Line is: |%s|\n", line);
					ft_strdel(&line);
				}
				else if (x == 0)
				{
					printf("Gnl returns |%d| Nothing left to read.\n", x);
					printf("Line is: |%s|\n", line);
				}
				i++;
			}
		}
	}
	else if (ac == 3 && ft_strcmp(av[1], "errorline") == 0)
	{
		fd = open(av[2], O_RDONLY);
		printf("We will open the file given as second argument and then send fd |%d| and NULL (instead of &line) to GNL.\n", fd);
		if (fd == -1)
			printf("open() failed, try again with a valid file name.\n");
		while (x == 1 && i < 10)
		{
			x = get_next_line(fd, NULL);
			if (x == -1)
				printf("Error, Gnl returns |%d| and fd is |%d|\n", x, fd);
			else if (x == 1)
			{
				printf("Line is: |%s|\n", line);
				ft_strdel(&line);
			}
			else if (x == 0)
			{
				printf("Gnl returns |%d| Nothing left to read.\n", x);
				printf("Line is: |%s|\n", line);
			}
			i++;
		}
	}
	else if (ac == 3 && ft_strcmp(av[1], "FD_SIZE") == 0)
	{
		fd = open(av[2], O_RDONLY);
		printf("We will send fd = |%d| (given as second argument) to GNL.\n", atoi(av[2]));
		fd = atoi(av[2]);
		while (x == 1 && i < 10)
		{
			x = get_next_line(fd, &line);
			if (x == -1)
				printf("Error, Gnl returns |%d| and fd is |%d|\n", x, fd);
			else if (x == 1)
			{
				printf("Line is: |%s|\n", line);
				ft_strdel(&line);
			}
			else if (x == 0)
			{
				printf("Gnl returns |%d| Nothing left to read.\n", x);
				printf("Line is: |%s|\n", line);
			}
			i++;
		}
	}
	else if (ac == 4)
	{

		fd = open(av[1], O_RDONLY);
		fd2 = open(av[2], O_RDONLY);
		fd3 = open(av[3], O_RDONLY);
		if (fd == -1)
			ft_putstr("open() failed\n");
		if (fd2 == -1)
			ft_putstr("open() failed\n");
		if (fd3 == -1)
			ft_putstr("open() failed\n");
		while (i < 3 && x == 1)
		{
			x = get_next_line(fd, &line);
			if (x == -1)
				printf("error, gnl returns |%d|", x);

			else if (x == 1)
			{
				printf("Line is: |%s|\n", line);
				ft_strdel(&line);
			}
			else if (x == 0)
			{
				printf("Gnl returns |%d| Nothing left to read.\n", x);
				printf("Line is: |%s|\n", line);
			}
			i++;
		}
		printf("fd is %d\n", fd);
		i = 0;
		while (i < 3 && x == 1)
		{
			x = get_next_line(fd2, &line);
			if (x == -1)
				printf("error, gnl returns |%d|", x);

			else if (x == 1)
			{
				printf("Line is: |%s|\n", line);
				ft_strdel(&line);
			}
			else if (x == 0)
			{
				printf("Gnl returns |%d| Nothing left to read.\n", x);
				printf("Line is: |%s|\n", line);
			}
			i++;
		}
		i = 0;
		printf("fd is %d\n", fd2);
		while (i < 3 && x == 1)
		{
			x = get_next_line(fd3, &line);
			if (x == -1)
				printf("error, gnl returns |%d|", x);

			else if (x == 1)
			{
				printf("Line is: |%s|\n", line);
				ft_strdel(&line);
			}
			else if (x == 0)
			{
				printf("Gnl returns |%d| Nothing left to read.\n", x);
				printf("Line is: |%s|\n", line);
			}
			i++;
		}
		i = 0;
		printf("fd is %d\n", fd3);
		while (i < 3 && x == 1)
		{
			x = get_next_line(fd, &line);
			if (x == -1)
				printf("error, gnl returns |%d|", x);

			else if (x == 1)
			{
				printf("Line is: |%s|\n", line);
				ft_strdel(&line);
			}
			else if (x == 0)
			{
				printf("Gnl returns |%d| Nothing left to read.\n", x);
				printf("Line is: |%s|\n", line);
			}
			i++;
		}
		printf("fd is %d\n", fd);
	}
	else if (ac > 4)
	{
		printf("wrong number of arguments, give 3 file names.\n");
	}
	// while (1)
	// 	;

	return (0);
}
