/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echeung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 18:53:41 by echeung           #+#    #+#             */
/*   Updated: 2019/12/11 12:08:37 by echeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystk, const char *ndl, size_t len)
{
	size_t	i;
	size_t	j;

	if (*ndl == '\0')
		return ((char *)haystk);
	i = 0;
	j = 0;
	while (haystk[i] != '\0' && i < len)
	{
		if (haystk[i] == ndl[0])
		{
			while (ndl[j] != '\0' && haystk[i + j] == ndl[j] && i + j < len)
				j++;
			if (ndl[j] == '\0')
				return ((char *)haystk + i);
		}
		i++;
	}
	return (NULL);
}
