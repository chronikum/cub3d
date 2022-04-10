/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:32:11 by jfritz            #+#    #+#             */
/*   Updated: 2022/04/10 16:21:16 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include "../../assets/assets.h"

/*
	Loads and saves the image for NO.
	It holds the image in static memory to reduce load.
*/
void	*load_no_image(t_cub *cub)
{
	void		*img;
	int			pos[2];
	t_vars		vars;

	vars = cub->vars;
	img = mlx_xpm_file_to_image(&vars.mlx, cub->no, &pos[0], &pos[1]);
	cub->img_no = img;
	cub->tex_no = new_texture(img);
	return (img);
}

/*
	Loads and saves the image for SO.
	It holds the image in static memory to reduce load.
*/
void	*load_so_image(t_cub *cub)
{
	void		*img;
	int			pos[2];
	t_vars		vars;

	vars = cub->vars;
	img = mlx_xpm_file_to_image(&vars.mlx, cub->so, &pos[0], &pos[1]);
	cub->img_so = img;
	cub->tex_so = new_texture(img);
	return (img);
}

/*
	Loads and saves the image for WE.
	It holds the image in static memory to reduce load.
*/
void	*load_we_image(t_cub *cub)
{
	void		*img;
	int			pos[2];
	t_vars		vars;

	vars = cub->vars;
	img = mlx_xpm_file_to_image(&vars.mlx, cub->we, &pos[0], &pos[1]);
	cub->img_we = img;
	cub->tex_we = new_texture(img);
	return (img);
}

/*
	Loads and saves the image for EA.
	It holds the image in static memory to reduce load.
*/
void	*load_ea_image(t_cub *cub)
{
	void		*img;
	int			pos[2];
	t_vars		vars;

	vars = cub->vars;
	img = mlx_xpm_file_to_image(&vars.mlx, cub->ea, &pos[0], &pos[1]);
	cub->img_ea = img;
	cub->tex_ea = new_texture(img);
	return (img);
}

/*
	Initiates loading of the textures.
	If a image should not exist, this function will fail.
*/
bool	load_textures(t_cub *cub)
{
	if (load_no_image(cub) && load_so_image(cub) && load_we_image(cub)
		&& load_ea_image(cub))
		return (true);
	ft_putendl_fd("Error: One or more textures are missing.", 2);
	return (false);
}
