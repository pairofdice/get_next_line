/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:58:13 by jsaarine          #+#    #+#             */
/*   Updated: 2022/01/31 18:21:52 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include "../libft/libft.h"
#include <time.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;
	char	*tests[] = {"a_test", "aaaa_test", "x100_test", "long_lines", 0};
	int		i;
	int x = 0;

	clock_t tic = clock();



	i = 0;
	while (tests[i])
	{
		ft_putstr("Test: ");
		ft_putnbr(i);
		ft_putchar('\n');
		fd = open(tests[i], O_RDONLY);
		while (x++ < 3)
		{
			get_next_line(fd, &line);
			ft_putendl(line);
			//ft_strdel(&line);
			}
		x= 0;


		i++;
	}

    clock_t toc = clock();
    printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);
}

