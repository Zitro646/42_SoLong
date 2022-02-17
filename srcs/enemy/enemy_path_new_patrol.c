/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_path_new_patrol.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:51:58 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/01/25 14:54:02 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enemy.h"

int	check_sorroundings_y(char **show_map, int x, int y)
{
	int	pos;
	int	neg;

	pos = 0;
	neg = 0;
	while (show_map[y - neg - 1][x] == '0' || show_map[y - neg - 1][x] == 'P')
		neg++;
	while (show_map[y + pos + 1][x] == '0' || show_map[y + pos + 1][x] == 'P')
		pos++;
	if (pos > neg)
		return (pos - 1);
	else if (neg > pos)
		return (neg - 1);
	else if (neg != 1)
		return (neg - 1);
	else
		return (0);
}

int	get_new_y(char **show_map, int x, int y)
{
	int	pos;
	int	neg;

	pos = 0;
	neg = 0;
	while (show_map[y - neg - 1][x] == '0' || show_map[y - neg - 1][x] == 'P')
		neg++;
	while (show_map[y + pos + 1][x] == '0' || show_map[y + pos + 1][x] == 'P')
		pos++;
	if (pos > neg)
		return (y + pos);
	else
		return (y + (neg * -1));
}

int	check_sorroundings_x(char **show_map, int x, int y)
{
	int	pos;
	int	neg;

	pos = 0;
	neg = 0;
	while (show_map[y][x - neg - 1] == '0' || show_map[y][x - neg - 1] == 'P')
		neg++;
	while (show_map[y][x + pos + 1] == '0' || show_map[y][x + pos + 1] == 'P')
		pos++;
	if (pos > neg)
		return (pos);
	else if (neg > pos)
		return (neg);
	else if (neg != 1)
		return (neg);
	else
		return (0);
}

int	get_new_x(char **show_map, int x, int y)
{
	int	pos;
	int	neg;

	pos = 1;
	neg = 1;
	while (show_map[y][x - neg - 1] == '0' || show_map[y][x - neg - 1] == 'P')
		neg++;
	while (show_map[y][x + pos + 1] == '0' || show_map[y][x + pos + 1] == 'P')
		pos++;
	if (pos > neg)
		return (x + pos);
	else
		return (x + (neg * -1));
}

void	new_objective(t_data_map *data_map, int enemy_x, int enemy_y)
{
	t_list	**enemy;
	int		ppx;
	int		ppy;

	enemy = data_map->enemy;
	ppy = check_sorroundings_y(data_map->showmap, enemy_x, enemy_y);
	ppx = check_sorroundings_x(data_map->showmap, enemy_x, enemy_y);
	if (ppx > ppy)
	{
		(*enemy)->go_to_x = get_new_x(data_map->showmap, enemy_x, enemy_y);
	}
	else
	{
		(*enemy)->go_to_y = get_new_y(data_map->showmap, enemy_x, enemy_y);
	}
}
