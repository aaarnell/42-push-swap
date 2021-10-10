#include "push_swap.h"

int main(int argc, char **argv)
{
	//сделать проверку аргументов на отношение к целым числам
	//сделать проверку числа аргументов если 1, то аргументов нет, если 2, то вернуть то, что есть
	t_list *first;
	t_list *tmp;
	int i;

	i = 0;
	tmp = NULL;
	if (argc > 1)
		first = ft_crtlst(argv);
	if (argc == 2)
		tmp = first;
	else if (argc <= 4)
		tmp = srt_3itm(first);
	else if (argc <= 7)
		tmp = srt_6itm(first);
	else
		tmp = srt100t_4(first);
	//printf("\n");
	/*printf("Результат: ");
	while (tmp)
	{
		printf("%d ", *(int *)(tmp->content));
		tmp = tmp->next;
		i++;
	}
	printf("\n");*/
	return (0);
}
