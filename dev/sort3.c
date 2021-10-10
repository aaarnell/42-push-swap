#include "push_swap.h"

t_list *sort3(t_list *lst)
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
			if (!st2 || *(int *)(st1->content) <= *(int *)(st2->content))
				ft_lstpush(&st2, &st1);
			else if (i%2)
			{
				ft_lstpush(&st2, &st1);
				ft_lstswp(&st2);
				op++;
			}
			else
			{
				ft_lstpush(&st2, &st1);
				ft_lstrot(&st2);
				op++;
			}
		}
		else
			ft_lstrot(&st1);
		//wr_prl_st(st1, st2);
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
			ft_lstpush(&st1, &st2);
		else
			ft_lstrot(&st1);
		//wr_prl_st(st1, st2);
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
