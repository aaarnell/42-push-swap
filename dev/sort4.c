#include "push_swap.h"

static int sort4s(t_list **lst1, t_list **lst2, char *l_op)
{
	//t_list *tmp;
	t_list *tmp2;
	t_list *tm[2];
	int min;
	int max;
	char op[4];
	char c;
/*
	if (!lst1)
	{
		tmp = *lst2;
		tmp2 = (*lst2)->next;
		c = 'b';
	}
	if (!lst2)
	{
		tmp = *lst1;
		tmp2 = (*lst1)->next;
		c = 'a';
	}
	ft_bzero(op, 4);
	srch_minmax(tmp, &min, &max);
	if (min == *(int *)(tmp->content) && chk_ord(tmp))
		return (1);
	if (*(int *)(tmp->content) <= *(int *)(tmp2->content) || max == *(int *)(tmp->content))
		ft_strlcpy(op, "r", 4);
	else
		ft_strlcpy(op, "s", 4);
	ft_strlcat(op, &c, 4);
	ft_pushswap2(lst1, lst2, op, l_op);
	return (0);
*/
	int i;
	printf("______\n");
	i = 0;
	tm[0] = *lst1;
	tm[1] = *lst2;
	while (i < 2)
	{
		tmp2 = tm[i]->next;
		c = 'a' + i;
		ft_bzero(op, 4);
		srch_minmax(tm[i], &min, &max);
		printf("______%d\n", i);
		printf("ps: op = '%s'\tl_op = '%s'\tc = %c\n", op, l_op, c);
		if (min == *(int *)(tm[i]->content) && chk_ord(tm[i]))
		{
			i++;
			continue ;
		}
		if (*(int *)(tm[i]->content) <= *(int *)(tmp2->content) || max == *(int *)(tm[i]->content))
			ft_strlcpy(op, "r", 4);
		else
			ft_strlcpy(op, "s", 4);
		printf("pe: op = '%s'\tl_op = '%s'\n", op, l_op);
		ft_strlcpy(&op[1], &c, 2);
		printf("ppe: op = '%s'\tl_op = '%s'\n", op, l_op);
		ft_pushswap2(lst1, lst2, op, l_op);
		i++;
	}
	wr_prl_st(*lst1, *lst2);
	return (chk_ord(*lst1) * chk_ord(*lst2));
}

t_list *sort4(t_list *lst)
{
	t_list *st1;
	t_list *st2;
	int sz1;
	int min;
	int max;
	//int min1;
	//int max1;
	//int min2;
	//int max2;
	char l_op[4];

	if (!lst || !lst->next)
		return (lst);
	st1 = lst;
	st2 = NULL;
	sz1 = ft_lstsize(lst);
	ft_bzero(l_op, 4);
	srch_minmax(lst, &min, &max);
	//сбросим в стек2 все элементы кроме 3х
	while (sz1 > 3)
	{
		printf("sz1 = %d\n", sz1);
		ft_pushswap2(&st1, &st2, "pb", l_op);
		sz1--;
	}
	//сортируем два стека
	//sleep(3);
	//ft_putstr_fd("sort 2 stacks\n", 1);
	while (1)
	{
		printf("sort 2 stacks\n");
		wr_prl_st(st1, st2);
		if (sort4s(&st1, &st2, l_op))
			break;
	}
	//перейдем в стеке1 на максимальный элемент
	//ft_pushswap2(&st1, &st2, "rra", l_op);
	//забрасываем все из 2 стека в 1й

	while (1)
	{
		if (min == *(int *)(st1->content) && !st2 && chk_ord(st1))
			break;
		if (st2)
			ft_pushswap2(&st1, &st2, "pa", l_op);
		if (*(int *)(st1->content) <= *(int *)((st1->next)->content) || max == *(int *)(st1->content))
			ft_pushswap2(&st1, &st2, "ra", l_op);
		else
			ft_pushswap2(&st1, &st2, "sa", l_op);
		wr_prl_st(st1, st2);
	}
	return (st1);
}
