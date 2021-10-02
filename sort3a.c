#include "push_swap.h"

t_list *sort3a(t_list *lst)
{
	t_list *st1;
	t_list *st2;
	int min;
	int max;
	int op;
	int i;
	int c; //для остановки при ошибке и бесконечном цикле

	c = 9 * ft_lstsize(lst);

	if (!lst || !lst->next)
		return (lst);
	op = 0;
	i = 0;
	st1 = lst;
	st2 = NULL;
	srch_minmax(lst, &min, &max);
	write(1, "start\t\t", 7);
	write(1, "st1: ", 5);
	wr_st(st1);
	write(1, "st2: ", 5);
	wr_st(st2);
	write(1, "\n\n", 1);
	while (1)
	{
		write(1, "Итерация ", 18);
		ft_putnbr_fd(i++, 1);
		write(1, "\t", 1);
		if (min == *(int *)(st1->content) && chk_ord(st1))
		{
			write(1, "\n", 1);
			break;
		}
		if (min != *(int *)(st1->content) && max != *(int *)(st1->content))
		{
			ft_pushswap(&st2, &st1, "pa");
			if (i%2)
				ft_pushswap(&st2, NULL, "sb");
			else
				ft_pushswap(&st2, NULL, "rb");
			op++;
		}
		else
			ft_pushswap(&st1, NULL, "ra");
		write(1, "st1: ", 5);
		wr_st(st1);
		write(1, "st2: ", 5);
		wr_st(st2);
		op++;
		write(1, "\tОпераций: ", 19);
		ft_putnbr_fd(op, 1);
		write(1, "\n\n", 2);
	}
	while (1)
	{
		write(1, "Итерация ", 18);
		ft_putnbr_fd(i++, 1);
		write(1, "\t", 1);
		if (min == *(int *)(st1->content) && !st2 && chk_ord(st1))
			break;
		if (st2 && *(int *)(st1->content) >= *(int *)(st2->content))
			ft_pushswap(&st1, &st2, "pa");
		else
			ft_pushswap(&st1, NULL, "ra");
		write(1, "st1: ", 5);
		wr_st(st1);
		write(1, "st2: ", 5);
		wr_st(st2);
		op++;
		write(1, "\tОпераций: ", 19);
		ft_putnbr_fd(op, 1);
		write(1, "\n\n", 2);
		if (i > c)	//остановка при бесконечном цикле
		{
			write(1, "err: i > c\n", 11);
			break;
		}
	}
	printf("i = %d\t", i);
	printf("op = %d\n", op);
	return (st1);
}
