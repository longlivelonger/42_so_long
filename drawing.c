/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:54:35 by sbronwyn          #+#    #+#             */
/*   Updated: 2021/11/04 17:11:14 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*get_image_by_char(char c, t_assets *assets)
{
	static t_assets	*assets_local = 0;

	if (assets != 0)
		assets_local = assets;
	if (c == '0')
		return (assets_local->floor);
	else if (c == '1')
		return (assets_local->wall);
	else if (c == 'E')
		return (assets_local->exit);
	else if (c == 'P')
		return (assets_local->player);
	else if (c == 'C')
		return (assets_local->coins);
	return (0);
}

static int	moves_count(int add)
{
	static int	count = -1;

	count += add;
	return (count);
}

static void	draw_counter(void *mlx_ptr, void *mlx_win, int num)
{
	int		y;
	int		x;
	char	*num_str;
	char	*final_str;

	num_str = ft_itoa(num);
	if (num_str == 0)
		return ;
	final_str = ft_strjoin("Moves: ", num_str);
	if (final_str == 0)
	{
		free(num_str);
		return ;
	}
	y = -1;
	while (++y < 20)
	{
		x = -1;
		while (++x < 85)
			mlx_pixel_put(mlx_ptr, mlx_win, x, y, 5999942);
	}
	mlx_string_put(mlx_ptr, mlx_win, 10, 15, 0, final_str);
	free(num_str);
	free(final_str);
}

void	draw_window(void *mlx_ptr, void *mlx_win, t_assets *assets, t_map *map)
{
	static void	*mlx_ptr_local = 0;
	static void	*mlx_win_local = 0;
	int			i;
	void		*image;

	if (mlx_ptr != 0)
		mlx_ptr_local = mlx_ptr;
	if (mlx_win != 0)
		mlx_win_local = mlx_win;
	mlx_clear_window(mlx_ptr_local, mlx_win_local);
	i = -1;
	while (map->str[++i] != '\0')
	{
		mlx_put_image_to_window(mlx_ptr_local, mlx_win_local,
			get_image_by_char('0', assets),
			32 * (i % (map->width + 1)), 32 * (i / (map->width + 1)));
		image = get_image_by_char(map->str[i], assets);
		if (image != 0)
			mlx_put_image_to_window(mlx_ptr_local, mlx_win_local, image,
				32 * (i % (map->width + 1)), 32 * (i / (map->width + 1)));
	}
	draw_counter(mlx_ptr_local, mlx_win_local, moves_count(1));
}
