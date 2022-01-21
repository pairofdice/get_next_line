/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:49:28 by jsaarine          #+#    #+#             */
/*   Updated: 2022/01/21 18:07:49 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	buff_new(t_buff *new_buff)
{
	t_vec	vec;

	if (vec_new(&vec, BUFF_SIZE * 2, sizeof(char)) == -1)
		return (-1);
	new_buff->content_vec = &vec;
	new_buff->index = 0;
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	t_vec			new;
	static t_buff	*fd_seen[MAX_FD] = {0};
	t_buff			temp_buff;
	t_vec			temp_vec;
	char			temp_string[BUFF_SIZE + 1];
	int				ret;

	if (fd > MAX_FD || fd < 0 || !line)
		return (-1);

	if (fd_seen[fd])
	{
		if (fd_seen[fd]->index - 1 >= fd_seen[fd]->content_vec->len)
		{
			// we've gone through the whole thing and need to free stuff
			// TODO
			return (0);
		}
	}
	else
	{
		if (buff_new(&temp_buff) == -1)
			return (-1);
		fd_seen[fd] = &temp_buff;
		ret = read(fd, temp_string, BUFF_SIZE);
		while (ret > 0)
		{
			if (vec_from(&temp_vec,
						temp_string,
						ret,
						sizeof(char)) == -1)
				return (-1);
			if (vec_append(&fd_seen[fd]->content_vec, &temp_vec) == -1)
				return (-1);
			ret = read(fd, temp_string, BUFF_SIZE);
		}
	}
	// I'm still not inserting terminators at newlines
	vec_push(fd_seen[fd]->content_vec, '\0');
	*line = &temp_vec.memory[fd_seen[fd]->index];
	fd_seen[fd]->index += ft_strlen(temp_vec.memory[fd_seen[fd]->index] + 1);

	return (0);
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
