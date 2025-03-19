/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:51:43 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/19 21:05:58 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
		temp = ft_strjoin(result, line);
		free(line);
		free(result);
		if (!temp)
		{
			close(fd);
			ft_printf("Error: Memory allocation failed\n");
			exit(1);
		}
		result = temp;
	}
	return (result);
}

static void	mapper(char *arg, t_map *map)
{
	char	*result;
	int		fd;
	int		i;

	fd = open(arg, O_RDONLY);
	result = ft_strdup("");
	if (!result)
	{
		close(fd);
		ft_printf("Error: Memory allocation failed\n");
		exit(1);
	}
	result = read_lines(result, fd);
	close(fd);
	map->map_lines = ft_split(result, '\n');
	free(result);
	map->w = (int)ft_strlen(map->map_lines[0]);
	i = 0;
	while (map->map_lines[i])
		i++;
	map->h = i;
}

t_map	*init_map(char *arg)
{
	t_map	*map;

	map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!map)
	{
		ft_printf("Error: Map Cannot Be Initialized\n");
		exit(1);
	}
	mapper(arg, map);
	validate_map(map);
	map_helper(map);
	while (map->map_lines[map->h])
		map->h++;
	map->w = ft_strlen(map->map_lines[0]);
	return (map);
}
