#include "push_swap.h"

t_list *srt100t_4(t_list *lst)
{
	t_list *st1;
	t_list *st2;
	int sz1;
	int min;
	int max;
	enum Ops l_op;

	if (!lst || !lst->next)
		return (lst);
	st1 = lst;
	st2 = NULL;
	sz1 = ft_lstsize(st1);
	l_op = NaN;
	//сбросим в стек2 все элементы кроме min && max
	srch_minmax(st1, &min, &max);
	while (sz1 > 2)
	{
		//wr_prl_st(st1, st2);
		//write(1, "\n", 1);
		if (min != *(int *)(st1->content) && max != *(int *)(st1->content))
		{
			ft_pushswap4_2(&st1, &st2, PB, &l_op);
			sz1--;
			if (sz1 == 2 && min == *(int *)(st1->content))
				ft_pushswap4_2(&st1, &st2, RA, &l_op);
		}
		else
			ft_pushswap4_2(&st1, &st2, RA, &l_op);
	}
	//wr_prl_st(st1, st2);
	//write(1, "\n", 1);
	//вернем все элементы обратно в 1 стек
	ft_chk_mv(&st1, &st2, &l_op);

	//wr_prl_st(st1, st2);
	//write(1, "\n", 1);
	//прокрутим стек1 до min
	if (min != *(int *)(st1->content))
	{
		sz1 = ft_cnt_dp(st1, min, 2);
		if ((ft_lstsize(st1) - sz1) < sz1)
		{
			sz1 = ft_lstsize(st1) - sz1;
			while (sz1--)
			{
				ft_pushswap4_2(&st1, &st2, RRA, &l_op);
				//wr_prl_st(st1, st2);
				//write(1, "\n", 1);
			}
		}
		else
			while (sz1--)
			{
				ft_pushswap4_2(&st1, &st2, RA, &l_op);
				//wr_prl_st(st1, st2);
				//write(1, "\n", 1);
			}
	}
	ft_put_op4_2(&l_op, &l_op);	//печатаем последнюю операцию
	return (st1);
}
