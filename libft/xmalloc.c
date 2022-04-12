/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xmalloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:20:48 by jfritz            #+#    #+#             */
/*   Updated: 2022/04/12 12:36:42 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*xmalloc(size_t size)
{
	void	*dest;

	if (size == 0)
		return (NULL);
	dest = malloc(size);
	if (!dest)
		exit(0);
	return (dest);
}
