/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:23:30 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/22 23:53:08 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static	int	check_elements(const char **file_paths, int *fd)
{
	int	i;

	i = 4;
	while (i < 8)
	{
		fd[i] = open(file_paths[i], O_RDWR);
		if (fd[i] < 0)
		{
			ft_printf("Error Element Not Found: %s\n", file_paths[i]);
			while (i >= 4)
				close(fd[i--]);
			return (0);
		}
		i++;
	}
	while (--i >= 0)
		close(fd[i]);
	return (1);
}

static int	check_char(const char **file_paths, int *fd)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		fd[i] = open(file_paths[i], O_RDWR);
		if (fd[i] < 0)
		{
			ft_printf("Error: Character Not Found: %s\n", file_paths[i]);
			while (--i >= 0)
				close(fd[i]);
			return (0);
		}
		i++;
	}
	while (--i >= 0)
		close(fd[i]);
	return (1);
}

void	xmp_check(void)
{
	const char	*file_paths[8];
	int			fd[8];

	file_paths[0] = "./assets/front.xpm";
	file_paths[1] = "./assets/right.xpm";
	file_paths[2] = "./assets/left.xpm";
	file_paths[3] = "./assets/back.xpm";
	file_paths[4] = "./assets/chest.xpm";
	file_paths[5] = "./assets/gate.xpm";
	file_paths[6] = "./assets/ground.xpm";
	file_paths[7] = "./assets/wall.xpm";
	if (!check_char(file_paths, fd))
		exit(1);
	if (!check_elements(file_paths, fd))
		exit(1);
}

static	int	arg_check(char *arg)
{
	int	len;

	len = (int)ft_strlen(arg) - 4;
	if (ft_strncmp(arg + len, ".ber", 4) != 0)
	{
		ft_printf("Error: Wrong Map File Extention\n");
		return (0);
	}
	return (1);
}

void	map_check(char *arg)
{
	int	fd;

	if (!arg_check(arg))
		exit(1);
	fd = open(arg, O_RDWR);
	if (fd < 0)
	{
		close(fd);
		ft_printf("Error: Map File Can not be Opened\n");
		exit(1);
	}
	close(fd);
}
