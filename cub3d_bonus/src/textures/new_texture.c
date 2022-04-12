/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:55:56 by jfritz            #+#    #+#             */
/*   Updated: 2022/04/10 21:00:23 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include "../../assets/assets.h"

/**
 * Validates texture resolution and makes sure it is a square
 */
bool	check_texture_res(t_texture *tex)
{
	int	width;
	int	height;

	width = tex->line_size / (tex->bpp / 8);
	height = tex->line_size / (tex->bpp / 8);
	if (width == height && width == 64)
		return (true);
	ft_putendl_fd("Textures are not square or have wrong resolution", 2);
	exit(EXIT_FAILURE);
}

/**
 * Loads the image texture information, prepares int information array too
 */
void	prepare_texture_data(t_texture *t)
{
	int	x;
	int	y;

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
t_texture	*new_texture(void *img_ptr)
{
	t_texture	*texture;

	if (!img_ptr)
		exit_on_texture_error();
	texture = xmalloc(sizeof(t_texture));
	texture->texture_ptr = mlx_get_data_addr(img_ptr, &texture->bpp,
			&texture->line_size, &texture->endian);
	texture->texture = xmalloc(sizeof(int) * 64 * 64);
	texture->texture_data = (int *) texture->texture_ptr;
	check_texture_res(texture);
	texture->width = 64;
	texture->height = 64;
	prepare_texture_data(texture);
	return (texture);
}
