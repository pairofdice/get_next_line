/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 20:03:48 by jsaarine          #+#    #+#             */
/*   Updated: 2022/02/09 20:42:43 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
	frees the allocated resources in src and zeroes its fields.
 */
void	vec_free(t_vec *src)
{
	if (!src || src->alloc_size == 0)
		return ;
	free(src->memory);
	src->memory = NULL;
	src->elem_size = 0;
	src->alloc_size = 0;
	src->len = 0;
}
