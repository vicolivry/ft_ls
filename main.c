/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/07 15:36:04 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/15 13:43:09 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int	main(int ac, const char **av)
{
	int			i;
	int			j;
	t_pars_ls	strc;

	j = 0;
	i = ac - 1;
	strc = init_pars_ls();
	if (ac == 1)
			ft_ls_r(".", strc);
	else
	{
		while (av[++j] && av[j][0] == '-' && j <= ac)
			if (!(parse_ls(&strc, av[j])))
				return (1);
		if (j == ac)
				ft_ls_r(".", strc);
		else
			while (i-- >= j)
					ft_ls_r(av[i], strc);
	}
	return (0);
}
