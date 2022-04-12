/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_vector2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:41:42 by jfritz            #+#    #+#             */
/*   Updated: 2022/04/08 13:05:03 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * Updates the given vector with the new values
 */
void	uvec(t_vec2 *vector, double x, double y)
{
	vector->x = x;
	vector->y = y;
}

/**
 * Creates a vector
 */
t_vec2	*create_vector(double x, double y)
{
	t_vec2	*vector2;

	vector2 = xmalloc(sizeof(t_vec2));
	vector2->x = x;
	vector2->y = y;
	return (vector2);
}
