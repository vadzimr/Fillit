/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echeung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:39:20 by echeung           #+#    #+#             */
/*   Updated: 2020/01/09 16:28:45 by echeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lencount(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static int	ft_edge(int n, char *str)
{
	char	*s;
	int		i;

	i = 0;
	if (n == -2147483648)
	{
		s = "-2147483648";
		while (i <= 12)
		{
			str[i] = s[i];
			i++;
		}
		return (1);
	}
	if (n == 0)
	{
		str[0] = '0';
		return (1);
	}
	return (0);
}

char		*ft_itoa(int n)
{
	int		i;
	char	*str;

	i = ft_lencount(n);
	str = (char*)malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	str[i] = '\0';
	i--;
	if (ft_edge(n, str) == 1)
		return (str);
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (str);
}
