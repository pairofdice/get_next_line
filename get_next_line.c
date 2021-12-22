/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:49:28 by jsaarine          #+#    #+#             */
/*   Updated: 2021/12/22 12:10:32 by jsaarine         ###   ########.fr       */
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
		// read until \n or \0
		// if until \n save spot in fd_seen and return 1?
		// if until \0 return 0?
	}
	else
	{
		// read(fd, *line, BUFF_SIZE);
	}
	return (ret);
}

	// check if fd has been seen
		// if fd not seen, it is now
		// or if we see a \0 before \n we're done reading, reset fd_seen
	// find \n or \0
		// put it in *line with \0
		// save our spot in *line with the corresponding fd
