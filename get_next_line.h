/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:13:00 by jsaarine          #+#    #+#             */
/*   Updated: 2022/02/03 11:45:29 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1
# define MAX_FD 8192

# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"

int	get_next_line(const int fd, char **line);

typedef struct s_buff
{
	size_t	index;
	t_vec	*content_vec;
}	t_buff;

#endif
