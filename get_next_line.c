/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:49:28 by jsaarine          #+#    #+#             */
/*   Updated: 2022/02/02 22:02:13 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	get_next_line(const int fd, char **line)
{
	char			read_into[BUFF_SIZE + 1];
	char			*hodl;
	static t_vec	*fd_seen[MAX_FD];
	t_vec			transfer;
	t_vec			buffer;
	ssize_t			ret;

	if (fd_seen[fd])
	{
		fd_seen[fd]->memory += ft_strlen(fd_seen[fd]->memory) + 1;
		fd_seen[fd]->len -= ft_strlen(fd_seen[fd]->memory) + 1;
		if (fd_seen[fd]->len == ft_strlen(fd_seen[fd]->memory) + 1)
		{
		 	vec_free(fd_seen[fd]); 
			fd_seen[fd] = 0;
			return (0);
		}
	}
	else
	{
		vec_new(&buffer,BUFF_SIZE + 1, 1);
		fd_seen[fd] = &buffer;
	}
	ret = read(fd, read_into, BUFF_SIZE);
	while (ret > 0)
	{
		read_into[ret] = '\0';
		vec_from(&transfer, read_into, ft_strlen(read_into), 1);
 		vec_append(fd_seen[fd], &transfer);
 		vec_free(&transfer);
		hodl = ft_strchr(fd_seen[fd]->memory, '\n');
		if (hodl)
		{
			*hodl = '\0';
			fd_seen[fd]->len = ft_strlen(fd_seen[fd]->memory  ) + 1;
			break;
		}
		ret = read(fd, read_into, BUFF_SIZE);
	}
	//vec_push(fd_seen[fd], "\0");
	*line = ft_strdup(fd_seen[fd]->memory);
	return (1);
}
