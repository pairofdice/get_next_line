/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:49:28 by jsaarine          #+#    #+#             */
/*   Updated: 2021/12/23 17:39:20 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	static char	*fd_seen[MAX_FD];
	int			ret;
	char		buff[BUFF_SIZE + 1];

	if (!fd_seen[fd])
	{
		ret = 1;
		while (ret)
		{
			ret = read(fd, *line, BUFF_SIZE);
			// dynamic arrays here, maybe?
			// read the whole file into buffer
		}
	}
	return (ret);
}

	// if fd in fd_seen
		// get fd_seen[fd] ... hmm, not needed?
	// else
		// read(fd, *line, BUFF_SIZE);
	// read until '\n' or '\0'
		// match '\n'
		// match '\0
		// strsep?
