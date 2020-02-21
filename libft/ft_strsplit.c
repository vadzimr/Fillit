/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echeung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 18:28:32 by echeung           #+#    #+#             */
/*   Updated: 2019/12/13 19:11:46 by echeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_arrlen(char const *s, char c)
{
	int	count;

	count = 0;
	if (*s && *s != c)
	{
		count++;
		s++;
	}
	while (*s)
	{
		while (*s == c)
		{
			s++;
			if (*s != c && *s)
				count++;
		}
		s++;
	}
	return (count);
}

static int	ft_word(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**d;

	j = 0;
	i = 0;
	if (!s || !(d = (char **)malloc(sizeof(char *) * (ft_arrlen(s, c) + 1))))
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			if (!(d[i] = (char *)malloc(sizeof(char) * (ft_word(s, c) + 1))))
				return (NULL);
			while (*s && *s != c)
				d[i][j++] = (char)*s++;
			d[i][j] = '\0';
			i++;
			j = 0;
		}
	}
	d[i] = NULL;
	return (d);
}
