/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_preparing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:08:48 by jfritz            #+#    #+#             */
/*   Updated: 2022/04/08 12:48:47 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h" 

/**
 * Gets called when a new image is being displayed
 */
void	destroy_mlx_image(t_cub *cub)
{
	mlx_put_image_to_window(cub->vars.mlx, cub->vars.win, cub->data.img, 0, 0);
	mlx_destroy_image (cub->vars.mlx, cub->data.img);
}

/**
 * Creates the mlx data values
 */
void	create_mlx_data(t_cub *cub)
{
	cub->data.img = mlx_new_image(cub->vars.mlx, WIDTH, HEIGHT);
	cub->data.addr = mlx_get_data_addr(cub->data.img, &cub->data.bits_per_pixel,
			&cub->data.line_length, &cub->data.endian);
}

/**
 * This is the render loop. It gets called every frame.
 * There is a cache which will prevent the image from updating
 * when nothing changed.
 */
int	render_loop(void	*cub_)
{
	int		x;
	t_cub	*cub;
	t_vec2	*start_vector;
	t_vec2	*end_vector;

	x = 0;
	cub = (t_cub *) cub_;
	if (is_player_in_cache(cub))
		return (0);
	create_mlx_data(cub);
	start_vector = create_vector(x, cub->math->drawStart);
	end_vector = create_vector(x, cub->math->drawEnd);
	while (x < (int)WIDTH)
	{
		render_walls(cub, x);
		draw_line_color(cub, start_vector, end_vector, 8355711);
		x++;
	}
	destroy_mlx_image(cub);
	free(end_vector);
	free(start_vector);
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