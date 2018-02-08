/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/07 15:36:04 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/08 17:57:02 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_ls(const char *file, t_pars_ls pars)
{
	t_data_ls	*data;

	data = new_data_ls("");
	if (!pars.l)
		s_fmt(file, pars, data);
	else
		l_fmt(file, pars, data);
	return (0);
}

int	main(int ac, const char **av)
{
	int			i;
	int			j;
	t_pars_ls	pars;

	j = 0;
	i = ac - 1;
	pars = init_pars_ls(pars);
	if (ac == 1)
		ft_ls(".", pars);
	else
	{
		while (av[++j] && av[j][0] == '-' && j <= ac)
			if (!(parse_ls(&pars, av[j])))
				return (1);
		if (j == ac)
			ft_ls(".", pars);
		else
			while (i >= j)
				ft_ls(av[i--], pars);
	}
	return (0);
}
