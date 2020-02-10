/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echeung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:42:02 by echeung           #+#    #+#             */
/*   Updated: 2020/02/10 15:49:57 by echeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	overlap(char *tetri, char board[12][12], int a, int b)
{
	int	j;
	int	x;
	int	y;

	j = 0;
	x = tetri[j] - '0' + a;
	y = tetri[j + 1] - '0' + b;
	while ((j < 8) && board[x][y] == '.')
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
	while (j < 8)
	{
		x = tetri[j] - '0' + xy[0];
		y = tetri[j + 1] - '0' + xy[1];
		board[x][y] = letters;
		j += 2;
	}
}

int	solve_recursion(char tetri[27][27], char board[12][12], int size, char *letters)
{
	int	i;
	int	xy[2];

	i = 0;
	xy[0] = 0;
	xy[1] = 0;
	if (tetri[i] == NULL)
		return (1);
	while ((tetri[i][4] - '0' + xy[0]) < size)
	{
		while ((tetri[i][7] - '0' + xy[1]) < size)
		{
			if (overlap(tetri[i], board, xy[0], xy[1]) == 8)
			{
				place_board(tetri[i], board, xy, letters[i]);
				if (solve_recursion(&tetri[i + 1], board, size, &letters[i + 1]) == 1)
				   return (1);
				else
					place_board(tetri[i], board, xy, '.');
			}
			xy[1]++;
		}
		xy[1] = 0;
		xy[0]++;
	}
	return (0);
}

void	make_board(char board[12][12], int size)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < size)
	{
		while (y < size)
		{
			board[x][y] = '.';
			y++;
		}
		x++;
	}
}

void	solve(char **tetri, int count)
{
	char	board[12][12];
	char	*letters;
	int		size;

	letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	size = 2;
	while ((size * size) < (count * 4))
		size++;
	make_board(board, size);
	while (!solve_recursion(tetri, board, size, letters))
	{
		size++;
		make_board(board, size);
	}
	print_board(board, size);
}
