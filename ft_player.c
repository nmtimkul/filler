/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmtimkul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 19:08:44 by nmtimkul          #+#    #+#             */
/*   Updated: 2017/11/10 19:09:19 by nmtimkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		ft_check_column(t_info *info, int x)
{
	int		y;

	y = 0;
	while (y < info->m_col)
	{
		if (info->map[y][x] == info->letter)
			return (1);
		y++;
	}
	return (0);
}

static int		ft_check_line(t_info *info, int y, char c)
{
	int		x;

	x = 0;
	while (x < info->m_row)
	{
		if (info->map[y][x] == c || info->map[y][x] == ft_toupper(c))
			return (1);
		x++;
	}
	return (0);
}

static int		ft_check_aggresive(t_info *info)
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
			{
				if (ft_check_line(info, y, 'x') == 1 ||
						ft_check_line(info, y, 'o') == 1)
					return (1);
				else
					return (0);
			}
			x--;
		}
		y--;
	}
	return (0);
}

static void		ft_stop_aggresive(t_info *info)
{
	int		x;

	x = 0;
	while (x < info->m_col)
	{
		if (info->map[0][x] == info->letter ||
				info->map[info->m_col - 1][x] == info->letter)
		{
			info->stop_agr = 1;
			return ;
		}
		x++;
	}
	info->stop_agr = 0;
}

int				ft_player(t_info *info, t_piece *piece)
{
	info->stop = 0;
	ft_get_map(info, piece);
	ft_get_pivotmap(info);
	ft_stop_aggresive(info);
	if (ft_check_column(info, info->m_row - 1) == 0 &&
			ft_check_column(info, 0) == 0 &&
			ft_check_line(info, info->pivot, 'o') == 1 &&
			ft_check_aggresive(info) == 0)
		ft_place_left(info, piece);
	else if (ft_check_aggresive(info) == 1 && info->stop_agr == 0)
		ft_move_top(info, piece);
	else
		ft_move_bot(info, piece);
	if (info->stop == 1 || info->cantmv == 1)
		ft_move_bot(info, piece);
	if (info->finish == 1)
	{
		ft_putnbr(0);
		ft_putchar(' ');
		ft_putnbr(0);
		ft_putchar('\n');
		return (0);
	}
	return (1);
}
