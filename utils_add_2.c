#include "push_swap.h"

static struct s_var
{
	t_list *tmp1;
	t_list *tmp2;
	int	ln1;
	int	ln2;
	int	dp1;
	int dp2;
	int mv;
	int c_op;
	enum Ops op1;
	enum Ops op2;
} vr;

static void ft_fl_str_vr(t_list *st1, t_list *st2)
{
	vr.tmp1 = st1;
	vr.tmp2 = st2;
	vr.ln1 = ft_lstsize(st1);
	vr.ln2 = ft_lstsize(st2);
	vr.dp1 = 0;
	vr.dp2 = 0;
	vr.mv = *(int *)(st2->content);
	vr.c_op = 0;
	vr.op1 = RA;
	vr.op2 = RB;
}

int ft_cnt_dp(t_list *lst, int elm, int n_st)
{
	t_list *tmp;
	int cnt;

	cnt = 0;
	tmp = ft_lstlast(lst);
	if(n_st == 1)
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
	else
		while (lst && elm != *(int *)(lst->content))
		{
			cnt++;
			lst = lst->next;
		}
	return (cnt);
}

static void ft_def_mv(t_list *st1, t_list *st2)
{
	int c_op;
	int sgn;
	int dp1;
	int dp2;

	sgn = 0;
	dp1 = ft_cnt_dp(st1, *(int *)(vr.tmp2->content), 1);
	dp2 = ft_cnt_dp(st2, *(int *)(vr.tmp2->content), 2);
	if ((vr.ln1 - dp1) < dp1)
	{
		dp1 = vr.ln1 - dp1;
		sgn += 1;
	}
	if ((vr.ln2 - dp2) < dp2)
	{
		dp2 = vr.ln2 - dp2;
		sgn += 2;
	}
	if ((sgn == 0 || sgn == 3) && dp1 >= dp2)
		c_op = dp1 + 1;
	else if ((sgn == 0 || sgn == 3) && dp1 < dp2)
		c_op = dp2 + 1;
	else
		c_op = dp1 + dp2 + 1;
	if (vr.c_op == 0 || vr.c_op > c_op)
	{
		vr.c_op = c_op;
		vr.dp1 = dp1;
		vr.dp2 = dp2;
		/*if (sgn == 1 || sgn == 3)
			vr.op1 = RRA;
		if (sgn == 2 || sgn == 3)
			vr.op2 = RRB;*/
		if (sgn == 1 || sgn == 3)
		{
			vr.op1 = RRA;
			if (sgn == 1)
				vr.op2 = RB;
		}
		if (sgn == 2 || sgn == 3)
		{
			if (sgn == 2)
				vr.op1 = RA;
			vr.op2 = RRB;
		}
		vr.mv = *(int *)(vr.tmp2->content);
	}
}

static void ccl_def(t_list **st1, t_list **st2)
{
	while (vr.tmp2)
	{
		ft_def_mv(*st1, *st2);
		vr.tmp2 = vr.tmp2->next;
	}
}

static void ccl_mv(t_list **st1, t_list **st2, enum Ops *l_op)
{
	while (vr.c_op)
	{
		//wr_prl_st(*st1, *st2);
		//write(1, "\n", 1);
		if (vr.dp1 && vr.dp2 && (vr.op2 - vr.op1) == 1 \
			&& vr.dp1-- && vr.dp2-- && vr.c_op--)
			ft_pushswap4_2(st1, st2, (vr.op2 + 1), l_op);
		else if (vr.dp1 && vr.dp1-- && vr.c_op--)
			ft_pushswap4_2(st1, st2, vr.op1, l_op);
		else if (vr.dp2 && vr.dp2-- && vr.c_op--)
			ft_pushswap4_2(st1, st2, vr.op2, l_op);
		else if (!vr.dp1 && !vr.dp2 && vr.c_op--)
			ft_pushswap4_2(st1, st2, PA, l_op);
		//wr_prl_st(*st1, *st2);
		//write(1, "\n", 1);
	}
}

void ft_chk_mv(t_list **st1, t_list **st2, enum Ops *l_op)
{
	while (*st2)
	{
		//заполним структуру
		ft_fl_str_vr(*st1, *st2);
		/*while (vr.tmp2)
		{
			ft_def_mv(*st1, *st2);
			vr.tmp2 = vr.tmp2->next;
		}*/
		ccl_def(st1, st2);


		//крутим стек 1 и стек 2, параллельно двигаем и закидываем элемент в стек 1
		/*while (vr.c_op)
		{
			wr_prl_st(*st1, *st2);
			write(1, "\n", 1);
			if (vr.dp1 && vr.dp2 && (vr.op2 - vr.op1) == 1 \
				&& vr.dp1-- && vr.dp2-- && vr.c_op--)
				ft_pushswap4_2(st1, st2, (vr.op2 + 1), l_op);
			else if (vr.dp1 && vr.dp1-- && vr.c_op--)
				ft_pushswap4_2(st1, st2, vr.op1, l_op);
			else if (vr.dp2 && vr.dp2-- && vr.c_op--)
				ft_pushswap4_2(st1, st2, vr.op2, l_op);
			else if (!vr.dp1 && !vr.dp2 && vr.c_op--)
				ft_pushswap4_2(st1, st2, PA, l_op);
			wr_prl_st(*st1, *st2);
			write(1, "\n", 1);
		}*/
		ccl_mv(st1, st2, l_op);
	}
}
