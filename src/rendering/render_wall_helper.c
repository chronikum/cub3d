/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 15:13:00 by jfritz            #+#    #+#             */
/*   Updated: 2022/04/12 10:21:49 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * Writes every pixel in a buffer which we will later print on screen.
 * Also adds distance shading
 */
void	write_in_mlx_buffer(t_cub *cub, int x, int y)
{
	while (y < cub->math->drawend)
	{
		cub->math->texy = (int)cub->math->texpos & (64 - 1);
		cub->math->texpos += cub->math->step;
		cub->math->texcolor
			= get_text_dir(cub)->texture_data[64
			* cub->math->texy + cub->math->texx];
		cub->math->buff[y][x] = distance_color(cub->math->texcolor,
				(cub->math->perpwalldist / 10));
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
		cub->math->wallx
			= cub->player->y + cub->math->perpwalldist * cub->math->raydiry;
	}
	else
	{
		cub->math->wallx
			= cub->player->x + cub->math->perpwalldist * cub->math->raydirx;
	}
	cub->math->wallx -= floor(cub->math->wallx);
	cub->math->texx = (int)(cub->math->wallx * ((double) 64));
	if (cub->math->side == 0 && cub->math->raydirx > 0)
		cub->math->texx = 64 - cub->math->texx - 1;
	if (cub->math->side == 1 && cub->math->raydiry < 0)
		cub->math->texx = 64 - cub->math->texx - 1;
	cub->math->step = 1.0 * 64 / cub->math->lineheight;
	cub->math->texpos = (cub->math->drawstart - HEIGHT
			/ 2 + cub->math->lineheight / 2) * cub->math->step;
	y_helper = cub->math->drawstart;
	write_in_mlx_buffer(cub, x, y_helper);
	cub->math->dBuffer[x] = cub->math->perpwalldist;
}
