/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 12:54:49 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/19 21:08:18 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_helper(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (map->map_lines[y])
	{
		x = 0;
		while (map->map_lines[y][x])
		{
			if (map->map_lines[y][x] == 'P')
				map->player_count++;
			else if (map->map_lines[y][x] == 'C')
				map->coin_count++;
			else if (map->map_lines[y][x] == 'E')
				map->end_count++;
			x++;
		}
		y++;
	}
	print_invalid(map);
}

static void	map_size_control(t_map *map)
{
	int	i;
	int	len;

	i = 0;
	len = map->w;
	while (map->map_lines[i])
	{
		if ((int)ft_strlen(map->map_lines[i]) != len)
			exit_with_error("Map Line Invalid Size", map);
		i++;
	}
}

static void	check_map_borders(t_map *map)
{
	int	i;
	int	last;

	i = -1;
	last = map->w - 1;
	while (map->map_lines[0][++i])
		if (map->map_lines[0][i] != '1' || map->map_lines[map->h - 1][i] != '1')
			exit_with_error("Map is not enclosed by walls", map);
	i = -1;
	while (map->map_lines[++i])
		if (map->map_lines[i][0] != '1' || map->map_lines[i][last] != '1')
			exit_with_error("Map is not enclosed by walls", map);
}

static int	check_valid_characters(const char *str)
{
	int	x;

	x = 0;
	while (str[x])
	{
		if (str[x] != 'C' && str[x] != 'P' && str[x] != 'E'
			&& str[x] != '0' && str[x] != '1' && str[x] != '\n')
			return (0);
		x++;
	}
	return (1);
}

void	validate_map(t_map *map)
{
	int	y;

	map_size_control(map);
	check_map_borders(map);
	y = 0;
	while (map->map_lines[y])
	{
		if (!check_valid_characters(map->map_lines[y]))
			exit_with_error("Invalid Character in Map", map);
		y++;
	}
}
