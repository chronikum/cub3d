/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 15:13:00 by jfritz            #+#    #+#             */
/*   Updated: 2022/04/11 16:44:28 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * Writes every pixel in a buffer which we will later print on screen.
 * Also adds distance shading
 */
void	write_in_mlx_buffer(t_cub *cub, int x, int y)
{
	while (y < cub->math->drawEnd)
	{
		cub->math->texY = (int)cub->math->texPos & (64 - 1);
		cub->math->texPos += cub->math->step;
		cub->math->texColor
			= get_text_dir(cub)->texture_data[64
			* cub->math->texY + cub->math->texX];
		cub->math->buff[y][x] = distance_color(cub->math->texColor,
				(cub->math->perpWallDist / 10));
		y++;
	}
}

/**
 * Draws the texture/gets what we need for texture
 * and writes it in pixel buffer
 */
void	draw_textures(t_cub *cub, int x)
{
	int	y_helper;

	if (cub->math->side == 0)
	{
		cub->math->wallX
			= cub->player->y + cub->math->perpWallDist * cub->math->rayDirY;
	}
	else
	{
		cub->math->wallX
			= cub->player->x + cub->math->perpWallDist * cub->math->rayDirX;
	}
	cub->math->wallX -= floor(cub->math->wallX);
	cub->math->texX = (int)(cub->math->wallX * ((double) 64));
	if (cub->math->side == 0 && cub->math->rayDirX > 0)
		cub->math->texX = 64 - cub->math->texX - 1;
	if (cub->math->side == 1 && cub->math->rayDirY < 0)
		cub->math->texX = 64 - cub->math->texX - 1;
	cub->math->step = 1.0 * 64 / cub->math->lineHeight;
	cub->math->texPos = (cub->math->drawStart - HEIGHT
			/ 2 + cub->math->lineHeight / 2) * cub->math->step;
	y_helper = cub->math->drawStart;
	write_in_mlx_buffer(cub, x, y_helper);
	cub->math->dBuffer[x] = cub->math->perpWallDist;
}
