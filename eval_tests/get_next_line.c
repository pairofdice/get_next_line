/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:49:28 by jsaarine          #+#    #+#             */
/*   Updated: 2022/02/10 11:21:08 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	get_next_line(const int fd, char **line)
{
	char			read_into[BUFF_SIZE + 1];
	char			*hodl;
	t_vec			*fd_seen[MAX_FD];
	t_vec			transfer;
	static t_vec	buffer;
	ssize_t			ret;
	ssize_t			len;

	if (fd_seen[fd])
	{
		 // vec_push(fd_seen[fd], "\0");
		if (fd_seen[fd]->len == 0)
		{
			vec_free(fd_seen[fd]);
			fd_seen[fd] = 0;
			return (-1);
		}
		if (fd_seen[fd]->len >= ft_strlen(fd_seen[fd]->memory) + 1)
		{
			fd_seen[fd]->memory += ft_strlen(fd_seen[fd]->memory) + 1; // need a check for this
			fd_seen[fd]->len = ft_strlen(fd_seen[fd]->memory) ;

		}
		else
		{
			ft_putendl("Do we ever get here");
		 	vec_free(fd_seen[fd]);
			ft_putendl("after free");
			fd_seen[fd] = 0;
			return (0);
		}
		/* if (fd_seen[fd]->len == ft_strlen(fd_seen[fd]->memory) + 1) */
	}
	else
	{

		vec_new(&buffer, BUFF_SIZE, 1);
		fd_seen[fd] = &buffer;
	}
	ret = read(fd, read_into, BUFF_SIZE);
	if (ret == 0)
		return (0);
	while (ret > 0)
	{
		read_into[ret] = '\0';
		vec_from(&transfer, read_into, ft_strlen(read_into), 1);
 		vec_append(fd_seen[fd], &transfer);
 		//vec_free(&transfer);
		hodl = ft_strchr(read_into, '\n');
		if (hodl)
		{
			*hodl = '\0';
			//fd_seen[fd]->len = ft_strlen(fd_seen[fd]->memory  ) + 1;
			break; // maybe push null terminator onto fd_seen[fd] here
		}
		ret = read(fd, read_into, BUFF_SIZE);
	}

/* 	if (fd_seen[fd] != 0 )
	{
		if(fd_seen[fd]->len == 0)
		{
			vec_free(fd_seen[fd]);
			fd_seen[fd] = 0;
			return (0);

		}
	} */
	*line = ft_strdup(fd_seen[fd]->memory);
	return (1);
}
