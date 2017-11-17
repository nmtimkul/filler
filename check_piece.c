/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmtimkul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 19:07:02 by nmtimkul          #+#    #+#             */
/*   Updated: 2017/11/17 14:53:04 by nmtimkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	check_size(t_info *info, t_piece *piece, int x, int y)
{
	if (x > info->m_row || x < 0)
		return (0);
	if (y > info->m_col || y < 0)
		return (0);
	if (x + piece->p_row > info->m_row)
		return (0);
	if (y + piece->p_col > info->m_col)
		return (0);
	return (1);
}

static int	check_pos(t_info *info, t_piece *piece, int x, int y)
{
	int		i;
	int		j;
	int		tmp;
	int		count;

	i = -1;
	tmp = x;
	count = 0;
	while (++i < piece->p_col)
	{
		j = -1;
		x = tmp;
		while (++j < piece->p_row)
		{
			if (info->nbr == 1)
				if (piece->piece[i][j] == '*' && info->map[y][x] == 'O')
					count++;
			if (info->nbr == 2)
				if (piece->piece[i][j] == '*' && info->map[y][x] == 'X')
					count++;
			x++;
		}
		y++;
	}
	return ((count > 1) ? 0 : 1);
}

static int	check_adverse_pos(t_info *info, t_piece *piece, int x, int y)
{
	int		i;
	int		j;
	int		tmp;

	i = 0;
	tmp = x;
	while (i < piece->p_col)
	{
		j = 0;
		x = tmp;
		while (j < piece->p_row)
		{
			if (info->nbr == 1)
				if (piece->piece[i][j] == '*' && info->map[y][x] == 'X')
					return (0);
			if (info->nbr == 2)
				if (piece->piece[i][j] == '*' && info->map[y][x] == 'O')
					return (0);
			j++;
			x++;
		}
		i++;
		y++;
	}
	return (1);
}

int			check_piece_size(t_info *info, t_piece *piece, int x, int y)
{
	if (check_size(info, piece, x, y) == 0)
		return (0);
	if (check_pos(info, piece, x, y) == 0)
		return (0);
	if (check_adverse_pos(info, piece, x, y) == 0)
		return (0);
	return (1);
}
