/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_items.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarnell <aarnell@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 22:12:20 by aarnell           #+#    #+#             */
/*   Updated: 2021/10/18 22:23:20 by aarnell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	srt_3itm(t_vrb *vr)
{
	int	cur_e;

	if (!vr->st1 || !vr->st1->next)
		return ;
	cur_e = *(int *)(vr->st1->content);
	srch_mnavmx(vr->st1, &vr->min, &vr->avg, &vr->max);
	if (ft_chkord(vr->st1))
	{
		if (vr->max == cur_e)
			ft_pswp(vr, RA);
		else if (vr->min != cur_e)
			ft_pswp(vr, RRA);
	}
	else
	{
		if (vr->max == cur_e)
			ft_pswp(vr, RA);
		ft_pswp(vr, SA);
		if (vr->min == cur_e)
			ft_pswp(vr, RA);
	}
}
