/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/07 15:36:04 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/28 14:59:32 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void	no_arg_ls(t_pars_ls strc)
{
	strc.rr ? ft_ls_r(".", &strc) : ft_ls(".", &strc);
	display(strc, strc.data);
	free_ls(strc.data);
}

int			main(int ac, const char **av)
{
	int			j;
	t_pars_ls	strc;

	j = 0;
	strc = init_pars_ls();
	if (ac == 1)
		no_arg_ls(strc);
	else
	{
		while (av[++j] && av[j][0] == '-' && av[j][1] && j <= ac)
			if (!(parse_ls(&strc, av[j])))
				return (1);
		if (j == ac)
			no_arg_ls(strc);
		else
			multifile(ac, j, av, strc);
	}
	return (0);
}
