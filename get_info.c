/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmtimkul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 19:10:32 by nmtimkul          #+#    #+#             */
/*   Updated: 2017/11/10 19:10:52 by nmtimkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_get_numplayer(t_info *info)
{
	char	*line;

	get_next_line(0, &line);
	info->nbr = ft_atoi(&line[10]);
}

void	ft_get_letter(t_info *info)
{
	if (info->nbr == 1)
		info->letter = 'O';
	else
		info->letter = 'X';
}

void	ft_get_h_and_w(t_info *info)
{
	char *line;

	get_next_line(0, &line);
	info->m_col = ft_atoi(&line[8]);
	info->m_row = ft_atoi(&line[11]);
}

void	ft_get_info(t_info *info)
{
	ft_get_numplayer(info);
	ft_get_letter(info);
	ft_get_h_and_w(info);
}
