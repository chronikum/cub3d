/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 20:27:57 by jfritz            #+#    #+#             */
/*   Updated: 2022/04/10 20:33:06 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h" 

void	exit_on_texture_error(void)
{
	ft_putendl_fd("Texture files corrupted or missing.", 2);
	exit(EXIT_FAILURE);
}

void	exit_on_error(void)
{
	ft_putendl_fd("Map file corrupted.", 2);
	exit(EXIT_FAILURE);
}