/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:51:43 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/23 01:34:02 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	measure_map(t_map *map)
{
	int		i;

	if (!*(map->map_lines))
	{
		free_double(map->map_lines);
		free(map);
		ft_printf("Error: Invalid Map\n");
		return ;
	}
	map->w = (int)ft_strlen(map->map_lines[0]);
	i = 0;
	while (map->map_lines[i])
		i++;
	map->h = i;
}

static void	is_line_empty(char *temp, char *c)
{
	if (c[0] != '\n')
		return ;
	if (temp)
		free(temp);
	free(c);
	ft_printf("Error: Empty Line in map\n");
	return ;
}

static char	*read_lines(char *result, int fd)
{
	char	*line;
	char	*temp;

	line = NULL;
	temp = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		is_line_empty(temp, line);
		temp = ft_strjoin(result, line);
		free(line);
		free(result);
		if (!temp)
		{
			close(fd);
			ft_printf("Error: Memory allocation failed\n");
			return (NULL);
		}
		result = temp;
	}
	return (result);
}

static void	mapper(char *arg, t_map *map)
{
	char	*result;
	int		fd;

	fd = open(arg, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error: File could not be opened\n");
		return ;
	}
	result = ft_strdup("");
	if (!result)
	{
		close(fd);
		ft_printf("Error: Memory allocation failed\n");
		return ;
	}
	result = read_lines(result, fd);
	close(fd);
	if (!result)
		return ;
	map->map_lines = ft_split(result, '\n');
	free(result);
	measure_map(map);
}

t_map	*init_map(char *arg)
{
	t_map	*map;

	map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!map)
	{
		ft_printf("Error: Map Cannot Be Initialized\n");
		return (NULL);
	}
	mapper(arg, map); // map->map_lines
	validate_map(map); // 
	map_helper(map);
	return (map);
}
