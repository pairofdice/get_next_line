/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:58:13 by jsaarine          #+#    #+#             */
/*   Updated: 2022/02/13 23:23:52 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include "../libft/libft.h"
#include <time.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	int		ret;
	char	*line;
	int		i;
	char	*tests[] = {"a_test",
		"aaaa_test",
		"x100_test",
		"many_empty",
		"long_lines", 
		/*"150xlorem",
		"plato",
		"test_bible",
		"10_superlongsentence_no_newline", */ 0};

	clock_t tic = clock();
	i = 0;
	while (tests[i])
	{
		ret = 1;
		ft_putstr("Test: ");
		ft_putnbr(i);
		ft_putchar('\n');
		fd = open(tests[i], O_RDONLY);
		while (get_next_line(fd, &line))
		{
			//get_next_line(fd, &line);
			printf(" %s\n", line);
			//ret++;
			ft_strdel(&line);
			//if (ret == 3)
			//	break;
		}
		i++;
	}

    clock_t toc = clock();
    printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);
	system("leaks a.out");
	return (0);
}

