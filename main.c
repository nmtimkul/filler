/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmtimkul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 19:11:21 by nmtimkul          #+#    #+#             */
/*   Updated: 2017/11/10 19:11:29 by nmtimkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		ft_init(t_info *info, t_piece *piece)
{
	info->nbr = 0;
	info->pivot = 0;
	info->stop_agr = 0;
	info->stop = 0;
	info->cantmv = 0;
	info->finish = 0;
	piece->p_col = 0;
	piece->p_row = 0;
}

int				main(void)
{
	t_info	info;
	t_piece	piece;

	ft_init(&info, &piece);
	ft_get_info(&info);
	while (1)
	{
		if (info.nbr == 1 || info.nbr == 2)
			if (ft_player(&info, &piece) == 0)
				break ;
	}
}
