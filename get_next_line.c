/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:49:28 by jsaarine          #+#    #+#             */
/*   Updated: 2022/01/21 19:12:23 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/* static int	buff_new(t_buff *new_buff)
{
	t_vec	*vec;

	vec = malloc(sizeof(vec));

 	if (vec_new(vec, BUFF_SIZE * 2, 1) == -1)
	{
		return (-1);
	} 
	
	new_buff->content_vec = vec;
	new_buff->index = 0;

	return (1);
} */

int	get_next_line(const int fd, char **line)
{
	char		read_into[BUFF_SIZE + 1];
	char 		*hodl;
	static t_vec		*fd_seen[MAX_FD];
	t_vec		transfer;
	t_vec		buffer;
	ssize_t		ret;


	if (fd_seen[fd])
	{
		ft_putendl("Hi");
		fd_seen[fd]->memory += 1;
	}
	else
	{
		vec_new(&buffer,BUFF_SIZE, 1);
		fd_seen[fd] = &buffer;
	}


	ret = read(fd, read_into, BUFF_SIZE);
	while (ret > 0)
	{
		ft_putendl("Ah");
		vec_free(&transfer);
		ft_putendl("Ahh");
		vec_from(&transfer, read_into, ft_strlen(read_into), 1);
		
		vec_append(fd_seen[fd], &transfer);
		hodl = ft_strchr(fd_seen[fd]->memory, '\n');
		if (hodl)
		{
			fd_seen[fd]->memory[hodl - fd_seen[fd]->memory] = '\0';
			break;
		}
		ret = read(fd, read_into, BUFF_SIZE);
	}
	vec_push(fd_seen[fd], "\0");
	*line = ft_strdup(fd_seen[fd]->memory);
	if (ft_strlen(fd_seen[fd]->memory) == 0)
	{
		vec_free(fd_seen[fd]);
		fd_seen[fd] = 0;
		return (0);
	}
	return (1);
}

/*
pseudocode
check input
	FD?
		We need to have a File Descriptor from 0 to 8192(?)
	line?
		We need a pointer to string

when we haven't seen fd before:
	init a struct with fd, index 0, vector
		if not good, free, return -1
	read the whole input into the vector
		just vec_append()
		amount of stuff we read should be in vector.len
	replace newlines with terminators to make each line a separate string
	if we're not done with this input, put it in the fd_seen buffer

if we have seen this FD before
	check if we have read everything
		if index-1 >= vec.len or something
		freeeeeeeeeee()
	find spot in line with index and send it on its way

update index to point past the bit we just read

???

 */
