/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_append.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 20:03:52 by jsaarine          #+#    #+#             */
/*   Updated: 2022/01/20 16:27:55 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
	appends vector src to dst
*/
int	vec_append(t_vec *dst, t_vec *src)
{
	size_t	space_needed;

	if (!dst || !src || !src->memory)
		return (-1);
	if (!dst->memory)
		vec_new(dst, 1, dst->elem_size);
	space_needed = dst->len * dst->elem_size + src->len * src->elem_size;
	if (dst->alloc_size < space_needed)
	{
		if (vec_resize(dst, space_needed * 2) == -1)
			return (-1);
	}
	memcpy(
		&dst->memory[dst->len * dst->elem_size],
		src->memory,
		src->len * src->elem_size);
	dst->len += src->len;
	return (1);
}
