/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frames_per_second.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:31:46 by jfritz            #+#    #+#             */
/*   Updated: 2022/04/07 17:32:05 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/*
	TODO: REMOVE BEFORE EVAL
	Gets the time
*/
long	get_time(void)
{
	struct timeval	tp;
	long			milliseconds;

	gettimeofday(&tp, NULL);
	milliseconds = tp.tv_sec * 1000;
	milliseconds += tp.tv_usec / 1000;
	return (milliseconds);
}

/*
	TODO: REMOVE BEFORE EVAL
	Calculates the frames per seconds
*/
int	display_fps(void)
{
	static int	frames = 0;
	static long	old_time = 0;
	static int	reset = 0;

	if (reset)
	{
		reset = 0;
		frames = 0;
	}
	if ((get_time() - old_time) >= 100)
	{
		old_time = get_time();
		reset = 1;
		return (frames * 10);
	}
	frames++;
	return (-1);
}

/*
	TODO: REMOVE BEFORE EVAL
	Renders the frames per seconds
*/
int	render_fps(t_cub *cub, int frames)
{
	static char	*frames_char = "WAITING";

	if (frames != -1)
	{
		frames_char = ft_itoa(frames);
		mlx_string_put(cub->vars.mlx, cub->vars.win, 0 + 20, 20,
			16777215, frames_char);
	}
	else
		mlx_string_put(cub->vars.mlx, cub->vars.win, 0 + 20, 20,
			16777215, frames_char);

	mlx_string_put(cub->vars.mlx, cub->vars.win, 0 + 20, 20,
			16777215, frames_char);
	return (-1);
}
