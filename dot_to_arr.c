/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_to_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echeung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 16:10:50 by echeung           #+#    #+#             */
/*   Updated: 2020/02/17 18:12:33 by echeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*cmp_shape(char *tmp)
{
	char	*coor_str;

	coor_str = NULL;
	(!(ft_strcmp(tmp, SHAPE_1))) && (coor_str = "00010203");
	(!(ft_strcmp(tmp, SHAPE_2))) && (coor_str = "00103020");
	(!(ft_strcmp(tmp, SHAPE_3))) && (coor_str = "00011011");
	(!(ft_strcmp(tmp, SHAPE_4))) && (coor_str = "00011202");
	(!(ft_strcmp(tmp, SHAPE_5))) && (coor_str = "00101112");
	(!(ft_strcmp(tmp, SHAPE_6))) && (coor_str = "00102001");
	(!(ft_strcmp(tmp, SHAPE_7))) && (coor_str = "01112021");
	(!(ft_strcmp(tmp, SHAPE_8))) && (coor_str = "00011002");
	(!(ft_strcmp(tmp, SHAPE_9))) && (coor_str = "02101112");
	(!(ft_strcmp(tmp, SHAPE_10))) && (coor_str = "00012111");
	(!(ft_strcmp(tmp, SHAPE_11))) && (coor_str = "00102021");
	(!(ft_strcmp(tmp, SHAPE_12))) && (coor_str = "00011112");
	(!(ft_strcmp(tmp, SHAPE_13))) && (coor_str = "10012011");
	(!(ft_strcmp(tmp, SHAPE_14))) && (coor_str = "10011102");
	(!(ft_strcmp(tmp, SHAPE_15))) && (coor_str = "00102111");
	(!(ft_strcmp(tmp, SHAPE_16))) && (coor_str = "10012111");
	(!(ft_strcmp(tmp, SHAPE_17))) && (coor_str = "10011112");
	(!(ft_strcmp(tmp, SHAPE_18))) && (coor_str = "00011102");
	(!(ft_strcmp(tmp, SHAPE_19))) && (coor_str = "00102011");
	free(tmp);
	return (coor_str);
}

char	*get_shape(char *buff)
{
	int		start;
	int		end;
	int		len;
	int		j;
	char	*tmp;

	start = 0;
	end = ft_strlen(buff) - 1;
	j = 0;
	while (buff[start] == '.')
		start++;
	while (buff[end] == '.')
		end--;
	len = end - start + 1;
	if (!(tmp = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (len > 0)
	{
		tmp[j] = buff[start];
		j++;
		start++;
		len--;
	}
	tmp[j] = '\0';
	return (tmp);
}
