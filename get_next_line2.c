/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:49:28 by jsaarine          #+#    #+#             */
/*   Updated: 2022/02/12 14:55:38 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>


void	output_update(t_vec *storage, char **line)
{
	ssize_t	len;

	*line = ft_strdup(storage->index);
	len = ft_strlen(storage->index);
	if (storage->len > len + 1)
	{
		ft_memcpy(storage->memory,
			&storage->memory[len + 1],
			storage->len - len + 1);
		storage->len -= len + 1;
	}
	else
		storage->len = 0;
}

void	read_into_storage(t_vec *buffer, char **line, const int fd)
{
	t_vec	transfer;
	ssize_t	ret;
	char	*hodl;
	char	read_into[BUFF_SIZE + 1];

	ret = read(fd, read_into, BUFF_SIZE);
	while (ret > 0)
	{
		read_into[ret] = '\0';
		vec_from(&transfer, read_into, ft_strlen(read_into), 1);
		vec_append(buffer, &transfer);
		hodl = ft_strchr(buffer->memory, '\n');
		if (hodl)
		{
			while (hodl)
			{
				*hodl = '\0';
				hodl = ft_strchr(buffer->memory, '\n');
			}
			break ;
		}
		ret = read(fd, read_into, BUFF_SIZE);
	}
}

int	get_next_line(const int fd, char **line)
{
	t_vec			*fd_seen[MAX_FD];
	static t_vec	buffer;
	int				len;
	char			*hodl;

	if (!fd_seen[fd])
	{
		vec_new(&buffer, BUFF_SIZE * 2, 1);
		fd_seen[fd] = &buffer;
	}
	hodl = ft_strchr(buffer.memory, '\n');
	if (hodl)
	{
		*hodl = '\0';
		jotain(&buffer, line);
		return (1);
	}
	read_into_storage(fd_seen[fd], line, fd);
	if (fd_seen[fd]->len <= 0)
	{
		vec_free(fd_seen[fd]);
		fd_seen[fd] = 0;
		return (0);
	}
	jotain(fd_seen[fd], line);
	return (1);
}
