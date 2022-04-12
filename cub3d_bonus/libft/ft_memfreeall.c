/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memfreeall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 10:56:02 by ysonmez           #+#    #+#             */
/*   Updated: 2022/02/09 15:23:10 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_memfreeall(void **ptr)
{
	int	i;

	i = 0;
	if (ptr == NULL)
		return (1);
	while (ptr[i] != NULL)
	{
		ft_memfree(ptr[i]);
		i++;
	}
	free(ptr);
	ptr = NULL;
	return (1);
}
