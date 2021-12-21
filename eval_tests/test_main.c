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

	fd = open("a_test", O_RDONLY);
	get_next_line(fd, line);
}
