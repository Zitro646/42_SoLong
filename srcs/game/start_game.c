/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 09:21:24 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/02/17 15:11:24 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	get_array_height(char **array)
{
	int	i;

	i = 0;
	while (array[i] != 0)
		i++;
	return (i);
}

int	get_array_size(char **array)
{
	int	i;

	i = 0;
	while (array[0][i] != 0)
		i++;
	return (i);
}

void	start_game(t_data_map *data_map)
{
	int			x;
	int			y;
	t_window	*window;

	x = get_array_size(data_map->showmap);
	y = get_array_height(data_map->showmap);
	data_map->window = init_window();
	window = data_map->window;
	window->win_ptr = mlx_new_window(window->mlx_ptr, x * 32, y * 32, \
		"So_Long");
	set_window(data_map);
	mlx_hook(window->win_ptr, 17, 0, ft_red_cross, data_map);
	mlx_key_hook(window->win_ptr, key_hook, data_map);
	mlx_loop(window->mlx_ptr);
}
