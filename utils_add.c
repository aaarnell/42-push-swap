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
	while (lst)
	{
		if (i > *(int *)(lst->content))
			return (0);
		i = *(int *)(lst->content);
		lst = lst->next;
	}
	return (1);
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
		//ft_putstr_fd(argv[i], 1);
		//write(1, " ", 1);
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
	write(1, "\n", 1);
	return (res);
}

