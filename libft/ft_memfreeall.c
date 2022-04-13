/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memfreeall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 10:56:02 by ysonmez           #+#    #+#             */
/*   Updated: 2022/04/13 14:18:00 by jfritz           ###   ########.fr       */
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
		memfree(ptr[i]);
		i++;
	}
	free(ptr);
	ptr = NULL;
	return (1);
}
