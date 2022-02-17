/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 08:39:43 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/01/25 15:01:25 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	free_window(t_data_map *data_map)
{
	if (data_map->window != 0)
	{
		mlx_destroy_window(data_map->window->mlx_ptr, \
			data_map->window->win_ptr);
		free(data_map->window);
	}
}

void	free_all(t_data_map *data_map)
{
	int	i;

	i = 0;
	while (data_map->showmap[i] != '\0')
	{
		free(data_map->showmap[i]);
		free(data_map->background_map[i]);
		i++;
	}
	free(data_map->showmap);
	free(data_map->background_map);
	ft_lstclear(data_map->player);
	free(data_map->player);
	free_window(data_map);
	ft_lstclear(data_map->enemy);
	free(data_map->enemy);
	free(data_map);
}
