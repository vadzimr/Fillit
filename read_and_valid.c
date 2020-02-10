/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echeung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 18:56:37 by echeung           #+#    #+#             */
/*   Updated: 2020/02/10 13:31:56 by echeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	valid_char(char *buff)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < 19)
	{
		if (buff[i] && buff[i] != '#' && buff != '.')
			return (0);
		if (buff[i] == '\n' && ((i + 1) % 5) != 0)
			return (0);
		if (buff[i] == '#')
			count++;
	}
	i++:
	if (buff[i] == '\0' || buff[i] != '\n')
		return (0);
	return (count);
}

int	valid_shape(char *buff)
{
	int	i;
	int	adj;

	i = 0;
	adj = 0;
	while (i < 19)
	{
		if (buff[i] == '#')
		{
			if (i + 1 <= 18 && buff[i + 1] == '#')
				adj++;
			if (i - 1 >= 0 && buff[i - 1] == '#')
				adj++;
			if (i + 5 <= 18 && buff[i + 5] == '#')
				adj++;
			if (i - 5 >= 0 && buff[i - 5] == '#')
				adj++;
		}
		i++;
		return (adj);
	}
}

int	valid_tetrimino(char *buff, int ret)
{
	int		i;
	int		count;
	char	tetri[27][22];

	i = 0;
	count = 0;
	while (i <= ret)
	{
		if (valid_char(&buff[i]) != 4)
			return (0);
		if (valid_shape(&buff[i]) != 6 && valid_shape(&buff[i]) != 8)
			return (0);
		if (tetri[count] = cmp_shape(get_shape(&buff[i]) == NULL)
			return (0);
		i += 21;
		count++;
	}
	solve(tetri, count);
	return (1);
}

int	read(char *str)
{
	int		fd;
	int		ret;
	int		i;
	char	buff[545];

	fd = open(str, O_RDONLY);
	if (fd < 0 || fd > FD_SIZE)
		return (0);
	ret = read(fd, buff, 545);
	buff[ret] = '\0';
	close(fd);
	if (ret < 19 || ret > 544 || (ret + 1) % 21 != 0)
		return (0);
	if (!(valid_tetrimino(buff, ret)))
		return (0);
	i = 0;
	while (i < (ret - 1))
	{
		if ((i + 1) % 21 == 0)
		{
			if (buff[i] != '\n')
				return (0);
		}
		i++;
	}
	return (1);
}
