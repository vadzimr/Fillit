/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echeung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 18:27:38 by echeung           #+#    #+#             */
/*   Updated: 2020/02/18 15:19:33 by echeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (1);
	}
	if (read_file(av[1]) == 0)
	{
		ft_putstr("error\n");
		return (1);
	}
	return (0);
}
