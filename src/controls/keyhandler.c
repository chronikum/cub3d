/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:24:05 by ysonmez           #+#    #+#             */
/*   Updated: 2022/04/08 15:01:19 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * Initializes move trigger for cub3d struct
 */
t_move_trigger	*initalize_key_trigger()
{
	t_move_trigger	*move_trigger;

	move_trigger = xmalloc(sizeof(move_trigger));
	move_trigger->is_moving_up = false;
	move_trigger->is_moving_down = false;
	move_trigger->is_moving_left = false;
	move_trigger->is_moving_right = false;
	move_trigger->is_rotating_left = false;
	move_trigger->is_rotating_right = false;

	return (move_trigger);
}

/*	Event hook to close the window with ESCAPE */
static void	close_window(t_cub *cub)
{
	mlx_destroy_window(cub->vars.mlx, cub->vars.win);
	clear_data(cub);
	exit(EXIT_SUCCESS);
}

/*	KEYPRESS HANDLER : event hook depending on pressed key */
int	key_handler(int keycode, t_cub *cub)
{
	if (keycode == W)
		cub->movetrigger->is_moving_up = true;
	if (keycode == S)
		cub->movetrigger->is_moving_down = true;
	if (keycode == A)
		cub->movetrigger->is_moving_left = true;
	if (keycode == D)
		cub->movetrigger->is_moving_right = true;
	if (keycode == LEFT)
		cub->movetrigger->is_rotating_left = true;
	if (keycode == RIGHT)
		cub->movetrigger->is_rotating_right = true;
	if (keycode == ESCAPE)
		close_window(cub);
	return (0);
}

/*	Key goes up again */
int	key_up(int keycode, t_cub *cub)
{
	if (keycode == W)
		cub->movetrigger->is_moving_up = false;
	if (keycode == S)
		cub->movetrigger->is_moving_down = false;
	if (keycode == A)
		cub->movetrigger->is_moving_left = false;
	if (keycode == D)
		cub->movetrigger->is_moving_right = false;
	if (keycode == LEFT)
		cub->movetrigger->is_rotating_left = false;
	if (keycode == RIGHT)
		cub->movetrigger->is_rotating_right = false;
	return (0);
}
