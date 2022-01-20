/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:49:28 by jsaarine          #+#    #+#             */
/*   Updated: 2022/01/20 16:32:27 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	t_vec			new;
	static t_buff	*fd_seen[MAX_FD] = {0};
	t_vec			temp;
	char			temp_string[BUFF_SIZE + 1];
	int				ret;

	if (fd > MAX_FD || fd < 0 || !line)
		return (-1);
	if (fd_seen[fd])
	{
		if (fd_seen[fd]->index - 1 >= fd_seen[fd]->content->len)
		{
			return (0);
		}
		temp = *fd_seen[fd]->content;
		line = temp.memory[fd_seen[fd]->index];
		return (1);
	}
	else
	{
		if (vec_new(&new, BUFF_SIZE * 2, sizeof(**line)) == -1)
			return (-1);
		ret = read(fd, temp_string, BUFF_SIZE);
		while (ret > 0)
		{
			temp_string[ret] = '\0';
			ft_putendl(temp_string);
			ret = read(fd, temp_string, BUFF_SIZE);
		}
	}
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
		just vec_append() // TODO
		amount of stuff we read should be in vector.len
	replace newlines with terminators to make each line a separate string
	if we're not done with this input, put it in the fd_seen buffer

if we have seen this FD before
	check if we have read everything
		if index-1 >= vec.len or something
		freeeeeeeeeee()
	find spot in line with index and send it on its way

update index to point past the bit we just read



 */
