/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 20:03:31 by jsaarine          #+#    #+#             */
/*   Updated: 2022/01/12 20:04:04 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
	takes in a vector and a pointer to an element to be pushed to the
	end of the vector.
 */
int	vec_push(t_vec *src, void *elem)
{
	if (!src || !elem)
		return (-1);
	if ((src->len * src->elem_size) == src->alloc_size)
		if (vec_resize(src, src->len * 2) == -1)
			return (-1);
	ft_memcpy(&src->memory[src->len * src->elem_size], elem, src->elem_size);
	src->len++;
	return (1);
}
