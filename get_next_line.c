/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:49:28 by jsaarine          #+#    #+#             */
/*   Updated: 2022/02/13 22:21:45 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	output(t_vec *storage, char **line)
{
	size_t	len;

	*line = ft_strdup(storage->memory);
	len = ft_strlen(storage->memory);
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

int		read_into_storage(t_vec *storage, const int fd)
{
	t_vec	transfer;
	ssize_t	ret;
	char	*hodl;
	char	buffer[BUFF_SIZE + 1];

	ret = read(fd, buffer, BUFF_SIZE);

	while (ret > 0)
	{
		buffer[ret] = '\0';
		//vec_strapp(storage, buffer);
		vec_from(&transfer, buffer, ft_strlen(buffer), 1);
		vec_append(storage, &transfer);
		hodl = ft_strchr(storage->memory, '\n');
		if (hodl)
		{
			while (hodl)
			{
				*hodl = '\0';
				hodl = ft_strchr(storage->memory, '\n');
			}
			break ;
		}

		ret = read(fd, buffer, BUFF_SIZE);
	}
	if (!hodl && ret == 0)
		storage->memory[storage->len] = '\0';
	return (ret);
}

int	get_next_line(const int fd, char **line)
{
	t_vec			*fd_seen[MAX_FD];
	static t_vec	storage;
	char			*hodl;

	if (fd < 0 || fd >= MAX_FD || line == NULL)
		return (-1);

	if (!fd_seen[fd])
	{
		vec_new(&storage, BUFF_SIZE * 2, 1);
		fd_seen[fd] = &storage;
	}
	hodl = ft_strchr(storage.memory, '\n');
	if (hodl)
	{
		*hodl = '\0';
		output(&storage, line);
		return (1);
	}
	if (read_into_storage(fd_seen[fd], fd) < 0)
		return (-1);
	if (fd_seen[fd]->len <= 0)
	{
		vec_free(fd_seen[fd]);
		fd_seen[fd] = 0;
		return (0);
	}
	output(fd_seen[fd], line);
	return (1);
}
