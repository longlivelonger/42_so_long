/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:59:11 by sbronwyn          #+#    #+#             */
/*   Updated: 2021/10/25 18:47:19 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(const char *s)
{
	int	size;

	size = 0;
	while (s[size] != 0)
		size++;
	return (size);
}

int	count_char(const char *s, int c)
{
	int	i;
	int	count;

	count = 0;
	i = -1;
	while (s[++i] != '\0')
		if (s[i] == c)
			count++;
	return (count);
}

int	display_error(char *msg)
{
	write(2, "Error\n", 6);
	if (msg == 0)
		perror(0);
	else
	{
		write(2, msg, ft_strlen(msg));
		write(2, "\n", 1);
	}
	return (1);
}

t_assets	*load_assets(void *mlx_ptr)
{
	t_assets	*assets;
	int			img_size;

	assets = malloc(sizeof(*assets));
	if (assets == 0)
		exit(display_error(0));
	assets->floor = mlx_xpm_file_to_image(mlx_ptr, "assets/floor.xpm",
			&img_size, &img_size);
	assets->exit = mlx_xpm_file_to_image(mlx_ptr, "assets/exit.xpm",
			&img_size, &img_size);
	assets->wall = mlx_xpm_file_to_image(mlx_ptr, "assets/wall.xpm",
			&img_size, &img_size);
	assets->coins = mlx_xpm_file_to_image(mlx_ptr, "assets/coins.xpm",
			&img_size, &img_size);
	assets->player = mlx_xpm_file_to_image(mlx_ptr, "assets/player.xpm",
			&img_size, &img_size);
	return (assets);
}

char	*append_char(char *str, char c)
{
	int		len;
	char	*res;
	int		i;

	if (str == 0)
		len = 1;
	else
		len = ft_strlen(str) + 1;
	res = malloc((len + 1) * sizeof(*res));
	if (res == 0)
		exit(display_error(0));
	res[len] = '\0';
	i = -1;
	while (++i < len - 1)
		res[i] = str[i];
	res[i] = c;
	if (str != 0)
		free(str);
	return (res);
}
