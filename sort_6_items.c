/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_6_items.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarnell <aarnell@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 22:13:15 by aarnell           #+#    #+#             */
/*   Updated: 2021/10/23 19:07:54 by aarnell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	srt_6itm(t_vrb *vr)
{
	if (!vr->st1 || !vr->st1->next)
		return ;
	vr->ln1 = ft_lstsize(vr->st1);
	srch_mnavmx(vr->st1, &vr->min, &vr->avg, &vr->max);
	if (vr->min == *(int *)(vr->st1->content) && ft_chkord(vr->st1))
		return ;
	while (vr->ln1 > 3)
	{
		if (vr->min != *(int *)(vr->st1->content) && \
			vr->max != *(int *)(vr->st1->content))
		{
			ft_pswp(vr, PB);
			vr->ln1--;
		}
		else
			ft_pswp(vr, RA);
	}
	srt_3itm(vr);
	ft_chkmv(vr);
	ft_trnstmnx(vr, 1, 0);
}
