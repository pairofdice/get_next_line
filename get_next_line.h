/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:13:00 by jsaarine          #+#    #+#             */
/*   Updated: 2022/02/09 20:04:49 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 10000
# define MAX_FD 8192

# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"

int	get_next_line(const int fd, char **line);

#endif
