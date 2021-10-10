#include "push_swap.h"

static char *OpNms[] = {
	"NaN",
	"pa",
	"pb",
	"ra",
	"rb",
	"rr",
	"rra",
	"rrb",
	"rrr",
	"sa",
	"sb",
	"ss"
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
	if (*l_op == NaN)
		*l_op = *op;
	else if ((*l_op == SA && *op == SB) || (*l_op == SB && *op == SA))
	{
		ft_putstr_fd("ss\n\0", 1);
		*l_op = NaN;
	}
	else if ((*l_op == RA && *op == RB) || (*l_op == RB && *op == RA))
	{
		ft_putstr_fd("rr\n\0", 1);
		*l_op = NaN;
	}
	else if ((*l_op == RRA && *op == RRB) || (*l_op == RRB && *op == RRA))
	{
		ft_putstr_fd("rrr\n\0", 1);
		*l_op = NaN;
	}
	else
	{
		ft_putstr_fd(OpNms[*l_op], 1);
		write(1, "\n", 1);
		*l_op = *op;
	}
}
