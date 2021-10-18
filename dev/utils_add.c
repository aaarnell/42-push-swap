#include "push_swap.h"

static char *OpNms[] = {
	"NaN",
	"pa\n",
	"pb\n",
	"ra\n",
	"rb\n",
	"rr\n",
	"rra\n",
	"rrb\n",
	"rrr\n",
	"sa\n",
	"sb\n",
	"ss\n"
};

void srch_minmax(t_list *lst, int *min, int *max)
{
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
}

void srch_mnavmx(t_list *lst, int *min, int *avg, int *max)
{
	int rem;

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

int chk_ord(t_list *lst)
{
	int i;

	i = *(int *)(lst->content);
	while (lst && lst->next)
	{
		lst = lst->next;
		if (i > *(int *)(lst->content))
			return (0);
		i = *(int *)(lst->content);
	}
	return (1);
}

int cnt_chs(t_list *lst)
{
	int i;

	i = 0;
	while (lst && lst->next)
	{
		if (*(int *)(lst->content) > *(int *)((lst->next)->content))
			i++;
		lst = lst->next;
	}
	return (i);
}

t_list *ft_crtlst(char **argv)
{
	int i;
	int *cnt;
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

void ft_put_op4_2(enum Ops *op, enum Ops *l_op)
{
/*
	if (*l_op == NaN)
		*l_op = *op;
	else if ((*l_op == SA && *op == SB) || (*l_op == SB && *op == SA))
	{
		ft_putstr_fd("ss\n", 1);
		*l_op = NaN;
	}
	else if ((*l_op == RA && *op == RB) || (*l_op == RB && *op == RA))
	{
		ft_putstr_fd("rr\n", 1);
		*l_op = NaN;
	}
	else if ((*l_op == RRA && *op == RRB) || (*l_op == RRB && *op == RRA))
	{
		ft_putstr_fd("rrr\n", 1);
		*l_op = NaN;
	}
	else
	{
		ft_putstr_fd(OpNms[*l_op], 1);
		//write(1, "\n", 1);
		*l_op = *op;
	}
*/
	ft_putstr_fd(OpNms[*op], 1);
	//if (*op == RRA || *op == RRB || *op == RRR)
	//	write(1, OpNms[*op], 4);
	//else
	//	write(1, OpNms[*op], 3);
	*l_op = NaN;
}

void ft_put_op4_3(enum Ops *op)
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
