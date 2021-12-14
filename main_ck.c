/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ck.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarnell <aarnell@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 19:44:26 by aarnell           #+#    #+#             */
/*   Updated: 2021/12/08 20:08:56 by aarnell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_chkstr(char *src)
{
	if (!ft_strncmp(src, "pa", 2) && ft_strlen(src) == 2)
		return (PA);
	else if (!ft_strncmp(src, "pb", 2) && ft_strlen(src) == 2)
		return (PB);
	else if (!ft_strncmp(src, "ra", 2) && ft_strlen(src) == 2)
		return (RA);
	else if (!ft_strncmp(src, "rb", 2) && ft_strlen(src) == 2)
		return (RB);
	else if (!ft_strncmp(src, "rr", 2) && ft_strlen(src) == 2)
		return (RR);
	else if (!ft_strncmp(src, "rra", 3) && ft_strlen(src) == 3)
		return (RRA);
	else if (!ft_strncmp(src, "rrb", 3) && ft_strlen(src) == 3)
		return (RRB);
	else if (!ft_strncmp(src, "rrr", 3) && ft_strlen(src) == 3)
		return (RRR);
	else if (!ft_strncmp(src, "sa", 2) && ft_strlen(src) == 2)
		return (SA);
	else if (!ft_strncmp(src, "sb", 2) && ft_strlen(src) == 2)
		return (SB);
	else if (!ft_strncmp(src, "ss", 2) && ft_strlen(src) == 2)
		return (SS);
	return (NaN);
}

static int	ft_dtops_swp(t_vrb *vr, char *str)
{
	int	i;

	i = ft_chkstr(str);
	if (i)
	{
		ft_pswp(vr, i, 0);
		return (0);
	}
	return (1);
}

static int	ft_gnl_dtops_swp(t_vrb *vr)
{
	int		i;
	char	ch;
	char	*bf;

	i = 0;
	bf = malloc(100);
	while (read(0, &ch, 1) > 0)
	{
		if (ch == '\n')
		{
			bf[i] = '\0';
			i = 0;
			if (ft_dtops_swp(vr, bf))
			{
				free(bf);
				return (1);
			}
		}
		else
			bf[i++] = ch;
	}
	free(bf);
	return (0);
}

static int	ft_chord_st1(t_vrb *vr)
{
	srch_mnavmx(vr->st1, &vr->min, &vr->avg, &vr->max);
	if (vr->min == *(int *)(vr->st1->content) && ft_chkord(vr->st1))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vrb	vr;

	(void)argc;
	if (ft_chknbr(argv) || ft_chkdup(argv) || ft_chkmnxint(argv))
		write(1, "Error\n", 6);
	else
	{
		vr.st1 = ft_crtlst(argv);
		vr.st2 = NULL;
		if (vr.st1)
		{
			if (ft_gnl_dtops_swp(&vr))
				write(1, "Error\n", 6);
			else if (vr.st2 || !ft_chord_st1(&vr))
				write(1, "KO\n", 3);
			else
				write(1, "OK\n", 3);
		}
		if (vr.st1)
			ft_lstclear(&vr.st1, free);
		if (vr.st2)
			ft_lstclear(&vr.st2, free);
	}
	return (0);
}
