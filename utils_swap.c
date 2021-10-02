#include "push_swap.h"

void ft_lstswp(t_list **lst)	// Изменение первых двух элементов местами (sa/sb/ss)
{
	t_list *tmp;

	if (!lst || !(*lst)->next)
		return ;
	tmp = (*lst)->next;
	(*lst)->next = tmp->next;
	tmp->next = *lst;
	*lst = tmp;
}

void ft_lstpush(t_list **lst1, t_list **lst2)	//Перенос головы второго списка в голову первого (pa/pb)
{
	t_list *tmp;

	if (!lst2)
		return ;
	tmp = (*lst2)->next;
	(*lst2)->next = *lst1;
	*lst1 = *lst2;
	*lst2 = tmp;
}

void ft_lstrot(t_list **lst)	//Перенос головы списка в его конец (ra/rb/rr)
{
	t_list *tmp;

	if (!lst || !(*lst)->next)
		return ;
	tmp = (*lst)->next;
	ft_lstadd_back(lst, *lst);
	(*lst)->next = NULL;
	*lst = tmp;
}

void ft_lstrev(t_list **lst)	//Перенос хвоста списка в голову (rra/rrb/rrr)
{
	t_list *tmp;
	t_list *tmp2;

	if (!lst || !(*lst)->next)
		return ;
	tmp = ft_lstlast(*lst);
	tmp2 = *lst;
	while (tmp2->next != tmp)
		tmp2 = tmp2->next;
	tmp2->next = NULL;
	ft_lstadd_front(lst, tmp);
}

void ft_pushswap(t_list **lst1, t_list **lst2, char *op)
{
	if (!ft_strncmp(op, "rra", 3) || !ft_strncmp(op, "rrb", 3))
		ft_lstrev(lst1);
	else if (!ft_strncmp(op, "rrr", 3))
	{
		ft_lstrev(lst1);
		ft_lstrev(lst2);
	}
	else if (!ft_strncmp(op, "ra", 2) || !ft_strncmp(op, "rb", 2))
		ft_lstrot(lst1);
	else if (!ft_strncmp(op, "rr", 2))
	{
		ft_lstrot(lst1);
		ft_lstrot(lst2);
	}
	if (!ft_strncmp(op, "sa", 2) || !ft_strncmp(op, "sb", 2))
		ft_lstswp(lst1);
	if (!ft_strncmp(op, "ss", 2))
	{
		ft_lstswp(lst1);
		ft_lstswp(lst2);
	}
	if (!ft_strncmp(op, "pa", 2) || !ft_strncmp(op, "pb", 2))
		ft_lstpush(lst1, lst2);
}

void ft_pushswap2(t_list **lst1, t_list **lst2, char *op, char *l_op)
{
	int i;

	i = ft_strlen(op);
	if (!ft_strncmp(op, "rra", 3) || !ft_strncmp(op, "rrr", 3))
		ft_lstrev(lst1);
	if (!ft_strncmp(op, "rrb", 3) || !ft_strncmp(op, "rrr", 3))
		ft_lstrev(lst2);
	if (i == 2)
	{
		if (!ft_strncmp(op, "ra", 2) || !ft_strncmp(op, "rr", 2))
			ft_lstrot(lst1);
		if (!ft_strncmp(op, "rb", 2) || !ft_strncmp(op, "rr", 2))
			ft_lstrot(lst2);
	}
	if (!ft_strncmp(op, "sa", 2) || !ft_strncmp(op, "ss", 2))
		ft_lstswp(lst1);
	if (!ft_strncmp(op, "sb", 2) || !ft_strncmp(op, "ss", 2))
		ft_lstswp(lst2);
	if (!ft_strncmp(op, "pa", 2))
		ft_lstpush(lst1, lst2);
	if (!ft_strncmp(op, "pb", 2))
		ft_lstpush(lst2, lst1);
	ft_put_op(op, l_op);
}
