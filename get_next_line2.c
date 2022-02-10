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


/* void jotain(t_vec &buffer)
{

} */

int	get_next_line(const int fd, char **line, int i)
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
// if we have stuff in memory we have to keep finding newlines until there are no more
/* else {
	hodl = ft_strchr(read_into, '\n');
	*hodl = '\0'
} */

if (i > 0)
{
 	printf("%s   %i\n", fd_seen[fd]->memory, i); 
	if (i > 6)
		return 0;
}


ret = read(fd, read_into, BUFF_SIZE);
while (ret > 0)
{
	read_into[ret] = '\0';					//vec_from(&transfer, read_into, ft_strlen(read_into), 1);
/* 	vec_strapp(fd_seen[fd], read_into); */
	vec_from(&transfer, read_into, ft_strlen(read_into), 1);
	vec_append(fd_seen[fd], &transfer);

	hodl = ft_strchr(read_into, '\n');
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



	*line = ft_strdup(fd_seen[fd]->memory);
	len = ft_strlen(fd_seen[fd]->memory);
	if (fd_seen[fd]->len > len + 1) // we're safe to move pointer and not done with file
	{
		fd_seen[fd]->memory += len + 1;
		fd_seen[fd]->len -= len + 1;
	}

	return (1);
}
