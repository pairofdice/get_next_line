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
	t_vec			*fd_seen[MAX_FD] = {0};
	t_vec			transfer;
	static t_vec	buffer;
	ssize_t			ret;
	int				len;


if (!fd_seen[fd])
{
	vec_new(&buffer, BUFF_SIZE * 2, 1);
	fd_seen[fd] = &buffer;
}
ret = read(fd, read_into, BUFF_SIZE);
while (ret > 0)
{
	read_into[ret] = '\0';					//vec_from(&transfer, read_into, ft_strlen(read_into), 1);
	/* vec_strapp(fd_seen[fd], read_into); */
	vec_from(&transfer, read_into, ft_strlen(read_into), 1);
	vec_append(fd_seen[fd], &transfer);

	hodl = ft_strchr(fd_seen[fd]->memory, '\n');
	if (hodl)
	{
		*hodl = '\0';						// fd_seen[fd]->len = ft_strlen(fd_seen[fd]->memory  ) + 1;
		break; 								// maybe push null terminator onto fd_seen[fd] here
	}
	ret = read(fd, read_into, BUFF_SIZE);
}

if (fd_seen[fd]->len == 0)
{
	vec_free(fd_seen[fd]);
	fd_seen[fd] = 0;
	return (0);
}



// if ret == 0 when? ...right after while loop, duh


	*line = ft_strdup(fd_seen[fd]->memory);
	len = ft_strlen(fd_seen[fd]->memory);
	if (fd_seen[fd]->len > len + 1) // we're safe to move pointer and not done with file
	{
		fd_seen[fd]->memory += len + 1;
		fd_seen[fd]->len -= len + 1;
	}

	return (1);
}
