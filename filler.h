/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mntumba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 14:31:49 by mntumba           #+#    #+#             */
/*   Updated: 2017/11/10 19:04:29 by nmtimkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct	s_info
{
	int			nbr;
	int			pivot;
	int			m_col;
	int			m_row;
	int			stop_agr;
	int			stop;
	int			cantmv;
	int			finish;
	char		letter;
	char		**map;
}				t_info;

typedef struct	s_piece
{
	int			p_col;
	int			p_row;
	int			x;
	int			y;
	char		**piece;
}				t_piece;

void			ft_move_top(t_info *info, t_piece *piece);
void			ft_move_bot(t_info *info, t_piece *piece);
void			ft_place_left(t_info *info, t_piece *piece);
void			ft_get_info(t_info *info);
void			ft_get_map(t_info *info, t_piece *piece);
void			ft_get_pivotmap(t_info *info);
int				ft_player(t_info *info, t_piece *piece);
int				check_piece_size(t_info *info, t_piece *piece, int x, int y);
int				get_next_line(int const fd, char **line);

#endif
