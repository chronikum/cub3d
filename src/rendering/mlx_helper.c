/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 15:26:24 by jfritz            #+#    #+#             */
/*   Updated: 2022/04/10 15:27:49 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * Finally loads and displays the image from the buffer on the screen
 */
void	mlx_draw_imagegiven(t_cub *cub)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			cub->data.addr[y * (int)WIDTH + x] = cub->math->buff[y][x];
			x++;
		}
		y++;
	}
}

/**
 * Gets called when a new image is being displayed
 */
void	destroy_mlx_image(t_cub *cub)
{
	mlx_put_image_to_window(cub->vars.mlx, cub->vars.win,
		cub->data.img, 0, 0);
	mlx_destroy_image (cub->vars.mlx, cub->data.img);
}

/**
 * Creates the mlx data values
 */
void	create_mlx_data(t_cub *cub)
{
	cub->data.img = mlx_new_image(cub->vars.mlx, WIDTH, HEIGHT);
	cub->data.addr = (int *) mlx_get_data_addr(cub->data.img,
			&cub->data.bits_per_pixel, &cub->data.line_length,
			&cub->data.endian);
}
