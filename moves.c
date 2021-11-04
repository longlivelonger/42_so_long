/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:25:17 by sbronwyn          #+#    #+#             */
/*   Updated: 2021/10/25 19:20:35 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	collectibles_count(int add)
{
	static int	count = 0;

	count += add;
	return (count);
}

int	move_left(t_map *map)
{
	int	player;

	player = find_player(map->str);
	if (map->str[player - 1] == 'E' && count_char(map->str, 'C') == 0)
		exit(0);
	if (map->str[player - 1] == '0' || map->str[player - 1] == 'C')
	{
		if (map->str[player - 1] == 'C')
			collectibles_count(1);
		map->str[player - 1] = 'P';
		map->str[player] = '0';
		draw_window(0, 0, 0, map);
	}
	return (0);
}

int	move_right(t_map *map)
{
	int	player;

	player = find_player(map->str);
	if (map->str[player + 1] == 'E' && count_char(map->str, 'C') == 0)
		exit(0);
	if (map->str[player + 1] == '0' || map->str[player + 1] == 'C')
	{
		if (map->str[player + 1] == 'C')
			collectibles_count(1);
		map->str[player + 1] = 'P';
		map->str[player] = '0';
		draw_window(0, 0, 0, map);
	}
	return (0);
}

int	move_up(t_map *map)
{
	int	player;
	int	next_pos;

	player = find_player(map->str);
	next_pos = player - map->width - 1;
	if (map->str[next_pos] == 'E' && count_char(map->str, 'C') == 0)
		exit(0);
	if (map->str[next_pos] == '0' || map->str[next_pos] == 'C')
	{
		if (map->str[next_pos] == 'C')
			collectibles_count(1);
		map->str[next_pos] = 'P';
		map->str[player] = '0';
		draw_window(0, 0, 0, map);
	}
	return (0);
}

int	move_down(t_map *map)
{
	int	player;
	int	next_pos;

	player = find_player(map->str);
	next_pos = player + map->width + 1;
	if (map->str[next_pos] == 'E' && count_char(map->str, 'C') == 0)
		exit(0);
	if (map->str[next_pos] == '0' || map->str[next_pos] == 'C')
	{
		if (map->str[next_pos] == 'C')
			collectibles_count(1);
		map->str[next_pos] = 'P';
		map->str[player] = '0';
		draw_window(0, 0, 0, map);
	}
	return (0);
}
