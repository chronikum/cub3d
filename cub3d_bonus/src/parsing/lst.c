/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 10:33:09 by ysonmez           #+#    #+#             */
/*   Updated: 2022/03/17 10:33:52 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/*	Create a new node of t_list type */

t_map	*ft_lstnew(void)
{
	t_map	*lstnew;

	lstnew = (t_map *)xmalloc(sizeof(t_map));
	lstnew->next = NULL;
	return (lstnew);
}

/*	Add a node to a t_list list */

void	ft_lstadd_back(t_map **lst, t_map *new)
{
	t_map	*tmp;

	tmp = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

/*	Create a new node of t_map_data type with content string */

t_map_data	*ft_data_new_data(char *string)
{
	t_map_data	*lstnew;

	lstnew = (t_map_data *)xmalloc(sizeof(t_map_data));
	lstnew->next = NULL;
	lstnew->data = string;
	return (lstnew);
}

/*	Add a node to a t_map_data list */

void	ft_data_append_data(t_map_data **lst, t_map_data *new)
{
	t_map_data	*tmp;

	tmp = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

/*	Counts the amount of map lines */

int	ft_lst_data_count(t_map_data *head)
{
	t_map_data	*tmp;
	int			count;

	if (!head)
		return (-1);
	tmp = head;
	count = 0;
	while (tmp->next)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}
