/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarnell <aarnell@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 21:53:29 by aarnell           #+#    #+#             */
/*   Updated: 2021/10/18 22:16:00 by aarnell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstswp(t_list **lst)
{
	t_list	*tmp;

	if (!lst || !(*lst)->next)
		return ;
	tmp = (*lst)->next;
	(*lst)->next = tmp->next;
	tmp->next = *lst;
	*lst = tmp;
}

void	ft_lstpush(t_list **lst1, t_list **lst2)
{
	t_list	*tmp;

	if (!lst2)
		return ;
	tmp = (*lst2)->next;
	(*lst2)->next = *lst1;
	*lst1 = *lst2;
	*lst2 = tmp;
}

void	ft_lstrot(t_list **lst)
{
	t_list	*tmp;

	if (!lst || !(*lst)->next)
		return ;
	tmp = (*lst)->next;
	ft_lstadd_back(lst, *lst);
	(*lst)->next = NULL;
	*lst = tmp;
}

void	ft_lstrev(t_list **lst)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!lst || !(*lst)->next)
		return ;
	tmp = ft_lstlast(*lst);
	tmp2 = *lst;
	while (tmp2->next != tmp)
		tmp2 = tmp2->next;
	tmp2->next = NULL;
	ft_lstadd_front(lst, tmp);
}

void	ft_pswp(t_vrb *vr, enum e_Ops op)
{
	if (op == RRA || op == RRR)
		ft_lstrev(&(vr->st1));
	if (op == RRB || op == RRR)
		ft_lstrev(&(vr->st2));
	if (op == RA || op == RR)
		ft_lstrot(&(vr->st1));
	if (op == RB || op == RR)
		ft_lstrot(&(vr->st2));
	if (op == SA || op == SS)
		ft_lstswp(&(vr->st1));
	if (op == SB || op == SS)
		ft_lstswp(&(vr->st2));
	if (op == PA)
		ft_lstpush(&(vr->st1), &(vr->st2));
	if (op == PB)
		ft_lstpush(&(vr->st2), &(vr->st1));
	ft_putsop(&op);
}
