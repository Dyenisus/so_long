/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:08:01 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/26 14:27:33 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	measure_map(t_map *map)
{
	int		i;

	map->w = (int)ft_strlen(map->map_lines[0]);
	i = 0;
	while (map->map_lines[i])
		i++;
	map->h = i;
}

static void	shut_chr_down(t_map *map, char *temp, int fd, char *msg)
{
	close(fd);
	if (temp)
		free(temp);
	exit_with_error_map(msg, map);
}

static char	*read_lines(char *result, int fd, t_map *map)
{
	char	*line;
	char	*temp;
	int		is_empty_line;

	is_empty_line = 0;
	line = NULL;
	temp = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] == '\n')
			is_empty_line = 1;
		temp = ft_strjoin(result, line);
		free(line);
		free(result);
		if (is_empty_line == 1)
			shut_chr_down(map, temp, fd, "Empty line in map");
		if (!temp)
			shut_chr_down(map, temp, fd, "Temp Memory allocation failed");
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
		exit_with_error_map("File could not be opened", map);
	result = ft_strdup("");
	if (!result)
	{
		close(fd);
		exit_with_error_map("Memory allocation failed", map);
	}
	result = read_lines(result, fd, map);
	close(fd);
	if (!result)
		exit_with_error_map("Lines could not be read", map);
	map->map_lines = ft_split(result, '\n');
	free(result);
	if (!map->map_lines)
		exit_with_error_map("Lines could not be splitted", map);
	if (!*(map->map_lines))
		exit_with_error_map("Empty Map", map);
	measure_map(map);
}

t_map	*init_map(char *arg)
{
	t_map	*map;

	map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!map)
		exit_with_error_map("Map Cannot Be Initialized", NULL);
	mapper(arg, map);
	validate_map(map);
	map_helper(map);
	return (map);
}
