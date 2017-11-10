/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmtimkul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 19:07:47 by nmtimkul          #+#    #+#             */
/*   Updated: 2017/11/10 19:08:12 by nmtimkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	ft_move_right(t_info *info, t_piece *piece, int y, int x)
{
	int		i;
	int		j;

	i = piece->p_col - 1;
	while (i >= 0)
	{
		j = piece->p_row - 1;
		while (j >= 0)
		{
			if (piece->piece[i][j] == '*')
			{
				if (check_piece_size(info, piece, x - j, y - i))
				{
					ft_putnbr(y - i);
					ft_putchar(' ');
					ft_putnbr(x - j);
					ft_putchar('\n');
					return (1);
				}
			}
			j--;
		}
		i--;
	}
	return (0);
}

static int	ft_move_left(t_info *info, t_piece *piece, int y, int x)
{
	int		i;
	int		j;

	i = 0;
	while (i < piece->p_col)
	{
		j = 0;
		while (j < piece->p_row)
		{
			if (piece->piece[i][j] == '*')
			{
				if (check_piece_size(info, piece, x - j, y - i))
				{
					ft_putnbr(y - i);
					ft_putchar(' ');
					ft_putnbr(x - j);
					ft_putchar('\n');
					return (1);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

void		ft_move_top(t_info *info, t_piece *piece)
{
	int		y;
	int		x;

	y = 0;
	while (y < info->m_col)
	{
		x = 0;
		while (x < info->m_row)
		{
			if (info->map[y][x] == info->letter)
				if (ft_move_right(info, piece, y, x) == 1)
					return ;
			x++;
		}
		y++;
	}
	info->stop = 1;
}

void		ft_move_bot(t_info *info, t_piece *piece)
{
	int		y;
	int		x;

	y = info->m_col - 1;
	while (y > 0)
	{
		x = info->m_row - 1;
		while (x > 0)
		{
			if (info->map[y][x] == info->letter)
				if (ft_move_left(info, piece, y, x) == 1)
					return ;
			x--;
		}
		y--;
	}
	info->finish = 1;
}

void		ft_place_left(t_info *info, t_piece *piece)
{
	int		y;
	int		x;

	y = info->pivot + (info->m_col / 10) - (info->m_col / 11);
	while (y < info->pivot + (info->m_col / 10) + (info->m_col / 11))
	{
		x = 0;
		while (x < info->m_row)
		{
			if (info->map[y][x] == info->letter)
				if (ft_move_right(info, piece, y, x) == 1)
					return ;
			x++;
		}
		y++;
	}
	info->cantmv = 1;
}
