/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:55:56 by jfritz            #+#    #+#             */
/*   Updated: 2022/04/08 16:26:31 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include "../../assets/assets.h"

/**
 * Loads the image texture information, prepares int information array too
 */
void	prepare_texture_data(t_texture *t)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < t->height)
	{
		x = 0;
		while (x < t->width)
		{
			t->texture[t->width * y + x] = t->texture_ptr[t->width * y + x];
			x++;
		}
		y++;
	}
}

/**
 * Loads a texture struct with the given img_ptr and
 * returns it. Fills the texture with texture data int array
 */
t_texture	*new_texture(void *img_ptr, t_cub *cub)
{
	t_texture		*texture;

	(void) cub;
	texture = xmalloc(sizeof(t_texture)); //to free in clear_data.c
	texture->texture_ptr = mlx_get_data_addr(img_ptr, &texture->bpp, &texture->line_size,
		&texture->endian);
	texture->texture = xmalloc(sizeof(int) * 64 * 64);
	texture->texture_data = (int *) texture->texture_ptr;
	texture->width = 64;
	texture->height = 64;
	prepare_texture_data(texture);
	printf("Texture size: %d\n", texture->width);
	return (texture);
}
