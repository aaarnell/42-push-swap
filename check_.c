#include "push_swap.h"

static void wr_cnt(t_list **lst)
{
	if (lst)
	{
		ft_putnbr_fd(*(int *)((*lst)->content), 1);
		*lst = (*lst)->next;
	}
	else
		write(1, "emp", 3);
}

static void wr_prl_4st(unsigned num, ...) //для параллельной печати по два стека
{
	va_list args;
	t_list *lst[num];
	unsigned i;

	i = 0;
	va_start(args, num);
	while (num > i++)
		lst[i] = va_arg(args, t_list *);
	va_end(args);

	write(1, "Orig\t\t\t\t\t", 9);
	write(1, "Copy\n", 5);
	write(1, "st1\t\t", 5);
	write(1, "st2\t\t", 4);
	write(1, "st1\t\t", 5);
	write(1, "st2\n", 4);
	while (1)
	{
		i = num;
		for (unsigned c = num; c; c--)
			if (!lst[c])
				i--;
		if (!i)
			return ;
		for (unsigned c = num; c; c--)
		{
			wr_cnt(&lst[c]);
			write(1, "\t\t", 2);
		}
		write(1, "\n", 1);
	}
}

static void ft_pswp(t_list **lst1, t_list **lst2, enum Ops *op)
{
	if (*op == RRA || *op == RRR)
		ft_lstrev(lst1);
	if (*op == RRB || *op == RRR)
		ft_lstrev(lst2);
	if (*op == RA || *op == RR)
		ft_lstrot(lst1);
	if (*op == RB || *op == RR)
		ft_lstrot(lst2);
	if (*op == SA || *op == SS)
		ft_lstswp(lst1);
	if (*op == SB || *op == SS)
		ft_lstswp(lst2);
	if (*op == PA)
		ft_lstpush(lst1, lst2);
	if (*op == PB)
		ft_lstpush(lst2, lst1);
}

static int chk_sts(t_list *lst1, t_list *lst2, t_list *st1, t_list *st2)
{
	while (lst1 || lst2 || st1 || st2)
	{
		if ((lst1 && st1 && *(int *)(lst1->content) != *(int *)(st1->content)) \
			|| (lst1 && !st1) || (!lst1 && st1))
		{
			vr.n_st = 1;
			if (lst1)
				vr.mstk1 = *(int *)(lst1->content);
			else
				vr.mstk1 = 0;
			if (st1)
				vr.mstk2 = *(int *)(st1->content);
			else
				vr.mstk2 = 0;
			return (1);
		}
		lst1 = lst1->next;
		st1 = st1->next;

		if ((lst2 && st2 && *(int *)(lst2->content) != *(int *)(st2->content)) \
			|| (lst2 && !st2) || (!lst2 && st2))
		{
			vr.n_st = 2;
			if (lst2)
				vr.mstk1 = *(int *)(lst2->content);
			else
				vr.mstk1 = 0;
			if (st2)
				vr.mstk2 = *(int *)(st2->content);
			else
				vr.mstk2 = 0;
			return (1);
		}
		lst2 = lst2->next;
		st2 = st2->next;
	}
	return (0);
}

void chk_op(t_list *lst1, t_list *lst2, enum Ops *op)
{
	ft_pswp(&vr.st_1, &vr.st_2, op);
	if (!chk_sts(lst1, lst2, vr.st_1, vr.st_2))
		ft_put_op4_2(op, NaN);
	else
	{
		//вывести сообщение ОШИБКААААААА
		ft_putstr_fd("ОШИБКА в операции: \t", 1);
		//вывести операцию с ошибкой
		ft_put_op4_2(op, NaN);
		//вывести контент, который с ошибкой
		ft_putstr_fd("Ошибка в стеке: \t", 1);
		ft_putnbr_fd(vr.n_st, 1);
		write(1, "\n", 1);
		ft_putstr_fd("Не совпадают элементы: \t", 1);
		ft_putnbr_fd(vr.mstk1, 1);
		write(1, "\t", 1);
		ft_putnbr_fd(vr.mstk2, 1);
		write(1, "\n", 1);
		//вывести стеки
		wr_prl_4st(4, lst1, lst2, vr.st_1, vr.st_2);
		//остановить программу
		exit(0);
	}
}
