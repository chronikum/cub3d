/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:57:47 by jfritz            #+#    #+#             */
/*   Updated: 2022/04/08 13:09:54 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h" 

/**
 * Calculates the steps by checking which number
 * is bigger
 */
static int	calculate_steps(int dx, int dy)
{
	if (abs(dx) > abs(dy))
		return (abs(dx));
	return (abs(dy));
}

/*
	Draws a line with the given color and returns the drawn distance
	Takes target and origin point.
*/
int	draw_line_color(t_cub *cub, t_vec2 *v1, t_vec2 *v0, int color)
{
	int		dd[2];
	int		steps;
	double	xinc;
	double	yinc;
	int		i;

	i = 0;
	dd[0] = v1->x - v0->x;
	dd[1] = v1->y - v0->y;
	steps = calculate_steps(dd[0], dd[1]);
	xinc = dd[0] / (double) steps;
	yinc = dd[1] / (double) steps;
	while (i <= steps)
	{
		if (v0->x < WIDTH && v0->y < HEIGHT && v0->x > 0 && v0->y > 0)
			my_mlx_pixel_put(&cub->data, v0->x, v0->y, color);
		v0->x += xinc;
		v0->y += yinc;
		i++;
	}
	return (-1);
}