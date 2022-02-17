/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:06:32 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/01/25 15:01:17 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# include "../map/map.h"
# include <mlx.h>

//man /usr/share/man/man3/mlx.1

//Draw images
void		draw_image(t_data_map *data_map, int y, int x);
void		set_window(t_data_map *data_map);
t_window	*init_window(void);

//Start game
void		start_game(t_data_map *data_map);

//Events
int			key_hook(int key_code, t_data_map *data_map);
int			ft_red_cross(t_data_map *data_map);

//Free malloc
void		free_all(t_data_map *data_map);
void		check_movement_character(int x, int y, t_data_map *data_map);
int			check_coins(char **show_map);
void		delete_coin(t_data_map *data_map);
#endif