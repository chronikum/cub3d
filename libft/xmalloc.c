/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xmalloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:20:48 by jfritz            #+#    #+#             */
/*   Updated: 2022/04/13 16:11:52 by jfritz           ###   ########.fr       */
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
		exit(1);
	return (dest);
}
