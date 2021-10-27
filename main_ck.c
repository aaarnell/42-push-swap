/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ck.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarnell <aarnell@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 19:44:26 by aarnell           #+#    #+#             */
/*   Updated: 2021/10/27 23:01:06 by aarnell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_chkstr(char *dst, char *src)
{
	int i;
	int ch;

	ch = 0;
	while (dst)
	{
		i = 0;
		while (src[i])
		{
			if (*dst == src[i])
				ch = 1;
			i++;
		}
		if (!ch)
			return (0);
		dst++;
	}
	return (1);
}

static int ft_dtops_swp(t_vrb *vr, char *str)
{
	int i;
	enum e_Ops op;

	i = ft_strlen(str) - 1;
	op = PA;
	if ((i == 1 || i == 2) && ft_chkstr(str, "abprs\0") \
		&& ((ft_strchr("pr\0", str[0]) && ft_strchr("abr\0", str[i])) \
		|| (i == 1 && str[0] == 's' && ft_strchr("abs\0", str[i]))) \
		&& (i == 1 || (i == 2 && str[1] == 'r')))
	{
		if (str[0] != 'p')
			op += 2;
		if (str[0] != 'r')
			op += 6;
		if (i == 2)
			op += 3;
		if (str[i] != 'a')
			op += 1;
		if (str[i] != 'b')
			op += 1;
		ft_pswp(vr, op);
		return (0);
	}
	return (1);
}

static int ft_gnl_dtops_swp(t_vrb *vr)
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

static int ft_chord_st1(t_vrb *vr)
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
