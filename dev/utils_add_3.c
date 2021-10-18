#include "push_swap.h"

static void ft_fl_str_vr1_2(t_vrb *vr)
{
	vr->tmp = vr->st1;
	vr->ln1 = ft_lstsize(vr->st1);
	vr->ln2 = ft_lstsize(vr->st2);
	vr->dp1 = 0;
	vr->dp2 = 0;
	vr->mv = *(int *)(vr->st1->content);
	vr->c_op = 0;
	vr->op1 = RA;
	vr->op2 = RB;
}

//Расчет операций для переброса в стек 2 с единовременной сортировкой сверху вниз от большего к меньшему
static int ft_cnt_dp2_2(t_list *lst, int elm, int n_st)
{
	t_list *tmp;
	int cnt;
	int min;
	int max;

	cnt = 0;
	tmp = ft_lstlast(lst);
	if(n_st == 1 && lst)
	{
		srch_minmax(lst, &min, &max);
		if ((elm >= max && max == *(int *)(lst->content)) || \
			(elm <= min && min == *(int *)(tmp->content)) || \
			(elm <= *(int *)(tmp->content) && elm >= *(int *)(lst->content)))
			return (cnt);
		while (lst)
		{
			cnt++;
			if (lst->next && ((elm >= max && max == *(int *)(lst->next->content)) || \
				(elm <= min && min == *(int *)(lst->content)) || \
				(elm = *(int *)(lst->content) && elm >= *(int *)(lst->next->content))))
				break ;
			lst = lst->next;
		}
	}
	if(n_st != 1 && lst)
		while (lst && elm != *(int *)(lst->content))
		{
			cnt++;
			lst = lst->next;
		}
	return (cnt);
}
//Расчет операций для переброса в стек 2 с единовременной сортировкой сверху вниз меньшего к большему
static int ft_cnt_dp2(t_list *lst, int elm, int n_st)
{
	t_list *tmp;
	int cnt;
	int min;
	int max;

	cnt = 0;
	tmp = ft_lstlast(lst);
	if(n_st == 1 && lst)
	{
		srch_minmax(lst, &min, &max);
		if ((elm >= *(int *)(tmp->content) && elm <= *(int *)(lst->content)) || \
			(elm >= *(int *)(tmp->content) && max == *(int *)(tmp->content)) || \
			(elm <= *(int *)(lst->content) && min == *(int *)(lst->content)))
			return (cnt);
		while (lst->next)
		{
			cnt++;
			if ((elm > *(int *)(lst->content) && elm <= *(int *)(lst->next->content)) || \
				(elm > *(int *)(lst->content) && max == *(int *)(lst->content)) || \
				(elm <= *(int *)(lst->next->content) && min == *(int *)(lst->next->content)))
			lst = lst->next;
		}
	}
	if(n_st != 1 && lst)
		while (lst && elm != *(int *)(lst->content))
		{
			cnt++;
			lst = lst->next;
		}
	return (cnt);
}

static void ft_def_mv1_2(t_vrb *vr)
{
	int c_op;
	int sgn;
	int dp1;
	int dp2;

	if (vr->min == *(int *)(vr->tmp->content) || vr->max == *(int *)(vr->tmp->content))
		return ;
	sgn = 0;
	dp1 = ft_cnt_dp2_2(vr->st1, *(int *)(vr->tmp->content), 0);
	dp2 = ft_cnt_dp2_2(vr->st2, *(int *)(vr->tmp->content), 1);
	if ((vr->ln1 - dp1) < dp1)
	{
		dp1 = vr->ln1 - dp1;
		sgn += 1;
	}
	if ((vr->ln2 - dp2) < dp2)
	{
		dp2 = vr->ln2 - dp2;
		sgn += 2;
	}
	if ((sgn == 0 || sgn == 3) && dp1 >= dp2)
		c_op = dp1 + 1;
	else if ((sgn == 0 || sgn == 3) && dp1 < dp2)
		c_op = dp2 + 1;
	else
		c_op = dp1 + dp2 + 1;
	if (vr->c_op == 0 || vr->c_op > c_op)
	{
		vr->c_op = c_op;
		vr->dp1 = dp1;
		vr->dp2 = dp2;
		if (sgn == 1 || sgn == 3)
		{
			vr->op1 = RRA;
			if (sgn == 1)
				vr->op2 = RB;
		}
		if (sgn == 2 || sgn == 3)
		{
			if (sgn == 2)
				vr->op1 = RA;
			vr->op2 = RRB;
		}
		vr->mv = *(int *)(vr->tmp->content);
	}
}

static void ft_trn_st_t_mnx(t_vrb *vr, int n_st, int s_mnx)
{
	t_list *tmp;
	int min;
	int max;
	int elm;
	enum Ops op;

	tmp = vr->st1;
	op = RA;
	if (n_st != 1)
	{
		tmp = vr->st2;
		op = RB;
	}
	srch_minmax(tmp, &min, &max);
	elm = min;
	if (s_mnx)
		elm = max;
	if (elm == *(int *)(tmp->content))
		return ;
	if ((ft_lstsize(tmp) - ft_cnt_dp2(tmp, elm, 0)) < ft_cnt_dp2(tmp, elm, 0))
		op = op + 3;
	while ((n_st == 1 && elm != *(int *)(vr->st1->content)) \
		|| (n_st == 2 && elm != *(int *)(vr->st2->content)))
		ft_pushswap4_3(vr, op);
}

void ft_chk_mv1_2(t_vrb *vr)
{
	while (vr->ln1 > 2)
	{
		//заполним структуру
		while (vr->min == *(int *)(vr->st1->content) || vr->max == *(int *)(vr->st1->content))
		{
			ft_pushswap4_3(vr, RA);
		}
		ft_fl_str_vr1_2(vr);
		while (vr->tmp)
		{
			ft_def_mv1_2(vr);
			vr->tmp = vr->tmp->next;
		}
		while (vr->c_op)
		{
			if (vr->dp1 && vr->dp2 && (vr->op2 - vr->op1) == 1 \
				&& vr->dp1-- && vr->dp2-- && vr->c_op--)
				ft_pushswap4_3(vr, (vr->op2 + 1));
			else if (vr->dp1 && vr->dp1-- && vr->c_op--)
				ft_pushswap4_3(vr, vr->op1);
			else if (vr->dp2 && vr->dp2-- && vr->c_op--)
				ft_pushswap4_3(vr, vr->op2);
			else if (!vr->dp1 && !vr->dp2 && vr->c_op-- && vr->ln1--)
				ft_pushswap4_3(vr, PB);
		}
	}
	ft_trn_st_t_mnx(vr, 2, 1);
}
