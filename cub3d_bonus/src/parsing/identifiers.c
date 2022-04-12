/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifiers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:52:48 by ysonmez           #+#    #+#             */
/*   Updated: 2022/04/11 14:30:55 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/*	Return the number of strings in an array */
static int	count_str(char **ar)
{
	int	i;

	i = 0;
	if (!ar)
		return (0);
	while (ar[i])
		i++;
	return (i);
}

/*	Check if the data related to identifier is copletely fulled
*	If yes set the bool cub->id to true and go for filling the data
*	related to the map
*/
void	identifier_done(t_cub *cub)
{
	if (cub->no == NULL)
		return ;
	if (cub->so == NULL)
		return ;
	if (cub->we == NULL)
		return ;
	if (cub->ea == NULL)
		return ;
	if (cub->floor < 0)
		return ;
	if (cub->ceiling < 0)
		return ;
	cub->id_done = true;
}

/*	Go through empty spaces and store the texture path
*	of a specific identifier
*/
static void	fill_path(char **path, char *read)
{
	int		i;

	i = 0;
	while (read[i] == ' ')
		i++;
	if (read[i] != '\0')
		*path = ft_strdup(&read[i]);
}

/*	Go through empty spaces and store the RGB
*	values of Floor / Ceiling
*	int = 65536 * R + 256 * G + B;
*/
static void	fill_rgb(int *color, char *read)
{
	int		i;
	char	**arr;
	int		rgb[3];

	i = 0;
	while (read[i] == ' ')
		i++;
	if (ft_isdigit(read[i]) == 0)
		return ;
	arr = ft_split(&read[i], ',');
	if (arr == NULL)
		return ;
	if (count_str(arr) != 3)
	{
		ft_memfreeall((void **)arr);
		return ;
	}
	rgb[0] = ft_atoi(arr[0]);
	rgb[1] = ft_atoi(arr[1]);
	rgb[2] = ft_atoi(arr[2]);
	ft_memfreeall((void **)arr);
	if (!check_rgb_valid(rgb[0], rgb[1], rgb[2]))
		return ;
	*color = (65536 * rgb[0]) + (256 * rgb[1]) + rgb[2];
}

int	identifier(t_cub *cub, char *read)
{
	if (read[0] == 'N' && read[1] == 'O' && read[2] == ' ')
		fill_path(&cub->no, &read[2]);
	else if (read[0] == 'S' && read[1] == 'O' && read[2] == ' ')
		fill_path(&cub->so, &read[2]);
	else if (read[0] == 'W' && read[1] == 'E' && read[2] == ' ')
		fill_path(&cub->we, &read[2]);
	else if (read[0] == 'E' && read[1] == 'A' && read[2] == ' ')
		fill_path(&cub->ea, &read[2]);
	else if (read[0] == 'F' && read[1] == ' ')
		fill_rgb(&cub->floor, &read[1]);
	else if (read[0] == 'C' && read[1] == ' ')
		fill_rgb(&cub->ceiling, &read[1]);
	else
		return (1);
	return (0);
}
