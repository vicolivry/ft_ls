/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/07 15:36:04 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/09 17:59:10 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_ls(const char *file, t_pars_ls strc)
{
	strc.data = parse_data_ls(file, strc);
	while (strc.data->next)
	{
		if (ft_strcmp(strc.data->dir->d_name, ".")
				&& ft_strcmp(strc.data->dir->d_name, ".."))
		{
			if (strc.l)
			{
				ft_printf("%s  %2d %s  %s %6d %s ", strc.data->chmod, strc.data->nlnk,
						strc.data->pwd, strc.data->gp, strc.data->size, strc.data->date);
				ft_printf("%-17s\n", strc.data->name);
			}
		}
		strc.data = strc.data->next;
	}
	return (0);
}

int	main(int ac, const char **av)
{
	int			i;
	int			j;
	t_pars_ls	strc;

	j = 0;
	i = ac - 1;
	strc = init_pars_ls(strc);
	if (ac == 1)
		ft_ls(".", strc);
	else
	{
		while (av[++j] && av[j][0] == '-' && j <= ac)
			if (!(parse_ls(&strc, av[j])))
				return (1);
		if (j == ac)
		{
			if (!strc.rr)
				ft_ls(".", strc);
		}
		else
			while (i-- >= j)
				if (!strc.rr)
					ft_ls(av[i], strc);
	}
	return (0);
}
