/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:06:49 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/26 14:40:29 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	count_strs(const char **str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	**ft_strdup_2d(const char **str)
{
	char	**ptr;
	int		str_count;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	str_count = count_strs(str);
	ptr = (char **)ft_calloc((str_count + 1), sizeof(char *));
	if (!ptr)
		return (NULL);
	while (str[i])
	{
		ptr[i] = ft_strdup(str[i]);
		if (ptr[i] == NULL)
		{
			free_double(ptr);
			return (NULL);
		}
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}

static void	flood_fill(char **map, t_flood size, t_flood begin)
{
	if (map[begin.y][begin.x] == 'E')
	{
		map[begin.y][begin.x] = 'F';
		return ;
	}
	if (begin.y < 0 || begin.y >= size.y
		|| begin.x < 0 || begin.x >= size.x
		|| map[begin.y][begin.x] == '1'
		|| map[begin.y][begin.x] == 'F')
		return ;
	map[begin.y][begin.x] = 'F';
	flood_fill(map, size, (t_flood){begin.x - 1, begin.y});
	flood_fill(map, size, (t_flood){begin.x + 1, begin.y});
	flood_fill(map, size, (t_flood){begin.x, begin.y - 1});
	flood_fill(map, size, (t_flood){begin.x, begin.y + 1});
}

static void	is_accessable(t_win *window, char **map)
{
	int	i[2];

	i[0] = -1;
	while (map[++i[0]])
	{
		i[1] = -1;
		while (map[i[0]][++i[1]])
		{
			if (!(map[i[0]][i[1]] == 'F' || map[i[0]][i[1]] == '1'
				|| map[i[0]][i[1]] == '0'
				|| map[i[0]][i[1]] == '\n'))
			{
				free_double(map);
				exit_with_error_win("Map is not accessable", window);
			}
		}
	}
	free_double(map);
}

void	valid_path(t_win *window)
{
	char	**map;
	t_flood	size;
	t_flood	begin;

	map = ft_strdup_2d((const char **)window->map->map_lines);
	if (!map)
		exit_with_error_win("Valid path cannot be allocated", window);
	size.x = window->map->w;
	size.y = window->map->h;
	begin.x = window->player->x;
	begin.y = window->player->y;
	flood_fill(map, size, begin);
	is_accessable(window, map);
}
