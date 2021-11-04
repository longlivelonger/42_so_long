/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:50:07 by sbronwyn          #+#    #+#             */
/*   Updated: 2021/10/25 19:14:13 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_allowed_chr(char c)
{
	if (c == '0' || c == '1' || c == 'C'
		|| c == 'E' || c == 'P' || c == '\n')
		return (1);
	return (0);
}

static void	find_map_size(t_map *map)
{
	int	i;
	int	start;

	start = 0;
	i = -1;
	while (map->str[++i] != '\0')
	{
		if (!is_allowed_chr(map->str[i]))
			exit(display_error("Invalid map character"));
		if (map->str[i] == '\n')
		{
			map->height++;
			if (map->width == 0 && i - start > 0)
				map->width = i - start;
			else if (map->width != 0 && map->width != i - start)
				exit(display_error("Invalid map width"));
			start = i + 1;
		}
	}
	if (map->width != -1 && map->width != i - start && i != start)
		exit(display_error("Invalid map width"));
	if (map->str[i - 1] != '\n')
		map->height++;
	if (map->width == 0 || map->height == 0)
		exit(display_error("Invalid map size"));
}

static void	check_map_requirements(t_map *map)
{
	int	i;

	if (count_char(map->str, 'E') != 1 || count_char(map->str, 'C') <= 0
		|| count_char(map->str, 'P') != 1)
		exit(display_error("Map dont have at least one E, C and P"));
	i = -1;
	while (++i < map->width)
		if (map->str[i] != '1'
			|| map->str[(map->height - 1) * (map->width + 1) + i] != '1')
			exit(display_error("Map dont have walls"));
	i = -1;
	while (++i < map->height)
		if (map->str[(map->width + 1) * i] != '1'
			|| map->str[(map->width + 1) * i + map->width - 1] != '1')
			exit(display_error("Map dont have walls"));
}

t_map	*load_map(char *path)
{
	int		fd;
	char	buf;
	t_map	*map;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit(display_error(0));
	map = malloc(sizeof(*map));
	if (map == 0)
		exit(display_error(0));
	map->str = 0;
	map->width = 0;
	map->height = 0;
	while (read(fd, &buf, 1))
		map->str = append_char(map->str, buf);
	close(fd);
	if (ft_strlen(map->str) == 0)
		exit(display_error("Empty map"));
	find_map_size(map);
	check_map_requirements(map);
	return (map);
}

int	find_player(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
		if (str[i] == 'P')
			return (i);
	return (-1);
}
