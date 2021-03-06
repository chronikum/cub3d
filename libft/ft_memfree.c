/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 10:57:32 by ysonmez           #+#    #+#             */
/*   Updated: 2022/04/13 14:17:36 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	memfree(void *ptr)
{
	if (ptr == NULL)
		return (1);
	free(ptr);
	ptr = NULL;
	return (1);
}
