#include "push_swap.h"

int main(int argc, char **argv)
{
	//сделать проверку аргументов на отношение к целым числам
	//сделать проверку числа аргументов если 1, то аргументов нет, если 2, то вернуть то, что есть
	t_list *first;
	t_list *tmp;
	t_vrb vr;

	tmp = NULL;
	if (argc > 1)
		tmp = NULL;
	first = ft_crtlst(argv);
	vr.st1 = first;
	vr.st2 = NULL;
	vr.st_1 = ft_crtlst(argv);
	vr.st_2 = NULL;
	if (argc == 2)
		tmp = first;
	else if (argc <= 4)
		tmp = srt_3itm(first);
	else if (argc <= 7)
		tmp = srt_6itm(first);
	else
		tmp = srt100t_4(&vr);
	//printf("\n");
	printf("Результат: ");
	while (tmp)
	{
		printf("%d ", *(int *)(tmp->content));
		tmp = tmp->next;
	}
	printf("\n");
	return (0);
}
