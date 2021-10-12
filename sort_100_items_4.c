#include "push_swap.h"

t_list *srt100t_4(t_vrb *vr)
{
	int sz1;
	int min;
	int max;
	enum Ops l_op;

	if (!vr->st1 || !vr->st1->next)
		return (vr->st1);
	sz1 = ft_lstsize(vr->st1);
	l_op = NaN;
	//сбросим в стек2 все элементы кроме min && max
	srch_minmax(vr->st1, &min, &max);
	//wr_prl_st(st1, st2);
	//write(1, "\n", 1);
	while (sz1 > 2)
	{
		if (min != *(int *)(vr->st1->content) && max != *(int *)(vr->st1->content))
		{
			ft_pushswap4_3(vr, PB, &l_op);
			sz1--;
			if (sz1 == 2 && min == *(int *)(vr->st1->content))
				ft_pushswap4_3(vr, RA, &l_op);
		}
		else
			ft_pushswap4_3(vr, RA, &l_op);
		//wr_prl_st(st1, st2);
		//write(1, "\n", 1);
	}
	//wr_prl_st(st1, st2);
	//write(1, "\n", 1);
	//вернем все элементы обратно в 1 стек
	//ft_chk_mv(&(vr->st1), &(vr->st2), &l_op);
	ft_chk_mv2(vr, &l_op);
	//wr_prl_st(st1, st2);
	//write(1, "\n", 1);
	//прокрутим стек1 до min
	if (min != *(int *)(vr->st1->content))
	{
		sz1 = ft_cnt_dp(vr->st1, min, 2);
		if ((ft_lstsize(vr->st1) - sz1) < sz1)
		{
			sz1 = ft_lstsize(vr->st1) - sz1;
			while (sz1--)
			{
				ft_pushswap4_3(vr, RRA, &l_op);
				//wr_prl_st(st1, st2);
				//write(1, "\n", 1);
			}
		}
		else
			while (sz1--)
			{
				ft_pushswap4_3(vr, RA, &l_op);
				//wr_prl_st(st1, st2);
				//write(1, "\n", 1);
			}
	}
	if (l_op != NaN)
		ft_put_op4_2(&l_op, &l_op);	//печатаем последнюю операцию
	return (vr->st1);
}
