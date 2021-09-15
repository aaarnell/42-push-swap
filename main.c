#include "push_swap.h"

int main(int argc, char **argv)
{
	//сделать проверку аргументов на отношение к целым числам
	//сделать проверку числа аргументов если 1, то аргументов нет, если 2, то вернуть то, что есть
	t_list *first;
	t_list *tmp;
	int i;
	i = 0;
	if (argc > 1) i = 0;
	first = ft_crtlst(argv);
	if (argc == 4)
		tmp = sort1(first);
	else
		tmp = sort3(first);
	printf("\n");
	while (tmp)
	{
		printf("%d. content '%d' \n", i, *(int *)(tmp->content));
		tmp = tmp->next;
		i++;
	}
	return (0);
}
