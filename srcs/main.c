/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 10:38:08 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/02/17 13:50:24 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/game.h"

int	main(int argc, char **argv)
{
	t_data_map	*map;
	int			check;
	char		*dir;

	if (argc >= 2)
		dir = ft_strjoin("./srcs/assets/", argv[1]);
	else
	{
		printf("Error no data inserted\n");
		return (0);
	}
	map = mapreader(dir);
	free(dir);
	check = mapcheck(map);
	if (check == 1)
		start_game(map);
	else
	{
		if (check == -1)
			free(map);
		else
			free_all(map);
	}
	return (0);
}
