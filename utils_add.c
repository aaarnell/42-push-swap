/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarnell <aarnell@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 21:53:48 by aarnell           #+#    #+#             */
/*   Updated: 2021/10/18 22:15:33 by aarnell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	srch_mnavmx(t_list *lst, int *min, int *avg, int *max)
{
	int	rem;

	*min = *(int *)(lst->content);
	*max = *(int *)(lst->content);
	while (lst)
	{
		if (*min > *(int *)(lst->content))
			*min = *(int *)(lst->content);
		if (*max < *(int *)(lst->content))
			*max = *(int *)(lst->content);
		lst = lst->next;
	}
	rem = *min % 2 + *max % 2;
	if (rem > 0)
		rem = 1;
	*avg = *min / 2 + *max / 2 + rem;
}

int	ft_chkord(t_list *lst)
{
	int	min;
	int	avg;
	int	max;

	srch_mnavmx(lst, &min, &avg, &max);
	while (lst && lst->next)
	{
		if (max == *(int *)(lst->content) && \
			min == *(int *)(lst->next->content))
			lst = lst->next;
		else if (*(int *)(lst->content) > *(int *)(lst->next->content))
			return (0);
		else
			lst = lst->next;
	}
	return (1);
}

t_list	*ft_crtlst(char **argv)
{
	int		i;
	int		*cnt;
	t_list	*res;
	t_list	*tmp;

	i = 1;
	res = NULL;
	while (argv[i])
	{
		cnt = malloc(sizeof(int));
		*cnt = ft_atoi(argv[i]);
		tmp = ft_lstnew(cnt);
		if (!tmp && res)
		{
			ft_lstclear(&res, free);
			return (NULL);
		}
		ft_lstadd_back(&res, tmp);
		i++;
	}
	return (res);
}

void	ft_putsop(enum e_Ops *op)
{
	if (*op == PA)
		ft_putstr_fd("pa\n", 1);
	else if (*op == PB)
		ft_putstr_fd("pb\n", 1);
	else if (*op == RA)
		ft_putstr_fd("ra\n", 1);
	else if (*op == RB)
		ft_putstr_fd("rb\n", 1);
	else if (*op == RR)
		ft_putstr_fd("rr\n", 1);
	else if (*op == RRA)
		ft_putstr_fd("rra\n", 1);
	else if (*op == RRB)
		ft_putstr_fd("rrb\n", 1);
	else if (*op == RRR)
		ft_putstr_fd("rrr\n", 1);
	else if (*op == SA)
		ft_putstr_fd("sa\n", 1);
	else if (*op == SB)
		ft_putstr_fd("sb\n", 1);
	else if (*op == SS)
		ft_putstr_fd("ss\n", 1);
}

int	ft_cnt_dp(t_list *lst, int elm, int n_st, int cnt)
{
	t_list	*tmp;

	tmp = ft_lstlast(lst);
	if (n_st == 1 && lst)
	{
		if (elm >= *(int *)(tmp->content) && elm <= *(int *)(lst->content))
			return (cnt);
		while (lst->next)
		{
			cnt++;
			if (elm > *(int *)(lst->content) && \
				elm <= *(int *)(lst->next->content))
				break ;
			lst = lst->next;
		}
	}
	if (n_st != 1 && lst)
	{
		while (lst && elm != *(int *)(lst->content))
		{
			cnt++;
			lst = lst->next;
		}
	}
	return (cnt);
}
