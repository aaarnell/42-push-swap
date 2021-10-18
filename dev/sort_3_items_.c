#include "push_swap.h"

int pr_srt_1it(t_list **lst1, t_list **lst2, enum Ops *l_op)
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

t_list *srt_3itm(t_list *lst)
{
	enum Ops l_op;

	if (!lst || !lst->next)
		return (lst);
	l_op = NaN;
	while (!pr_srt_1it(&lst, NULL, &l_op));
	ft_put_op4_2(&l_op, &l_op);	//печатаем последнюю операцию
	return (lst);
}

t_list *srt_3itm_(t_vrb *vr)
{
	if (!vr->st1 || !vr->st1->next)
		return (vr->st1);
	srch_minmax(vr->st1, vr->min, vr->max);
	while (1)
	{
		if (vr->min == *(int *)(vr->st1->content) && chk_ord(vr->st1))
			break ;
		if (*(int *)(vr->st1->content) <= *(int *)(vr->st1->next->content) || \
			vr->max == *(int *)(vr->st1->content))
			ft_pswp(vr, RA);
		else
			ft_pswp(vr, SA);
	}
	return (vr-st1);
}
