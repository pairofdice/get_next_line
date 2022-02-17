/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:49:28 by jsaarine          #+#    #+#             */
/*   Updated: 2022/02/15 16:23:23 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	output(t_vec *storage, char **line)
{
	size_t	len;

	// newlines have been replaced with terminators so str funs work
	*line = ft_strdup(storage->memory);
	len = ft_strlen(storage->memory);
	// storage->len doesn't include null terminator so +1
	// if we have more stuff in memory than the latest line, move it up
	if (storage->len > len + 1)
	{
		ft_memcpy(storage->memory,
			// len means strlen here so just the first line
			&storage->memory[len + 1],
			storage->len - len + 1);
		storage->len -= len + 1;
	}
	// otherwise we're done with the file, because we read until
	// newline or end of file
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

		// makes a vec from the string we read so we can add it to storage
		// excludes string null terminator
		vec_from(&transfer, buffer, ft_strlen(buffer), 1);
		vec_append(storage, &transfer);
		hodl = ft_strchr(storage->memory, '\n');
		if (hodl)
		{
			// weird nested newline search, I dont even know
			// we replace all \n with \0 that we read into storage,
			// while stopping more reads on the first newline
			while (hodl)
			{
				*hodl = '\0';
				hodl = ft_strchr(storage->memory, '\n');
			}
			break ;
		}
		ret = read(fd, buffer, BUFF_SIZE);
	}
	if (!hodl || ret == 0)
		storage->memory[storage->len] = '\0'; // looks sus, probably is
	return (ret);
}

int	get_next_line(const int fd, char **line)
{
	static t_vec	fd_seen[MAX_FD];
	char			*hodl;

	if (fd < 0 || fd >= MAX_FD || line == NULL)
		return (-1);
	if (!fd_seen[fd].memory)
		vec_new(&fd_seen[fd], BUFF_SIZE * 2, 1);
	hodl = ft_strchr(fd_seen[fd].memory, '\n');
	if (hodl) // If we read more than one line into memory last go around...
	{		// But wait a moment I thought I changed all newlines to Terminator already
		*hodl = '\0';
		output(&fd_seen[fd], line);
		return (1);
	}
	if (read_into_storage(&fd_seen[fd], fd) < 0)
		return (-1);
	if (fd_seen[fd].len <= 0) // When we have exhausted our storage we're done
	{
		vec_free(&fd_seen[fd]);
		return (0);
	}
	output(&fd_seen[fd], line);
	return (1);
}
