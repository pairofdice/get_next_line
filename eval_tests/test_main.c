/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:58:13 by jsaarine          #+#    #+#             */
/*   Updated: 2021/12/21 14:08:06 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line[10];
	char	**tests = {"a_test", "aaaa_test", 0};
	int		i;

	i = 0;
	while (tests[i] != 0)
	{
		ft_putstr("Test: ");
		ft_putnbr(i);
		ft_putchar('\n');
		fd = open(tests[i], O_RDONLY);
		get_next_line(fd, line);
		i++;
	}
}
