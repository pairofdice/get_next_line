/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 12:16:56 by jsaarine          #+#    #+#             */
/*   Updated: 2021/11/07 13:18:13 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "../libft.h"
#include "ft_colors.h"
#include <stdlib.h>

#include <limits.h>
#include <float.h>


int strdup_1()
{
	char	*memREF;
	char	*memME;

	if (!(memREF = malloc(sizeof(char) * 30)))
		return (-1);
	memset(memREF, 'j', 30);

	if (!(memME = malloc(sizeof(char) * 30)))
		return (-1);
	memset(memME, 'j', 30);

	char test[] = "Hello \0 World";

	memREF = strdup(test);
	memME = ft_strdup(test);
<<<<<<< HEAD
=======

>>>>>>> b1f79ecc0f431ca732f35479b2eee35efbe950d3
	if ( memcmp(memREF, memME, ft_strlen(test)) == 0)
		return (1);
	return (0);
}

void ft_strdup_test(void)
{
	printf("ft_strdup: \t");

	if (strdup_1() == 1)
		printf("💚");
	else
	{
<<<<<<< HEAD
=======

>>>>>>> b1f79ecc0f431ca732f35479b2eee35efbe950d3
		printf("💔");
	}

	printf("\n");
}
