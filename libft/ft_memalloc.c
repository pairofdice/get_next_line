/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:05:58 by jsaarine          #+#    #+#             */
/*   Updated: 2022/01/10 11:50:40 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*freshbytes;

	if (size == 0)
		return (NULL);
	freshbytes = malloc(size);
	if (!freshbytes)
		return (NULL);
	ft_bzero(freshbytes, size);
	return (freshbytes);
}
