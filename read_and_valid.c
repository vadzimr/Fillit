/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echeung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 18:56:37 by echeung           #+#    #+#             */
/*   Updated: 2020/02/17 21:48:44 by echeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		valid_char(char *buff)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < 19)
	{
		if (buff[i] && buff[i] != '#' && buff[i] != '.' && buff[i] != '\n')
			return (0);
		if (buff[i] == '\n' && ((i + 1) % 5) != 0)
			return (0);
		if (buff[i] == '#')
			count++;
		i++;
	}
	if (buff[i] == '\0' || buff[i] != '\n')
		return (0);
	return (count);
}

int		valid_shape(char *buff)
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
	}
	return (adj);
}

char	*make_string(char *buff)
{
	int		j;
	int		k;
	char	str[20];
	char	*tmp;

	j = 0;
	k = 0;
	while (j < 19)
	{
		if (buff[j] == '.' || buff[j] == '#')
		{
			str[k] = buff[j];
			k++;
		}
		j++;
	}
	str[k] = '\0';
	tmp = cmp_shape(get_shape(str));
	return (tmp);
}

int		valid_tetrimino(char *buff, int ret)
{
	int		i;
	int		j;
	char	tetri[27][27];

	i = 0;
	j = 0;
	while (i <= ret)
	{
		if (valid_char(&buff[i]) != 4)
			return (0);
		if (valid_shape(&buff[i]) != 6 && valid_shape(&buff[i]) != 8)
			return (0);
		if ((ft_strcpy(tetri[j], make_string(&buff[i]))) == NULL)
			return (0);
		i += 21;
		j++;
	}
	ft_strcpy(tetri[j], "NULL");
	solve(tetri, j);
	return (1);
}

int		read_file(char *str)
{
	int		fd;
	int		ret;
	int		i;
	char	buff[545];

	fd = open(str, O_RDONLY);
	if (fd < 0 || fd > 1025)
		return (0);
	ret = read(fd, buff, 545);
	buff[ret] = '\0';
	close(fd);
	if (ret < 19 || ret > 544 || (ret + 1) % 21 != 0)
		return (0);
	if (!valid_tetrimino(buff, ret))
		return (0);
	i = 0;
	while (i++ < (ret - 1))
	{
		if ((i + 1) % 21 == 0)
		{
			if (buff[i] != '\n')
				return (0);
		}
	}
	return (1);
}
