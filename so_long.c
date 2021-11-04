/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 13:55:44 by sbronwyn          #+#    #+#             */
/*   Updated: 2021/11/04 15:52:54 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	key_hook(int key, t_map *map)
{
	if (key == 0 && move_left(map))
		draw_window(0, 0, 0, map);
	else if (key == 2 && move_right(map))
		draw_window(0, 0, 0, map);
	else if (key == 13 && move_up(map))
		draw_window(0, 0, 0, map);
	else if (key == 1 && move_down(map))
		draw_window(0, 0, 0, map);
	else if (key == 53)
		exit(0);
	return (1);
}

static int	on_close_hook(void *params)
{
	(void)params;
	exit(0);
}

int	main(int argc, char **argv)
{
	void		*mlx_ptr;
	void		*mlx_win;
	t_assets	*assets;
	t_map		*map;

	if (argc != 2)
		exit(display_error("Incorrect argument number"));
	mlx_ptr = mlx_init();
	assets = load_assets(mlx_ptr);
	map = load_map(argv[1]);
	mlx_win = mlx_new_window(mlx_ptr, 32 * map->width,
			32 * map->height, "Dungeon Coins");
	draw_window(mlx_ptr, mlx_win, assets, map);
	mlx_key_hook(mlx_win, &key_hook, map);
	mlx_hook(mlx_win, 17, (1L << 17), on_close_hook, 0);
	mlx_loop(mlx_ptr);
	return (0);
}
