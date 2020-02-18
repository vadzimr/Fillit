/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echeung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 14:48:30 by echeung           #+#    #+#             */
/*   Updated: 2020/02/17 18:16:23 by echeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

# define SHAPE_1 "#...#...#...#"
# define SHAPE_2 "####"
# define SHAPE_3 "##..##"
# define SHAPE_4 "#...#...##"
# define SHAPE_5 "##...#...#"
# define SHAPE_6 "###.#"
# define SHAPE_7 "#.###"
# define SHAPE_8 "##..#...#"
# define SHAPE_9 "#...#..##"
# define SHAPE_10 "#...###"
# define SHAPE_11 "###...#"
# define SHAPE_12 "#...##...#"
# define SHAPE_13 "##.##"
# define SHAPE_14 "#..##..#"
# define SHAPE_15 "##...##"
# define SHAPE_16 "#..###"
# define SHAPE_17 "#..##...#"
# define SHAPE_18 "#...##..#"
# define SHAPE_19 "###..#"

int		read_file(char *str);
int		valid_tetrimino(char *buff, int ret);
char	*make_string(char *buff);
int		valid_shape(char *buff);
int		valid_char(char *buff);
char	*get_shape(char *buff);
char	*cmp_shape(char *tmp);
void	solve(char tetri[27][27], int count);
void	make_board(char board[12][12], int size);
int		recursion(char tetri[27][27], char board[12][12], int size, char *l);
void	place_board(char *tetri, char board[12][12], int xy[2], char letters);
int		overlap(char *tetri, char board[12][12], int a, int b);
void	print_board(char board[12][12], int size);

#endif
