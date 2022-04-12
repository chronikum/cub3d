/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 19:08:21 by jfritz            #+#    #+#             */
/*   Updated: 2022/04/10 19:09:42 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/*
	Rotates the view with the mouse movement on the X axis
*/
int	mouse_handler(t_cub *cub)
{
	static int	old_x = 0;
	int			x;
	int			y;

	x = 1;
	y = 2;
	mlx_mouse_get_pos(cub->vars.win, &x, &y);
	if (x < old_x)
		rotate_left(cub);
	else if (x > old_x)
		rotate_right(cub);
	mlx_mouse_move(cub->vars.win, 100, 100);
	old_x = 100;
	return (0);
}
