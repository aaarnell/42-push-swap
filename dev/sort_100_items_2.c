#include "push_swap.h"

t_list *srt100t_2(t_list *lst)
{
	t_list *st1;
	t_list *st2;
	enum Ops l_op;
	int min;
	int max;
	int tmx;
	//int c; //для остановки при ошибке и бесконечном цикле

	//c = 9 * ft_lstsize(lst);

	if (!lst || !lst->next)
		return (lst);
	st1 = lst;
	st2 = NULL;
	tmx = *(int *)(st1->content);
	l_op = NaN;
	srch_minmax(lst, &min, &max);
	while (1)
	{
		//wr_prl_st(st1, st2);
		//write(1, "\n", 1);
		if (min == *(int *)(st1->content) && chk_ord(st1))
			break;
		if (min != *(int *)(st1->content) && max != *(int *)(st1->content))
		{
			if (!st2)
				ft_pushswap4_2(&st1, &st2, PB, &l_op);
			else if (*(int *)(st1->content) > *(int *)(st2->content) \
					&& (!st2->next || tmx == *(int *)(st2->content)))
			{
				tmx = *(int *)(st1->content);
				ft_pushswap4_2(&st1, &st2, PB, &l_op);
				ft_pushswap4_2(&st1, &st2, SB, &l_op);
			}
			else if (*(int *)(st1->content) <= *(int *)(st2->content))
				ft_pushswap4_2(&st1, &st2, PB, &l_op);
			else
				ft_pushswap4_2(&st1, &st2, RB, &l_op);
		}
		else
			ft_pushswap4_2(&st1, &st2, RA, &l_op);
	}
	while (1)
	{
		//wr_prl_st(st1, st2);
		//write(1, "\n", 1);
		if (min == *(int *)(st1->content) && !st2 && chk_ord(st1))
			break;
		if (st2)
		{
			if (*(int *)(st1->content) >= *(int *)(st2->content))
				ft_pushswap4_2(&st1, &st2, PA, &l_op);
			else
				ft_pushswap4_2(&st1, &st2, RA, &l_op);
		}
		else
			pr_srt_1it(&st1, NULL, &l_op);
	}
	ft_put_op4_2(&l_op, &l_op);
	return (st1);
}
