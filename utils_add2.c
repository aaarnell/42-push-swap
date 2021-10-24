/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_add2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarnell <aarnell@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 21:56:54 by aarnell           #+#    #+#             */
/*   Updated: 2021/10/23 19:07:15 by aarnell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_flstr2(t_vrb *vr)
{
	vr->c_op = vr->c_op_t;
	vr->dp1 = vr->dp1_t;
	vr->dp2 = vr->dp2_t;
	if (vr->s_drc == 1 || vr->s_drc == 3)
	{
		vr->op1 = RRA;
		if (vr->s_drc == 1)
			vr->op2 = RB;
	}
	if (vr->s_drc == 2 || vr->s_drc == 3)
	{
		if (vr->s_drc == 2)
			vr->op1 = RA;
		vr->op2 = RRB;
	}
	vr->mv = *(int *)(vr->tmp->content);
}

static void	ft_dfelopmv(t_vrb *vr)
{
	vr->s_drc = 0;
	vr->dp1_t = ft_cnt_dp(vr->st1, *(int *)(vr->tmp->content), 1, 0);
	vr->dp2_t = ft_cnt_dp(vr->st2, *(int *)(vr->tmp->content), 2, 0);
	if ((vr->ln1 - vr->dp1_t) < vr->dp1_t)
	{
		vr->dp1_t = vr->ln1 - vr->dp1_t;
		vr->s_drc += 1;
	}
	if ((vr->ln2 - vr->dp2_t) < vr->dp2_t)
	{
		vr->dp2_t = vr->ln2 - vr->dp2_t;
		vr->s_drc += 2;
	}
	if ((vr->s_drc == 0 || vr->s_drc == 3) && vr->dp1_t >= vr->dp2_t)
		vr->c_op_t = vr->dp1_t + 1;
	else if ((vr->s_drc == 0 || vr->s_drc == 3) && vr->dp1_t < vr->dp2_t)
		vr->c_op_t = vr->dp2_t + 1;
	else
		vr->c_op_t = vr->dp1_t + vr->dp2_t + 1;
	if (vr->c_op == 0 || vr->c_op > vr->c_op_t)
		ft_flstr2(vr);
}

static void	ft_flstr(t_vrb *vr)
{
	vr->tmp = vr->st2;
	vr->ln1 = ft_lstsize(vr->st1);
	vr->ln2 = ft_lstsize(vr->st2);
	vr->dp1 = 0;
	vr->dp2 = 0;
	vr->mv = *(int *)(vr->st2->content);
	vr->c_op = 0;
	vr->op1 = RA;
	vr->op2 = RB;
}

void	ft_chkmv(t_vrb *vr)
{
	while (vr->st2)
	{
		ft_flstr(vr);
		while (vr->tmp)
		{
			ft_dfelopmv(vr);
			vr->tmp = vr->tmp->next;
		}
		while (vr->c_op)
		{
			if (vr->dp1 && vr->dp2 && (vr->op2 - vr->op1) == 1 \
				&& vr->dp1-- && vr->dp2-- && vr->c_op--)
				ft_pswp(vr, (vr->op2 + 1));
			else if (vr->dp1 && vr->dp1-- && vr->c_op--)
				ft_pswp(vr, vr->op1);
			else if (vr->dp2 && vr->dp2-- && vr->c_op--)
				ft_pswp(vr, vr->op2);
			else if (!vr->dp1 && !vr->dp2 && vr->c_op--)
				ft_pswp(vr, PA);
		}
	}
}

void	ft_trnstmnx(t_vrb *vr, int n_st, int s_mnx)
{
	int			elm;
	enum e_Ops	op;

	vr->tmp = vr->st1;
	op = RA;
	if (n_st != 1)
	{
		vr->tmp = vr->st2;
		op = RB;
	}
	srch_mnavmx(vr->tmp, &vr->min, &vr->avg, &vr->max);
	elm = vr->min;
	if (s_mnx)
		elm = vr->max;
	if (elm == *(int *)(vr->tmp->content))
		return ;
	if ((ft_lstsize(vr->tmp) - ft_cnt_dp(vr->tmp, elm, 0, 0)) < \
		ft_cnt_dp(vr->tmp, elm, 0, 0))
		op = op + 3;
	while ((n_st == 1 && elm != *(int *)(vr->st1->content)) \
		|| (n_st == 2 && elm != *(int *)(vr->st2->content)))
		ft_pswp(vr, op);
}
