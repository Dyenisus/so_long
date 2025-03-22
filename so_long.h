/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 20:40:56 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/23 01:12:38 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include "minilibx/mlx.h"
# include "libft/libft.h"
# include "libft/ft_printf.h"
# include "libft/get_next_line.h"

typedef struct s_size
{
	int	x;
	int	y;
}	t_size;

typedef struct s_play
{
	int		x;
	int		y;
	int		move;
	void	*front;
	void	*right;
	void	*left;
	void	*back;
	void	*current;
}	t_play;

typedef struct s_map
{
	char	**map_lines;
	int		h;
	int		w;
	int		gate_x;
	int		gate_y;
	int		player_count;
	int		coin_count;
	int		end_count;
}	t_map;

typedef struct s_win
{
	t_map	*map;
	t_play	*player;
	void	*win;
	void	*mlx;
	void	*ground;
	void	*wall;
	void	*coin;
	void	*end;
	int		height;
	int		weight;
}	t_win;

void	free_double(char **mapped);
void	xmp_check(void);
void	map_check(char *arg);
void	map_helper(t_map *map);
void	validate_map(t_map *map);
void	valid_path(t_win *window);
void	return_with_error(const char *msg, t_map *map);
void	print_invalid(t_map *map);
void	free_all(t_win *window);
t_map	*init_map(char *arg);
void	init_player(t_win *window);
void	destroy_player(t_win *window);
void	init_win(char *arg, t_win **window);
void	render_map(t_win *window);
void	print_win(void);
void	motion(t_win *window);

#endif