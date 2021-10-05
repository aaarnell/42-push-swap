#include "push_swap.h"

static int sort4_2s(t_list **lst1, t_list **lst2, enum Ops *l_op)
{
	t_list *tmp;
	t_list *tmp2;
	int min;
	int max;
	enum Ops tr;

	tmp = NULL;
	tr = RA;
	if (lst1 && !lst2)
		tmp = *lst1;
	else if (!lst1 && lst2)
	{
		tmp = *lst2;
		tr++;
	}
	tmp2 = tmp->next;
	srch_minmax(tmp, &min, &max);
	if (min == *(int *)(tmp->content) && chk_ord(tmp))
		return (1);
	if (*(int *)(tmp->content) <= *(int *)(tmp2->content) || max == *(int *)(tmp->content))
		ft_pushswap4_2(lst1, lst2, tr, l_op);
	else
		ft_pushswap4_2(lst1, lst2, (tr + 6), l_op);
	return (0);
}

t_list *sort4_2(t_list *lst)
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
	sz1 = ft_lstsize(lst);
	l_op = NaN;
	//сбросим в стек2 все элементы кроме 3х
	while (sz1-- > 3)
		ft_pushswap4_2(&st1, &st2, PB, &l_op);
	//сортируем два стека
	while (!(sort4_2s(&st1, NULL, &l_op) * sort4_2s(NULL, &st2, &l_op)));
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
