/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:49:28 by jsaarine          #+#    #+#             */
/*   Updated: 2022/02/02 18:33:47 by jsaarine         ###   ########.fr       */
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


	transfer.memory = NULL;

	if (fd_seen[fd])
	{
/* 		printf("fd buffer %s\n", fd_seen[fd]->memory);
		printf("fd buffer alloc size %zu\n", fd_seen[fd]->alloc_size); */
		fd_seen[fd]->memory += ft_strlen(fd_seen[fd]->memory);
		fd_seen[fd]->len -= ft_strlen(fd_seen[fd]->memory);
		if (fd_seen[fd]->len == ft_strlen(fd_seen[fd]->memory) + 1)
		{
		/* 	vec_free(fd_seen[fd]); */
			fd_seen[fd] = 0;
			return (0);
		}
		//printf("fd buffer len%zu\n", fd_seen[fd]->len);
	}
	else
	{
		vec_new(&buffer,BUFF_SIZE + 1, 1);
		fd_seen[fd] = &buffer;
	}


	ret = read(fd, read_into, BUFF_SIZE);
	while (ret > 0)
	{

/* 		if (transfer.memory)
			vec_free(&transfer); */
		vec_from(&transfer, read_into, ft_strlen(read_into), 1);

/* 	ft_putendl("Tässäkö3");
 */		vec_append(fd_seen[fd], &transfer);
/* 	ft_putendl("Tässäkö2");
 */		vec_free(&transfer);
		hodl = ft_strchr(fd_seen[fd]->memory, '\n');
		if (hodl)
		{
			*hodl = '\0';
			fd_seen[fd]->len = ft_strlen(fd_seen[fd]->memory  ) + 1;
			printf(" len hodl %zu\n", fd_seen[fd]->len);
/* 	ft_putendl("Tässäkö");
 */
				break;
		}
		ret = read(fd, read_into, BUFF_SIZE);
	}

	/* if (fd_seen[fd] != 0)
	{
		vec_push(fd_seen[fd], "\0");
	} */
	if (fd_seen[fd]->len > 0)
		*line = ft_strdup(fd_seen[fd]->memory);
	 else
	{
		vec_free(fd_seen[fd]);
		fd_seen[fd] = 0;
		return (0);
	}

	return (1);
}

