/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:00:32 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/26 19:31:43 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include "minilibx" // include according to OS
# include "libft/libft.h"
# include "libft/ft_printf.h"
# include "libft/get_next_line.h"

typedef struct s_flood
{
	int	x;
	int	y;
}	t_flood;

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

// check
void	xmp_check(void);
void	map_check(char *arg);

// free
void	free_double(char **mapped);
void	free_map(t_map *map);
void	free_all(t_win *window);

// exit
void	free_exit_map(t_map *map);
void	free_exit_player(t_play *player);
void	free_exit_player_map(t_map *map, t_play *player);
void	free_exit_win(t_win *window);

// print
void	print_win(void);

// message
void	exit_with_error_map(const char *msg, t_map *map);
void	exit_with_error_player(const char *msg, t_play *player);
void	exit_with_error_player_map(const char *msg, t_map *map, t_play *player);
void	exit_with_error_win(const char *msg, t_win *window);

// map_helper
void	map_helper(t_map *map);
void	validate_map(t_map *map);

// map
t_map	*init_map(char *arg);

// flood fill
void	valid_path(t_win *window);

// textures
void	get_player_image(t_win *window);
void	get_map_image(t_win *window);

// player
t_play	*init_player(t_map *map);

// render
void	render_map(t_win *window);

// window
t_win	*init_window(t_map *map, t_play *player);

// move
void	motion(t_win *window);

#endif