int vec_strapp()
{
	if (!vec || !elem)
		return (-1);
	if ((vec->len * vec->elem_size) >= vec->alloc_size)
		if (vec_resize(vec, vec->len * 2) == -1)
			return (-1);
}



#include "libft.h"
#include <stdio.h>
/*
	appends vector src to dst
*/
int	vec_append(t_vec *dst, t_vec *src)
{
	size_t	space_needed;

	if (!dst || !src || !src->memory)
		return (-1);
	if (!dst->memory)
		vec_new(dst, 1, 1);
	space_needed = dst->len * dst->elem_size + src->len * src->elem_size;
	if (dst->alloc_size < space_needed)
	{
		if (vec_resize(dst, space_needed * 2) == -1)
			return (-1);
		//dst->alloc_size = space_needed * 2;
	}
	ft_memcpy(
		&dst->memory[dst->len * dst->elem_size],
		src->memory,
		src->len * 1);
	dst->len += src->len;
	vec_free(src);
	return (1);
}
#include "libft.h"
/*
	takes in a vector and a pointer to an element to be pushed to the
	end of the vector.
 */
int	vec_push(t_vec *vec, void *elem)
{
	if (!vec || !elem)
		return (-1);
	if ((vec->len * vec->elem_size) == vec->alloc_size)
		if (vec_resize(vec, vec->len * 2) == -1)
			return (-1);
	ft_memcpy(&vec->memory[vec->len * vec->elem_size], elem, vec->elem_size);
	vec->len++;
	return (1);
}
