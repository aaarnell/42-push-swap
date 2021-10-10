#include "push_swap.h"

//Функция для печати цифры из контента. Удалить при публикации
void wr_wr(void *cnt)
{
	ft_putnbr_fd(*(int *)cnt, 1);
	write(1, " ", 1);
}
//Функция для печати цифры из контента. Удалить при публикации
//Функция для печати контента стеков. Удалить при публикации
void wr_prl_st(t_list *lst1, t_list *lst2)
{
	write(1, "st1\t\t", 5);
	write(1, "st2\n", 4);
	while (lst1 || lst2)
	{
		if (lst1)
		{
			ft_putnbr_fd(*(int *)(lst1->content), 1);
			lst1 = lst1->next;
		}
		else
			write(1, "emp", 3);
		write(1, "\t\t", 2);
		if (lst2)
		{
			ft_putnbr_fd(*(int *)(lst2->content), 1);
			lst2 = lst2->next;
		}
		else
			write(1, "emp", 3);
		write(1, "\n", 1);
	}
}
//Функция для печати контента стеков. Удалить при публикации
//Функция для печати контента стека. Удалить при публикации
void wr_st(t_list *lst)
{
	while (lst)
	{
		ft_putnbr_fd(*(int *)(lst->content), 1);
		write(1, " ", 1);
		lst = lst->next;
	}
	write(1, "\t", 1);
}
//Функция для печати контента стека. Удалить при публикации
/*
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
	printf("Операция %d\n", ++cnt);
}
*/
