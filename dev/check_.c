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

static int chk_sts(t_vrb *vr)
{
	t_list *t_st1;
	t_list *t_st2;
	t_list *t_st_1;
	t_list *t_st_2;

	t_st1 = vr->st1;
	t_st2 = vr->st2;
	t_st_1 = vr->st_1;
	t_st_2 = vr->st_2;

	while (t_st1 || t_st2 || t_st_1 || t_st_2)
	{
		if ((t_st1 && t_st_1 && *(int *)(t_st1->content) != *(int *)(t_st_1->content)) \
			|| (t_st1 && !t_st_1) || (!t_st1 && t_st_1))
		{
			vr->n_st = 1;
			if (t_st1)
				vr->mstk1 = *(int *)(t_st1->content);
			else
				vr->mstk1 = 0;
			if (t_st_1)
				vr->mstk2 = *(int *)(t_st_1->content);
			else
				vr->mstk2 = 0;
			return (1);
		}
		if (t_st1 && t_st_1)
		{
			t_st1 = t_st1->next;
			t_st_1 = t_st_1->next;
		}

		if ((t_st2 && t_st_2 && *(int *)(t_st2->content) != *(int *)(t_st_2->content)) \
			|| (t_st2 && !t_st_2) || (!t_st2 && t_st_2))
		{
			vr->n_st = 2;
			if (t_st2)
				vr->mstk1 = *(int *)(t_st2->content);
			else
				vr->mstk1 = 0;
			if (t_st_2)
				vr->mstk2 = *(int *)(t_st_2->content);
			else
				vr->mstk2 = 0;
			return (1);
		}
		if (t_st2 && t_st_2)
		{
			t_st2 = t_st2->next;
			t_st_2 = t_st_2->next;
		}
	}
	return (0);
}

void chk_op(t_vrb *vr, enum Ops *op)
{
	enum Ops l_op;

	l_op = NaN;
	ft_pswp(&vr->st_1, &vr->st_2, op);
	if (!chk_sts(vr))
		ft_put_op4_2(op, &l_op);
	else
	{
		//вывести сообщение ОШИБКААААААА
		ft_putstr_fd("ОШИБКА в операции: \t", 1);
		//вывести операцию с ошибкой
		ft_put_op4_2(op, &l_op);
		//вывести контент, который с ошибкой
		ft_putstr_fd("Ошибка в стеке: \t", 1);
		ft_putnbr_fd(vr->n_st, 1);
		write(1, "\n", 1);
		ft_putstr_fd("Не совпадают элементы: \t", 1);
		ft_putnbr_fd(vr->mstk1, 1);
		write(1, "\t", 1);
		ft_putnbr_fd(vr->mstk2, 1);
		write(1, "\n", 1);
		//вывести стеки
		wr_prl_4st(4, vr->st1, vr->st2, vr->st_1, vr->st_2);
		//остановить программу
		exit(0);
	}
}
