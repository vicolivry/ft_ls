/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/07 15:36:04 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/14 11:50:30 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_ls(const char *file, t_pars_ls *strc)
{
	t_dir		*dp;
	DIR			*dirp;
	t_data_ls	*tmp;
	char		*str;
	static int	i = 0;

	tmp = strc->data;
	if ((dirp = opendir(file)) != NULL)
	{
	while ((dp = readdir(dirp)) != NULL)
	{
		tmp->dir = dp;
		str = ft_strjoin(file, "/");
		tmp->path = ft_strdup(str);
		ft_memdel((void**)&str);
		tmp = parse_data_ls(tmp, *strc);
		maxlen(strc, tmp);
		if (tmp->next == NULL)
			tmp->next = new_data_ls();
		tmp = tmp->next;
	}
	closedir(dirp);
	}
	else
	{
		if (i)
		{
			ft_putchar('\n');
			ft_printf("%s:\n", file);
		}
		ft_putstr_fd("ft_ls: ", 2);
		if (file[ft_strlen(file) - 1] != '/')
			ft_putstr_fd(file, 2);
		ft_putstr_fd(": Permission denied\n", 2);
		tmp->next = NULL;
	}
	i = 1;
}

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
		while (av[++j] && av[j][0] == '-'  && av[j][1] && j <= ac)
			if (!(parse_ls(&strc, av[j])))
				return (-1);
		if (j == ac)
		{
			strc.rr ? ft_ls_r(".", &strc) : ft_ls(".", &strc);
			display(strc, strc.data);
			free_ls(strc.data);
		}
		else
			multifile(ac, j, av, strc);
	}
	return (0);
}
