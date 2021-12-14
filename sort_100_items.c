/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100_items.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarnell <aarnell@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 22:12:42 by aarnell           #+#    #+#             */
/*   Updated: 2021/12/08 20:08:18 by aarnell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	srt100(t_vrb *vr)
{
	if (!vr->st1 || !vr->st1->next)
		return ;
	vr->ln1 = ft_lstsize(vr->st1);
	srch_mnavmx(vr->st1, &vr->min, &vr->avg, &vr->max);
	if (vr->min == *(int *)(vr->st1->content) && ft_chkord(vr->st1))
		return ;
	while (vr->ln1 > 2)
	{
		if (vr->min != *(int *)(vr->st1->content) && \
			vr->max != *(int *)(vr->st1->content))
		{
			ft_pswp(vr, PB, 1);
			vr->ln1--;
			if (*(int *)(vr->st2->content) >= vr->avg)
				ft_pswp(vr, RB, 1);
			if (vr->ln1 == 2 && vr->min == *(int *)(vr->st1->content))
				ft_pswp(vr, RA, 1);
		}
		else
			ft_pswp(vr, RA, 1);
	}
	ft_chkmv(vr);
	ft_trnstmnx(vr, 1, 0);
}
