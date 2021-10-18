#include "push_swap.h"

int main(int argc, char **argv)
{
	//сделать проверку аргументов на отношение к целым числам
	//сделать проверку числа аргументов если 1, то аргументов нет, если 2, то вернуть то, что есть
	//проверка дубликатов
	//проверка на символы
	t_list *tmp;
	t_vrb vr;

	tmp = NULL;
	if (ft_chknbr(argv) || ft_chkdup(argv) || ft_chkmnxint(argv))
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	//if (argc == 2)
		//argv = ft_split(*(argv + 1), " ");
	vr.st1 = ft_crtlst(argv);
	vr.st2 = NULL;
	if (argc == 2)
		tmp = vr.st1;
	else if (argc <= 4)
		tmp = srt_3itm(&vr);
	else if (argc <= 7)
		tmp = srt_6itm(&vr);
	else
		tmp = srt100(&vr);

	//printf("\n");
	/*
	printf("Результат st1: ");
	while (tmp)
	{
		printf("%d ", *(int *)(tmp->content));
		tmp = tmp->next;
	}
	printf("\n");
	*/
	/*printf("Результат st_1: ");
	while (vr.st_1)
	{
		printf("%d ", *(int *)(vr.st_1->content));
		vr.st_1 = vr.st_1->next;
	}
	printf("\n");*/
	ft_lstclear(&vr.st1, free);
	return (0);
}
