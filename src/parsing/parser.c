/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:23:08 by ysonmez           #+#    #+#             */
/*   Updated: 2022/04/08 12:28:03 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*   Updated: 2022/02/26 18:35:27 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/*	Initialize the data and the pointers
*	NO/SO/WE/EA Identifiers
*	F[0-1-2] Floor RGB Colours
*	C[0-1-2] Ceiling RGB Colours
*
*/

void	init_data(t_cub *cub)
{
	cub->no = NULL;
	cub->so = NULL;
	cub->we = NULL;
	cub->ea = NULL;
	cub->floor = -1;
	cub->ceiling = -1;
	cub->i = 0;
	cub->map = NULL;
	cub->id_done = false;
	cub->map_done = false;
	cub->map_data = NULL;
}

/*	Create the data struct
*	Read the file
*	Verify the content
*	Store the data
*	Builds the char map used later
*/

t_cub	*get_data(int fd, char *read, t_cub *cub)
{
	cub = (t_cub *)xmalloc(sizeof(t_cub));
	init_data(cub);
	get_next_line(fd, &read);
	while (read != NULL)
	{
		if (ft_strcmp(read, "\0") == 0)
		{
			if (cub->map != NULL && ft_memfree((void *)read))
				break ;
		}
		else if (cub->id_done == false && identifier(cub, read))
			exit(EXIT_FAILURE);
		else if (cub->id_done == true && map(cub, NULL, read, 0))
			exit(EXIT_FAILURE);
		identifier_done(cub);
		free(read);
		get_next_line(fd, &read);
	}
	cub->map_done = is_map_valid(cub, false, 0);
	build_2d_charmap(cub);
	if ((cub->id_done == false || cub->map_done == false) && clear_data(cub))
		return (NULL);
	return (cub);
}

/*	This function is the main parsing function, it will
*		Check if the content of the file respect the rules
*		Store the data
*/

t_cub	*check_file_content(char *file)
{
	int		fd;
	t_cub	*cub;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putendl_fd("Corrupted file (open)", 2);
		return (NULL);
	}
	cub = get_data(fd, NULL, NULL);
	if (cub == NULL)
		ft_putendl_fd("Error\nmisconfiguration", 2);
	if (close(fd) == -1)
	{
		ft_putendl_fd("Corrupted file (close)", 2);
		clear_data(cub);
		return (NULL);
	}
	return (cub);
}

/**
**	Check if the filename has
**	a valid extension (.cub)
**	If not, it returns 0.
*/
int	check_file_format(char *file_name)
{
	int			len;
	const char	*start;

	len = ft_strlen(file_name);
	if (len <= 4)
		return (1);
	start = (const char *) &file_name[(len - 4)];
	if (ft_strncmp(start, ".cub", 4) == 0)
		return (0);
	return (1);
}
