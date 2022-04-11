/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:07:22 by jfritz            #+#    #+#             */
/*   Updated: 2022/04/11 16:45:20 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * As further away, as darker the color is
 */
int	distance_color(int c, double d)
{
	if (d <= 1.)
		return (c);
	return (((int)(((16711680 & c) >> 16) / d) << 16)
		+ ((int)(((65280 & c) >> 8) / d) << 8)
		+ ((int)((255 & c) / d)));
}


/**
 * As further away, as darker the color is
 */
int	distance_stepped(int c, double max_d, double steps, double step)
{
	if (max_d <= 1.)
		return (c);
	//printf("MAX D: %f STEPS %f STEP %f\n", max_d, steps, step);
	//printf("CALCULATED D: %f STEPS %f STEP %f\n", (max_d / steps) * step, steps, step);
	double calculated_distance = fabs(max_d - ((max_d / steps) * step));
	if (calculated_distance <= 1.)
		return (c);
	(void) step;
	(void) steps;
	return (((int)(((16711680 & c) >> 16) / calculated_distance) << 16)
		+ ((int)(((65280 & c) >> 8) / calculated_distance) << 8)
		+ ((int)((255 & c) / calculated_distance)));
}
