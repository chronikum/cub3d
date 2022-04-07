/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_preparing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:08:48 by jfritz            #+#    #+#             */
/*   Updated: 2022/04/07 19:04:49 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h" 


int	render_loop(void	*cub_)
{
	int		x;
	t_cub	*cub;

	cub = (t_cub *) cub_;
	x = 0;
	while (x < (int)WIDTH)
	{
		render_walls(cub, x);
		draw_line_color(cub, create_vector(x, cub->math->drawStart), create_vector(x, cub->math->drawEnd), 8355711);
		x++;
	}

	return (0);
}

/**
 * Creates a window, creates mlx variables, loads the textures, setup hooks and loops
 * Sets initial key controls too
 */
static void	create_window(t_cub *cub)
{
	cub->vars.mlx = mlx_init();
	cub->vars.win = mlx_new_window(cub->vars.mlx, WIDTH, HEIGHT, "CUB3D");
	cub->movetrigger = initalize_key_trigger();
	cub->math = xmalloc(sizeof(t_math));
	calculate_player_pos(cub);
	if (!load_textures(cub))
		exit(EXIT_FAILURE);
	mlx_mouse_hide();
	mlx_hook(cub->vars.win, 2, 1L << 0, key_handler, cub);
	mlx_hook(cub->vars.win, 3, 1L << 0, key_up, cub);
	// mlx_hook(cub->vars.win, 4, 1L << 2, fov_handler, cub);
	mlx_loop_hook(cub->vars.mlx, render_loop, cub);
	mlx_loop(cub->vars.mlx);
}

/**
 * Starts cub3d
 */
void	start_cub3d(t_cub *cub)
{
	create_window(cub);
}