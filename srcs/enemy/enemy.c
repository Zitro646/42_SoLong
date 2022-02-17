/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:48:58 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/01/25 15:06:51 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enemy.h"

int	check_objective(t_list *enemy)
{
	if (enemy->go_to_x == -1 && enemy->go_to_y == -1)
		return (-1);
	else if (enemy->go_to_x == enemy->x_axis && enemy->go_to_y == enemy->y_axis)
		return (-1);
	return (1);
}

void	move_enemy(t_data_map *data_map, int x, int y)
{
	t_list	**enemy;

	enemy = data_map->enemy;
	if (data_map->showmap[y][x] == '0')
	{
		data_map->showmap[y][x] = 'X';
		data_map->showmap[(*enemy)->y_axis][(*enemy)->x_axis] = '0';
		draw_image(data_map, y, x);
		draw_image(data_map, (*enemy)->y_axis, (*enemy)->x_axis);
		(*enemy)->x_axis = x;
		(*enemy)->y_axis = y;
	}
	else if (data_map->showmap[y][x] == 'P')
	{
		while ((*enemy)->prev != 0)
			(*enemy) = (*enemy)->prev;
		printf("Derrota");
		free_all(data_map);
		exit(0);
	}
	else
		new_objective(data_map, x, y);
}

void	enemy_action(t_data_map *data_map)
{
	t_list	**enemy;

	enemy = data_map->enemy;
	if ((*enemy)->go_to_x != (*enemy)->x_axis)
	{
		if ((*enemy)->go_to_x > (*enemy)->x_axis)
			move_enemy(data_map, (*enemy)->x_axis + 1, (*enemy)->y_axis);
		else
			move_enemy(data_map, (*enemy)->x_axis - 1, (*enemy)->y_axis);
	}
	else
	{
		if ((*enemy)->go_to_y > (*enemy)->y_axis)
			move_enemy(data_map, (*enemy)->x_axis, (*enemy)->y_axis + 1);
		else
			move_enemy(data_map, (*enemy)->x_axis, (*enemy)->y_axis - 1);
	}
}

void	enemy_patrol(t_data_map *data_map)
{
	t_list	**enemy;

	enemy = data_map->enemy;
	while ((*enemy) != 0)
	{
		if (check_objective(*enemy) == -1)
			new_objective(data_map, (*enemy)->x_axis, (*enemy)->y_axis);
		enemy_action(data_map);
		if ((*enemy)->next == 0)
		{
			while ((*enemy)->prev != 0)
				(*enemy) = (*enemy)->prev;
			break ;
		}
		(*enemy) = (*enemy)->next;
	}
}
