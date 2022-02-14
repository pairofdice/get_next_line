/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:58:13 by jsaarine          #+#    #+#             */
/*   Updated: 2022/02/14 16:27:12 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include "../libft/libft.h"
#include <time.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	int		fd2;
	int		fd3;
	int		x;
	char	*line;
	int		i;
	char	*tests[] = {
		/*
		"a_test",
		"aaaa_test",
		"many_empty",
		*/
		"x100_test",
		"test_text.txt",
		"12345.txt",
		/*
		"long_lines",
		"gnl7_1.txt",
		"150xlorem",
		"plato",
		"test_bible",
		"10_superlongsentence_no_newline",
		*/
		0};

	clock_t tic = clock();
	i = 0;
		fd2 = open(tests[0], O_RDONLY);
		fd3 = open(tests[1], O_RDONLY);
	int c;
	while (tests[i])
	{
		x = 0;
		//ft_putstr("Test: ");
		printf("Test: %d\n", i);

		fd = open(tests[i], O_RDONLY);
		c = 1;
		while (x <3)
		{
			c = get_next_line(fd, &line);
			printf("%d %s\n",c, line);
			//ret++;
			ft_strdel(&line);
			//if (ret == 3)
			//	break;
			x++;
		}
		printf("-----\n");
		i++;
	}

		c = 1;
		x = 0;
		while (x < 3)
		{
			
			c = get_next_line(fd2, &line);
			printf("%d %s\n",c, line);
			//ret++;
			ft_strdel(&line);
			//if (ret == 3)
			//	break;
			x++;
		}
		printf("-----\n");
		c = 1;
		while (c)
		{
			
			c = get_next_line(fd, &line);
			printf("%d %s\n",c, line);
			//ret++;
			ft_strdel(&line);
			//if (ret == 3)
			//	break;
			x++;
		}
				printf("-----\n");
		c = 1;
		while (c)
		{
			
			c = get_next_line(fd2, &line);
			printf("%d %s\n",c, line);
			//ret++;
			ft_strdel(&line);
			//if (ret == 3)
			//	break;
			x++;
		}

    clock_t toc = clock();
    printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);
	//system("leaks a.out");
	return (0);
}

