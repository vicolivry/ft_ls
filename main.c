/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/07 15:36:04 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/06 17:50:02 by volivry     ###    #+. /#+    ###.fr     */
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
}

int		main(int ac, const char **av)
{
	int			j;
	t_pars_ls	strc;

	j = 0;
	strc = init_pars_ls();
	if (ac == 1)
	{
		strc.rr ? ft_ls_r(".", strc) : ft_ls(".", strc);
		display(strc, strc.data);
		free_ls(strc.data);
	}
	else
	{
		while (av[++j] && av[j][0] == '-' && j <= ac)
			if (!(parse_ls(&strc, av[j])))
				return (-1);
		if (j == ac)
		{
			strc.rr ? ft_ls_r(".", strc) : ft_ls(".", strc);
			maxlen(&strc, strc.data);
			display(strc, strc.data);
			free_ls(strc.data);
		}
		else
			multifile(ac, j, av, strc);
	}
	return (0);
}
