#include "push_swap.h"

t_list *srt100t_3(t_list *lst)
{
	t_list *st1;
	t_list *st2;
	int lim;
	int min;
	int max;
	enum Ops l_op;

	if (!lst || !lst->next)
		return (lst);
	st1 = lst;
	st2 = NULL;
	lim = cnt_chs(lst);
	l_op = NaN;
	//сбросим в стек2 все элементы кроме 3х
	while (lim-- > 0)
		ft_pushswap4_2(&st1, &st2, PB, &l_op);
	//сортируем два стека
	while (!(pr_srt_1it(&st1, NULL, &l_op) * pr_srt_1it(NULL, &st2, &l_op)));
	//скидываем все из 2 в 1 стек
	srch_minmax(st1, &min, &max);
	while (1)
	{
		if (min == *(int *)(st1->content) && !st2 && chk_ord(st1))
			break;
		if (st2 && min == *(int *)(st1->content) && min > *(int *)(st2->content))
		{
			ft_pushswap4_2(&st1, &st2, PA, &l_op);
			min = *(int *)(st1->content);
		}
		else if (st2 && max == *(int *)(st1->content) && max < *(int *)(st2->content))
		{
			ft_pushswap4_2(&st1, &st2, RA, &l_op);
			ft_pushswap4_2(&st1, &st2, PA, &l_op);
			max = *(int *)(st1->content);
		}
		else if (st2 && *(int *)(st2->content) <= *(int *)(st1->content))
			ft_pushswap4_2(&st1, &st2, PA, &l_op);
		else if (*(int *)(st1->content) <= *(int *)((st1->next)->content) || max == *(int *)(st1->content))
			ft_pushswap4_2(&st1, &st2, RA, &l_op);
	}
	ft_put_op4_2(&l_op, &l_op);	//печатаем последнюю операцию
	return (st1);
}
