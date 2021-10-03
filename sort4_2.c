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
	srch_minmax(lst, &min, &max);
	//сбросим в стек2 все элементы кроме 3х
	while (sz1 > 3)
	{
		//printf("sz1 = %d\n", sz1);
		if (max == *(int *)(st1->content))
			ft_pushswap4_2(&st1, &st2, RA, &l_op);
		else
		{
			ft_pushswap4_2(&st1, &st2, PB, &l_op);
			sz1--;
		}
	}
	//сортируем два стека
	while (1)
	{
		//printf("sort 2 stacks\n");
		//wr_prl_st(st1, st2);
		if ((sort4_2s(&st1, NULL, &l_op) * sort4_2s(NULL, &st2, &l_op)))
			break;
	}
	//printf("__bb__\n");
	//забрасываем все из 2 стека в 1й
	while (1)
	{
		if (min == *(int *)(st1->content) && !st2 && chk_ord(st1))
			break;
		if (st2 && *(int *)(st2->content) <= *(int *)(st1->content))
			ft_pushswap4_2(&st1, &st2, PA, &l_op);
		else if (*(int *)(st1->content) <= *(int *)((st1->next)->content) || max == *(int *)(st1->content))
			ft_pushswap4_2(&st1, &st2, RA, &l_op);
		//ft_put_op4_2(&l_op, &l_op);
		//wr_prl_st(st1, st2);
	}
	return (st1);
}
