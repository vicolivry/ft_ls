/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/07 15:36:04 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 11:42:44 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls(const char *file, t_pars_ls strc)
{
	t_dir		*dp;
	DIR			*dirp;
	t_data_ls	*tmp;

	tmp = strc.data;
	dirp = opendir(file);
	while ((dp = readdir(dirp)) != NULL)
	{
		tmp->dir = dp;
		tmp->path = ft_strjoin(file, "/");
		tmp = parse_data_ls(tmp);
		if (tmp->next == NULL)
			tmp->next = new_data_ls();
		tmp = tmp->next;
	}
	closedir(dirp);
	display(strc, strc.data);
}

int		main(int ac, const char **av)
{
	int			i;
	int			j;
	t_pars_ls	strc;

	j = 0;
	i = ac - 1;
	strc = init_pars_ls();
	if (ac == 1)
		strc.rr ? ft_ls_r(".", strc) : ft_ls(".", strc);
	else
	{
		while (av[++j] && av[j][0] == '-' && j <= ac)
			if (!(parse_ls(&strc, av[j])))
				return (-1);
		if (j == ac)
			strc.rr ? ft_ls_r(".", strc) : ft_ls(".", strc);
		else
		{
			if (!(strc.poly_arg = (char**)malloc(ac - j)))
				return (-1);
			while (i-- >= j)
				strc.rr ? ft_ls_r(av[i], strc) : ft_ls(av[i], strc);
		}
	}
	return (0);
}
