#include "libft.h"
#include <stdio.h>



int vec_strapp(t_vec *vec, char *str)
{
	ssize_t	len;

	if (!vec || !str)
		return (-1);
	len = ft_strlen(str);
	if ((vec->len * vec->elem_size) +  len >= vec->alloc_size)
		if (vec_resize(vec, (vec->len + len) * 2) == -1)
			return (-1);
	ft_memcpy(&vec->memory[vec->len * vec->elem_size], str, len);
	vec->len += len;
	return (1);
}



