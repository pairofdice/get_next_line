/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:49:28 by jsaarine          #+#    #+#             */
/*   Updated: 2022/02/10 11:19:56 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	get_next_line(const int fd, char **line)
{
	char			read_into[BUFF_SIZE + 1];
	char			*hodl;
	char			*fd_seen[MAX_FD] = {0};
	t_vec			transfer;
	static t_vec	buffer;
	ssize_t			ret;


if (!fd_seen[fd])
{
	vec_new(&buffer, BUFF_SIZE * 2, 1);
	fd_seen[fd] = &buffer;
}
ret = read(fd, read_into, BUFF_SIZE);
while (ret > 0)
{
	read_into[0] = "\0";
	vec_from(&transfer, read_into, ft_strlen(read_into), 1);
}

// if ret == 0 when? ...right after while loop, duh



	return (1);
}
