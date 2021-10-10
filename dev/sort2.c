#include "push_swap.h"

//Сортировка в одном стеке. Задействовано три операции:
//1. Свап первых двух элементов
//2. Свап первого элемента в конец
//3. Свап последнего в начало

t_list *sort2(t_list *lst)
{
	t_list *tmp;
	t_list *tmp2;
	int min;
	int max;
	int drc;
	int i;

	i = 0;
	if (!lst || !lst->next)
		return (lst);
	drc = 0;
	tmp = lst;
	tmp2 = lst->next;
	srch_minmax(lst, &min, &max);
	while (tmp && tmp2)//i != tmp->content)
	{
		if (min == *(int *)(tmp->content) && chk_ord(tmp))
			break;
		if (max == *(int *)(tmp->content))
			drc = 1;
		if (min == *(int *)(tmp->content))
			drc = 0;
		if (*(int *)(tmp->content) <= *(int *)(tmp2->content))
		{
			//printf("%d <= %d\t", (int)tmp->content, (int)tmp2->content);
			/*
			ft_lstiter(tmp, &wr_wr);
			write(1, "\n", 1);
			write(1, "tmp->content <= tmp2->content || max == *(int *)(tmp->content)\t", 30);
			write(1, "tmp->content = ", 15);
			*/
			//write(1, tmp->content, 2);
			/*
			wr_wr(tmp->content);
			write(1, "\t", 1);
			write(1, "tmp2->content = ", 16);
			*/
			//write(1, tmp2->content, 2);
			/*
			wr_wr(tmp2->content);
			write(1, "\t", 1);
			*/
			if (drc == 0)
			{
				ft_lstrot(&tmp);
				//write(1, "ra\n", 3);
			}
			else
			{
				ft_lstrev(&tmp);
				//write(1, "rra\n", 4);
			}
			i++;
			/*ft_lstiter(tmp, &wr_wr);
			write(1, "\n", 1);*/
		}
		else //if (*(int *)(tmp->content) > *(int *)(tmp2->content))	//можно не использовать условие if, т.к. только оно остается после проверки выше
		{
			//printf("%d > %d\t", (int)tmp->content, (int)tmp2->content);
			/*ft_lstiter(tmp, &wr_wr);
			write(1, "\n", 1);
			write(1, "tmp->content > tmp2->content\t", 30);
			write(1, "tmp->content = ", 15);*/
			//write(1, tmp->content, 2);
			/*wr_wr(tmp->content);
			write(1, "\t", 1);
			write(1, "tmp2->content = ", 16);*/
			//write(1, tmp2->content, 2);
			/*wr_wr(tmp2->content);
			write(1, "\t", 1);*/
			ft_lstswp(&tmp);
			//i = tmp2->content;
			//write(1, "sa\n", 3);
			i++;
			/*ft_lstiter(tmp, &wr_wr);
			write(1, "\n", 1);*/
		}
		tmp2 = tmp->next;
		//sleep(2);
	}
	ft_putnbr_fd(i, 1);
	return (tmp);
}
