#include "push_swap.h"

t_list *srt100t_4(t_vrb *vr)
{
	int sz1;

	if (!vr->st1 || !vr->st1->next)
		return (vr->st1);
	sz1 = ft_lstsize(vr->st1);
	vr->ln1 = sz1;
	srch_mnavmx(vr->st1, &vr->min, &vr->avg, &vr->max);
	while (sz1 > 2)
	{
		if (vr->min != *(int *)(vr->st1->content) && vr->max != *(int *)(vr->st1->content))
		{
			ft_pushswap4_3(vr, PB);
			sz1--;
			if (*(int *)(vr->st2->content) >= vr->avg)
				ft_pushswap4_3(vr, RB);
			if (sz1 == 2 && vr->min == *(int *)(vr->st1->content))
				ft_pushswap4_3(vr, RA);
		}
		else
			ft_pushswap4_3(vr, RA);
	}

/*	while (sz1 > 2)
	{
		if (vr->min != *(int *)(vr->st1->content) && vr->max != *(int *)(vr->st1->content))
		{
			if (!vr->st2)
			{
				ft_pushswap4_3(vr, PB);
				sz1--;
			}
			else if (*(int *)(vr->st1->content) > *(int *)(vr->st2->content) \
					&& (!vr->st2->next || tmx == *(int *)(vr->st2->content)))
			{
				tmx = *(int *)(vr->st1->content);
				ft_pushswap4_3(vr, PB);
wr_prl_st(vr->st1, vr->st2);
write(1, "\n", 1);
				sz1--;
				ft_pushswap4_3(vr, SB);
			}
			else if (*(int *)(vr->st1->content) <= *(int *)(vr->st2->content))
			{
				ft_pushswap4_3(vr, PB);
				sz1--;
			}
			else
				ft_pushswap4_3(vr, RB);
			if (sz1 == 2 && vr->min == *(int *)(vr->st1->content))
				ft_pushswap4_3(vr, RA);
		}
		else
			ft_pushswap4_3(vr, RA);
wr_prl_st(vr->st1, vr->st2);
write(1, "\n", 1);
	}
wr_prl_st(vr->st1, vr->st2);
write(1, "\n", 1);*/
/*
	while (sz1 > 2)
	{
		if (vr->min != *(int *)(vr->st1->content) && vr->max != *(int *)(vr->st1->content))
		{
			ft_pushswap4_3(vr, PB);
			sz1--;
//wr_prl_st(vr->st1, vr->st2);
//write(1, "\n", 1);
			if (vr->st2->next && *(int *)(vr->st2->content) < *(int *)(vr->st2->next->content))
				ft_pushswap4_3(vr, RB);
			if (sz1 == 2 && vr->min == *(int *)(vr->st1->content))
				ft_pushswap4_3(vr, RA);
		}
		else
			ft_pushswap4_3(vr, RA);
//wr_prl_st(vr->st1, vr->st2);
//write(1, "\n", 1);
	}
//wr_prl_st(vr->st1, vr->st2);
//write(1, "\n", 1);
*/


/*
	//Беспорядочный сброс в стек 2 всего из стека 1, кроме мин и макс
	while (sz1 > 2)
	{
		if (vr->min != *(int *)(vr->st1->content) && vr->max != *(int *)(vr->st1->content))
		{
			ft_pushswap4_3(vr, PB);
			sz1--;
			if (sz1 == 2 && vr->min == *(int *)(vr->st1->content))
				ft_pushswap4_3(vr, RA);
		}
		else
			ft_pushswap4_3(vr, RA);
	}
*/

/*
	//Сброс с упорядочиванием в стек 2 всего из стека 1, кроме мин и макс
	ft_chk_mv1_2(vr);
	if (vr->min == *(int *)(vr->st1->content))
		ft_pushswap4_3(vr, RA);
*/


/*
	sz1 = 0;
	fx = *(int *)(vr->st1->content);
	if (ft_cnt_dp(vr->st1, vr->min, 2) < ft_cnt_dp(vr->st1, vr->max, 2))
	{
		sz1 = 1;
		fx = vr->min;
	}
	//wr_prl_st(vr->st1, vr->st2);
	//write(1, "\n", 1);
	while(1)
	{
		if (vr->min == *(int *)(vr->st1->content) && chk_ord(vr->st1))
		{
			ft_pushswap4_3(vr, RRA);
			break ;
		}
		if (vr->min == *(int *)(vr->st1->content) && (sz1 == 1 || fx > vr->min))
		{
			sz1 = 0;
			fx = vr->min;
		}
		if (sz1 == 1)
			ft_pushswap4_3(vr, PB);
		else //if (vr->min != *(int *)(vr->st1->content) && vr->max != *(int *)(vr->st1->content)) //&& sz == 0
		{
			if (fx <= *(int *)(vr->st1->content) ) // && sz == 0 && vr->min != *(int *)(vr->st1->content) && vr->max != *(int *)(vr->st1->content)
			{
				fx = *(int *)(vr->st1->content);
				ft_pushswap4_3(vr, RA);
			}
			else // if (sz == 0 && vr->min != *(int *)(vr->st1->content) && vr->max != *(int *)(vr->st1->content) && fx > *(int *)(vr->st1->content))
				ft_pushswap4_3(vr, PB);
		}
		//else // if (sz == 0 && (vr->min == *(int *)(vr->st1->content) || vr->max == *(int *)(vr->st1->content)))
			//ft_pushswap4_3(vr, RA);
		//wr_prl_st(vr->st1, vr->st2);
		//write(1, "\n", 1);
	}
*/
	//wr_prl_st(vr->st1, vr->st2);
	//write(1, "\n", 1);
	//wr_prl_st(st1, st2);
	//write(1, "\n", 1);
	//вернем все элементы обратно в 1 стек
	//ft_chk_mv(&(vr->st1), &(vr->st2), &l_op);

	//Поиск оптимального элемента для переноса из стека 2 в стек 1
	ft_chk_mv2(vr);
	//wr_prl_st(st1, st2);
	//write(1, "\n", 1);

	//прокрутим стек1 до min
	if (vr->min != *(int *)(vr->st1->content))
	{
		sz1 = ft_cnt_dp(vr->st1, vr->min, 2);
		if ((ft_lstsize(vr->st1) - sz1) < sz1)
		{
			sz1 = ft_lstsize(vr->st1) - sz1;
			while (sz1--)
			{
				ft_pushswap4_3(vr, RRA);
				//wr_prl_st(st1, st2);
				//write(1, "\n", 1);
				//wr_2st_str(vr->st1, vr->st2);
			}
		}
		else
			while (sz1--)
			{
				ft_pushswap4_3(vr, RA);
				//wr_prl_st(st1, st2);
				//write(1, "\n", 1);
				//wr_2st_str(vr->st1, vr->st2);
			}
	}
	return (vr->st1);
}
