/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 20:03:42 by jsaarine          #+#    #+#             */
/*   Updated: 2022/01/20 15:30:45 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	take a pointer to a t_vec and allocate len * elem_size bytes
	in the buffer as well as initialize its length and element size.
*/
int	vec_new(t_vec *src, size_t init_len, size_t elem_size)
{
	if (!src || elem_size == 0)
		return (-1);
	if (init_len == 0)
		src->memory = NULL;
	else
	{
		src->memory = malloc(init_len * elem_size);
		if (!src->memory)
			return (-1);
	}
	src->len = 0;
	src->alloc_size = init_len * elem_size;
	src->elem_size = elem_size;
	return (1);
}
