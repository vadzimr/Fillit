/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echeung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:42:02 by echeung           #+#    #+#             */
/*   Updated: 2020/02/17 21:48:18 by echeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		overlap(char *tetri, char board[12][12], int a, int b)
{
	int	j;
	int	x;
	int	y;

	j = 0;
	x = tetri[j] - '0' + a;
	y = tetri[j + 1] - '0' + b;
	while ((j <= 7) && board[y][x] == '.')
	{
		j += 2;
		x = tetri[j] - '0' + a;
		y = tetri[j + 1] - '0' + b;
	}
	return (j);
}

void	place_board(char *tetri, char board[12][12], int xy[2], char letters)
{
	int	j;
	int	x;
	int	y;

	j = 0;
	x = tetri[j] - '0' + xy[0];
	y = tetri[j + 1] - '0' + xy[1];
	while (j <= 6)
	{
		x = tetri[j] - '0' + xy[0];
		y = tetri[j + 1] - '0' + xy[1];
		board[y][x] = letters;
		j += 2;
	}
}

int		recursion(char tetri[27][27], char board[12][12], int size, char *l)
{
	int	i;
	int	xy[2];

	i = 0;
	xy[1] = 0;
	if (ft_strcmp(tetri[i], "NULL") == 0)
		return (1);
	while ((tetri[i][7] - '0' + xy[1]) < size)
	{
		xy[0] = 0;
		while ((tetri[i][4] - '0' + xy[0]) < size)
		{
			if (overlap(tetri[i], board, xy[0], xy[1]) == 8)
			{
				place_board(tetri[i], board, xy, l[i]);
				if (recursion(&tetri[i + 1], board, size, &l[i + 1]) == 1)
					return (1);
				else
					place_board(tetri[i], board, xy, '.');
			}
			xy[0]++;
		}
		xy[1]++;
	}
	return (0);
}

void	make_board(char board[12][12], int size)
{
	int	x;
	int	y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			board[y][x] = '.';
			x++;
		}
		y++;
	}
}

void	solve(char tetri[27][27], int count)
{
	char	board[12][12];
	char	*letters;
	int		size;

	letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	size = 2;
	while ((size * size) < (count * 4))
		size++;
	make_board(board, size);
	while (!recursion(tetri, board, size, letters))
	{
		size++;
		make_board(board, size);
	}
	print_board(board, size);
}
