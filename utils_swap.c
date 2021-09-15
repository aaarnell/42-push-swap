#include "push_swap.h"

t_list *ft_lstswp(t_list *lst)	// Изменение первых двух элементов местами (sa/sb/ss)
{
	t_list *tmp;

	if (!lst || !lst->next)
		return (lst);
	tmp = lst->next;
	lst->next = tmp->next;
	tmp->next = lst;
	return (tmp);
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

t_list *ft_lstrot(t_list *lst)	//Перенос головы списка в его конец (ra/rb/rr)
{
	t_list *tmp;

	if (!lst || !lst->next)
		return (lst);
	tmp = lst->next;
	ft_lstadd_back(&lst, lst);
	lst->next = NULL;
	return (tmp);
}

t_list *ft_lstrev(t_list *lst)	//Перенос хвоста списка в голову (rra/rrb/rrr)
{
	t_list *tmp;
	t_list *tmp2;

	if (!lst || !lst->next)
		return (lst);
	tmp = ft_lstlast(lst);
	tmp2 = lst;
	while (tmp2->next != tmp)
		tmp2 = tmp2->next;
	tmp2->next = NULL;
	ft_lstadd_front(&lst, tmp);
	return (lst);
}
