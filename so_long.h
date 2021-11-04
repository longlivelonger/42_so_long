/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:49:14 by sbronwyn          #+#    #+#             */
/*   Updated: 2021/10/26 13:53:30 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "mlx.h"

typedef struct s_assets
{
	void	*floor;
	void	*exit;
	void	*wall;
	void	*coins;
	void	*player;
}	t_assets;

typedef struct s_map
{
	char	*str;
	int		width;
	int		height;
}	t_map;

size_t		ft_strlen(const char *s);
int			count_char(const char *s, int c);
int			display_error(char *msg);
t_assets	*load_assets(void *mlx_ptr);
char		*append_char(char *str, char c);

t_map		*load_map(char *path);
int			find_player(char *str);

void		draw_window(void *mlx_ptr, void *mlx_win,
				t_assets *assets, t_map *map);

int			collectibles_count(int add);
int			move_left(t_map *map);
int			move_right(t_map *map);
int			move_up(t_map *map);
int			move_down(t_map *map);

#endif