/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 11:54:15 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/01/24 12:01:29 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	key_hook(int key_code, t_data_map *data_map)
{
	if (key_code == 0)
		check_movement_character(-1, 0, data_map);
	if (key_code == 13)
		check_movement_character(0, -1, data_map);
	if (key_code == 2)
		check_movement_character(1, 0, data_map);
	if (key_code == 1)
		check_movement_character(0, 1, data_map);
	if (key_code == 53)
	{
		free_all(data_map);
		exit (0);
	}
	return (0);
}

int	ft_red_cross(t_data_map *data_map)
{
	free_all(data_map);
	exit (0);
	return (0);
}
