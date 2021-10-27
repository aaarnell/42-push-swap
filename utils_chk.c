/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_chk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarnell <aarnell@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 21:52:06 by aarnell           #+#    #+#             */
/*   Updated: 2021/10/26 19:55:03 by aarnell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_chkdup(char **argv)
{
	int	i;
	int	j;
	int	li;
	int	lj;

	i = 1;
	while (argv[i])
	{
		li = ft_strlen(argv[i]);
		j = i + 1;
		while (argv[j])
		{
			lj = ft_strlen(argv[j]);
			if (li == lj && NULL != ft_strnstr(argv[j], argv[i], lj))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_chknbr(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (j == 0 && argv[i][j] == '-')
				;
			else if (!ft_isdigit(argv[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	cng_var(char a, unsigned long *res, int *cnt_sin, int *emp)
{
	if (a >= '0' && a <= '9')
		*res = (*res * 10) + ((unsigned long)a - 48);
	if (a == ' ' || (a >= 9 && a <= 13))
		*emp = *emp + 1;
	if (a == '-')
	{
		*cnt_sin = *cnt_sin + 1;
		return (1);
	}
	if (a == '+')
		*cnt_sin = *cnt_sin + 1;
	return (0);
}

static int	ft_atoi_chk(const char *str)
{
	unsigned long	r;
	int				s;
	int				cs;
	int				e;

	r = 0;
	s = 1;
	cs = 0;
	e = 0;
	if (ft_strlen(str) > 11)
		return (1);
	while (*str)
	{
		if ((*str != ' ' && *str != '-' && *str != '+' && (*str < 9 || *str \
		> 13) && (*str < '0' || *str > '9')) || ((r != 0 || cs != 0) && (*str \
		== ' ' || *str == '-' || *str == '+' || (*str >= 9 && *str <= 13))))
			break ;
		if (cng_var(*str, &r, &cs, &e) == 1)
			s *= (-1);
		str++;
	}
	if ((r > INT_MAX && s > 0) || (r - 1 > INT_MAX && s < 0))
		return (1);
	return (0);
}

int	ft_chkmnxint(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_atoi_chk(argv[i]))
			return (1);
		i++;
	}
	return (0);
}
