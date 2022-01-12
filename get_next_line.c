/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:49:28 by jsaarine          #+#    #+#             */
/*   Updated: 2022/01/12 17:04:24 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	static t_buff	*fd_seen[MAX_FD] = {0};
	t_vec temp;
	int ret;

	ret	= 1;
	if (fd > MAX_FD || fd < 0)
		return (-1);
	if (fd_seen[fd])
	{
		// check if we have read everything
		temp = *fd_seen[fd]->content;
		line = temp.memory[fd_seen[fd]->index];
		return (1);
	}
	else
	{
		while (ret)
		{
			ret = read(fd, line, BUFF_SIZE);
		}
	}
	return (0);
}
