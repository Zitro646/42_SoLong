/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 09:11:14 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/02/14 15:14:44 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_list(int *list)
{
	int	i;

	i = 0;
	if (list != 0)
	{
		while (list[i] != '\0')
			i++;
	}
	return (i);
}
