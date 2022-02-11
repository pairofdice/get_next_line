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


void jotain(t_vec *buffer, char **line)
{
	ssize_t	len;
	*line = ft_strdup(buffer->memory);
	len = ft_strlen(buffer->memory);

	if (buffer->len > len + 1) // We need to memcpy instead of move pointer
	{
		/* fd_seen[fd]->memory += len + 1;*/
		ft_memcpy(buffer->memory, &buffer->memory[len + 1], buffer->len - len + 1);
		buffer->len -= len + 1; 
	}
		else
	{
		buffer->len = 0;
	}
}

int	get_next_line(const int fd, char **line)
{
	char			read_into[BUFF_SIZE + 1];
	char			*hodl;
	t_vec			*fd_seen[MAX_FD];
	t_vec			transfer;
	static t_vec	buffer;
	ssize_t			ret;
	int				len;

if (!fd_seen[fd])
{
	vec_new(&buffer, BUFF_SIZE * 2, 1);
	fd_seen[fd] = &buffer;
}


hodl = ft_strchr(fd_seen[fd]->memory, '\n');
if (hodl)
{
	*hodl = '\0';						// fd_seen[fd]->len = ft_strlen(fd_seen[fd]->memory  ) + 1;
	jotain(fd_seen[fd], line);
	/* ft_putendl("here"); */
	return (1); 								// maybe push null terminator onto fd_seen[fd] here
} 

/* if (i > 0)
{
 	printf("%s   %i\n", fd_seen[fd]->memory, i); 
	if (i > 6)
		return 0;
}
 */

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
		while (hodl)
		{
			*hodl = '\0';						// fd_seen[fd]->len = ft_strlen(fd_seen[fd]->memory  ) + 1;
			hodl = ft_strchr(fd_seen[fd]->memory, '\n');
		}
		break; 								// maybe push null terminator onto fd_seen[fd] here
	}
	ret = read(fd, read_into, BUFF_SIZE);
}

if (fd_seen[fd]->len <= 0)
{
	vec_free(fd_seen[fd]);
	fd_seen[fd] = 0;
	return (0);
}


/* 	*line = ft_strdup(fd_seen[fd]->memory);
	len = ft_strlen(fd_seen[fd]->memory);
	if (fd_seen[fd]->len > len + 1) // We need to memcpy instead of move pointer
	{
		// fd_seen[fd]->memory += len + 1;
		ft_memcpy(fd_seen[fd]->memory, &fd_seen[fd]->memory[len + 1], fd_seen[fd]->len - len + 1);
		fd_seen[fd]->len -= len + 1; 
	}
	else
	{
		fd_seen[fd]->len = 0;
	} */
	jotain(fd_seen[fd], line);

	return (1);
}
