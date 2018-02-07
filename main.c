/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/07 15:36:04 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/07 20:30:23 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static t_pars_ls	init_pars_ls(t_pars_ls pars)
{
	pars.l = 0;
	pars.r = 0;
	pars.rr = 0;
	pars.a = 0;
	pars.t = 0;
	return (pars);
}

static int			parse_ls(t_pars_ls *pars, const char *str)
{
	while (*str++)
	{
		if (!ft_strchr(FLAGS_LS, *str))
		{
			ft_printf("ls: illegal option -- %c", *str);
			ft_printf("\nusage: ls [%s] [file ...]\n", FLAGS_LS);
			return (0);
		}
		else
		{
			pars->l = ft_strchr(str, 'l') ? 1 : 0;
			pars->r = ft_strchr(str, 'r') ? 1 : 0;
			pars->rr = ft_strchr(str, 'R') ? 1 : 0;
			pars->a = ft_strchr(str, 'a') ? 1 : 0;
			pars->t = ft_strchr(str, 't') ? 1 : 0;
		}
	}
	return (1);
}

static int	ft_ls(const char *file, t_pars_ls pars, t_data_ls *data)
{
	if (!pars.l)
		s_fmt(file, pars, data);
	else
		l_fmt(file, pars,data);
	return (0);
}

int					main(int ac, const char **av)
{
	int			i;
	t_pars_ls	pars;
	t_data_ls	*data;

	data = new_data_ls("choin");
	ft_printf("%s\n%d\n\n", data->name, data->time);
	i = 1;
	if (ac == 1)
		ft_ls(".", pars, data);
	else
	{
		while (av[i++][0] == '-' && i < ac)
		{
			if (!(parse_ls(&pars, av[1])))
				return (1);
		}
	}
	return (0);
}
