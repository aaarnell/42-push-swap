#include "push_swap.h"

static void ft_fl_str_vr2(t_vrb *vr)
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

int ft_cnt_dp(t_list *lst, int elm, int n_st)
{
	t_list *tmp;
	int cnt;

	cnt = 0;
	tmp = ft_lstlast(lst);
	if(n_st == 1 && lst)
	{
		if (elm >= *(int *)(tmp->content) && elm <= *(int *)(lst->content))
			return (cnt);
		while (lst->next)
		{
			cnt++;
			if (elm > *(int *)(lst->content) && elm <= *(int *)(lst->next->content))
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

static void ft_def_mv2(t_vrb *vr)
{
	int c_op;
	int sgn;
	int dp1;
	int dp2;

	sgn = 0;
	dp1 = ft_cnt_dp(vr->st1, *(int *)(vr->tmp->content), 1);
	dp2 = ft_cnt_dp(vr->st2, *(int *)(vr->tmp->content), 2);
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

void ft_chk_mv2(t_vrb *vr)
{
	while (vr->st2)
	{
		//заполним структуру
		ft_fl_str_vr2(vr);
		while (vr->tmp)
		{
			ft_def_mv2(vr);
			vr->tmp = vr->tmp->next;
		}
		//крутим стек 1 и стек 2, параллельно двигаем и закидываем элемент в стек 1
		while (vr->c_op)
		{
			//wr_prl_st(*st1, *st2);
			//write(1, "\n", 1);
			if (vr->dp1 && vr->dp2 && (vr->op2 - vr->op1) == 1 \
				&& vr->dp1-- && vr->dp2-- && vr->c_op--)
				ft_pushswap4_3(vr, (vr->op2 + 1));
			else if (vr->dp1 && vr->dp1-- && vr->c_op--)
				ft_pushswap4_3(vr, vr->op1);
			else if (vr->dp2 && vr->dp2-- && vr->c_op--)
				ft_pushswap4_3(vr, vr->op2);
			else if (!vr->dp1 && !vr->dp2 && vr->c_op--)
				ft_pushswap4_3(vr, PA);
			//wr_prl_st(vr->st1, vr->st2);
			//write(1, "\n", 1);
			//wr_2st_str(vr->st1, vr->st2);
		}
	}
}

/*
static struct s_var
{
	//Для чекнуть ошибки
	t_list		*st_1;
	t_list		*st_2;
	int			n_st;
	int			mstk1;
	int			mstk2;
	//Для чекнуть ошибки
	t_list		*st1;
	t_list		*st2;
	t_list		*tmp;
	int			ln1;
	int			ln2;
	int			dp1;
	int			dp2;
	int			mv;
	int			c_op;
	enum Ops	op1;
	enum Ops	op2;
} vrr;
*/
/*
static void ft_fl_str_vr(t_list *st1, t_list *st2)
{
	vrr.tmp = st2;
	vrr.ln1 = ft_lstsize(st1);
	vrr.ln2 = ft_lstsize(st2);
	vrr.dp1 = 0;
	vrr.dp2 = 0;
	vrr.mv = *(int *)(st2->content);
	vrr.c_op = 0;
	vrr.op1 = RA;
	vrr.op2 = RB;
}*/

/*
static void ft_fl_str_vr2(t_vrb *vr)
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
}*/


/*
static void ft_def_mv(t_list *st1, t_list *st2)
{
	int c_op;
	int sgn;
	int dp1;
	int dp2;

	sgn = 0;
	dp1 = ft_cnt_dp(st1, *(int *)(vrr.tmp->content), 1);
	dp2 = ft_cnt_dp(st2, *(int *)(vrr.tmp->content), 2);
	if ((vrr.ln1 - dp1) < dp1)
	{
		dp1 = vrr.ln1 - dp1;
		sgn += 1;
	}
	if ((vrr.ln2 - dp2) < dp2)
	{
		dp2 = vrr.ln2 - dp2;
		sgn += 2;
	}
	if ((sgn == 0 || sgn == 3) && dp1 >= dp2)
		c_op = dp1 + 1;
	else if ((sgn == 0 || sgn == 3) && dp1 < dp2)
		c_op = dp2 + 1;
	else
		c_op = dp1 + dp2 + 1;
	if (vrr.c_op == 0 || vrr.c_op > c_op)
	{
		vrr.c_op = c_op;
		vrr.dp1 = dp1;
		vrr.dp2 = dp2;
		if (sgn == 1 || sgn == 3)
		{
			vrr.op1 = RRA;
			if (sgn == 1)
				vrr.op2 = RB;
		}
		if (sgn == 2 || sgn == 3)
		{
			if (sgn == 2)
				vrr.op1 = RA;
			vrr.op2 = RRB;
		}
		vrr.mv = *(int *)(vrr.tmp->content);
	}
}*/

/*
static void ccl_def(t_list **st1, t_list **st2)
{
	while (vrr.tmp)
	{
		ft_def_mv(*st1, *st2);
		vrr.tmp = vrr.tmp->next;
	}
}*/
/*
static void ccl_mv(t_list **st1, t_list **st2, enum Ops *l_op)
{
	while (vrr.c_op)
	{
		//wr_prl_st(*st1, *st2);
		//write(1, "\n", 1);
		//if (vrr.dp1 && vrr.dp2 && (vrr.op2 - vrr.op1) == 1 \
		//	&& vrr.dp1-- && vrr.dp2-- && vrr.c_op--)
		//	ft_pushswap4_2(st1, st2, (vrr.op2 + 1), l_op);
		if (vrr.dp1 && vrr.dp1-- && vrr.c_op--)
			ft_pushswap4_2(st1, st2, vrr.op1, l_op);
		if (vrr.dp2 && vrr.dp2-- && vrr.c_op--)
			ft_pushswap4_2(st1, st2, vrr.op2, l_op);
		if (!vrr.dp1 && !vrr.dp2 && vrr.c_op--)
			ft_pushswap4_2(st1, st2, PA, l_op);
		wr_prl_st(*st1, *st2);
		write(1, "\n", 1);
	}
}*/
/*
void ft_chk_mv(t_list **st1, t_list **st2, enum Ops *l_op)
{
	while (*st2)
	{
		//заполним структуру
		ft_fl_str_vr(*st1, *st2);
		while (vrr.tmp)
		{
			ft_def_mv(*st1, *st2);
			vrr.tmp = vrr.tmp->next;
		}
		//ccl_def(st1, st2);
		//крутим стек 1 и стек 2, параллельно двигаем и закидываем элемент в стек 1
		while (vrr.c_op)
		{
			//wr_prl_st(*st1, *st2);
			//write(1, "\n", 1);
			if (vrr.dp1 && vrr.dp2 && (vrr.op2 - vrr.op1) == 1 \
				&& vrr.dp1-- && vrr.dp2-- && vrr.c_op--)
				ft_pushswap4_2(st1, st2, (vrr.op2 + 1), l_op);
			else if (vrr.dp1 && vrr.dp1-- && vrr.c_op--)
				ft_pushswap4_2(st1, st2, vrr.op1, l_op);
			else if (vrr.dp2 && vrr.dp2-- && vrr.c_op--)
				ft_pushswap4_2(st1, st2, vrr.op2, l_op);
			else if (!vrr.dp1 && !vrr.dp2 && vrr.c_op--)
				ft_pushswap4_2(st1, st2, PA, l_op);
			//wr_prl_st(*st1, *st2);
			//write(1, "\n", 1);
		}
		//ccl_mv(st1, st2, l_op);
	}
}
*/


