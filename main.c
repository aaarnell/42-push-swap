/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarnell <aarnell@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 22:26:53 by aarnell           #+#    #+#             */
/*   Updated: 2021/10/18 22:27:02 by aarnell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_vrb	vr;

	if (ft_chknbr(argv) || ft_chkdup(argv) || ft_chkmnxint(argv))
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	vr.st1 = ft_crtlst(argv);
	vr.st2 = NULL;
	if (argc > 2)
	{
		if (argc <= 4)
			srt_3itm(&vr);
		else if (argc <= 7)
			srt_6itm(&vr);
		else
			srt100(&vr);
	}
	ft_lstclear(&vr.st1, free);
	return (0);
}
