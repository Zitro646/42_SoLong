/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_mechanics.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:01:46 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/01/25 14:09:07 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	move_on_object(int x, int y, t_data_map *data_map)
{
	t_list	**player;

	player = data_map->player;
	if (data_map->showmap[y][x] == 'C')
	{
		data_map->showmap[y][x] = 'P';
		data_map->showmap[(*player)->y_axis][(*player)->x_axis] = '0';
		draw_image(data_map, y, x);
		draw_image(data_map, (*player)->y_axis, (*player)->x_axis);
		(*player)->x_axis = x;
		(*player)->y_axis = y;
		data_map->counter_moves++;
	}
	else if (data_map->showmap[y][x] == 'E')
	{
		if (check_coins(data_map->showmap) == 0)
		{
			free_all(data_map);
			printf("Victoria\n");
			exit (0);
		}
	}
}

static void	move_character(int x, int y, t_data_map *data_map)
{
	t_list	**player;

	player = data_map->player;
	data_map->showmap[y][x] = 'P';
	data_map->showmap[(*player)->y_axis][(*player)->x_axis] = '0';
	draw_image(data_map, y, x);
	draw_image(data_map, (*player)->y_axis, (*player)->x_axis);
	(*player)->x_axis = x;
	(*player)->y_axis = y;
	data_map->counter_moves++;
}

static void	print_counter(t_data_map *data_map)
{
	char	*aux;

	draw_image(data_map, 0, 0);
	draw_image(data_map, 0, 1);
	draw_image(data_map, 0, 2);
	mlx_string_put(data_map->window->mlx_ptr, data_map->window->win_ptr, \
		0, 0, 0, "->");
	aux = ft_itoa(data_map->counter_moves);
	mlx_string_put(data_map->window->mlx_ptr, data_map->window->win_ptr, \
		32, 0, 0, aux);
	free(aux);
}

void	check_movement_character(int x, int y, t_data_map *data_map)
{
	t_list	**player;
	int		ply_new_x;
	int		ply_new_y;

	player = data_map->player;
	if ((*player) != 0)
	{
		ply_new_x = ((*player)->x_axis + x);
		ply_new_y = ((*player)->y_axis + y);
		if (data_map->showmap[ply_new_y][ply_new_x] == 'C')
			move_on_object(ply_new_x, ply_new_y, data_map);
		else if (data_map->showmap[ply_new_y][ply_new_x] == 'E')
			move_on_object(ply_new_x, ply_new_y, data_map);
		else if (data_map->showmap[ply_new_y][ply_new_x] == '0')
			move_character(ply_new_x, ply_new_y, data_map);
		else if (data_map->showmap[ply_new_y][ply_new_x] == 'X')
		{
			free_all(data_map);
			printf("Derrota\n");
			exit (0);
		}
		printf("Total de movimientos: %i\n", data_map->counter_moves);
		print_counter(data_map);
		enemy_patrol(data_map);
	}
}
