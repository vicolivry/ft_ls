/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/07 15:36:04 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/26 18:11:19 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_ls2(const char *file, t_data_ls *tmp, t_pars_ls *strc)
{
	if (strc->rc)
	{
		ft_putchar('\n');
		ft_printf("%s:\n", file);
	}
	ft_putstr_fd("ft_ls: ", 2);
	if (file[ft_strlen(file) - 1] != '/')
		ft_putstr_fd(file, 2);
	ft_putstr_fd(": Permission denied\n", 2);
	tmp->next = NULL;
	strc->rc = 1;
}

void		ft_ls(const char *file, t_pars_ls *strc)
{
	t_dir		*dp;
	DIR			*dirp;
	t_data_ls	*tmp;
	char		*str;

	tmp = new_data_ls();
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
			strc->r && !strc->t ? rev_ascii_sort(&strc->data, tmp) :
				ascii_sort(&strc->data, tmp);
			tmp = new_data_ls();
		}
		if (strc->t)
			insert_time(&strc->data, *strc);
		closedir(dirp);
		ft_memdel((void**)&tmp);
	}
	else
		ft_ls2(file, tmp, strc);
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
		while (av[++j] && av[j][0] == '-' && av[j][1] && j <= ac)
			if (!(parse_ls(&strc, av[j])))
				return (-1);
		if (j == ac)
			no_arg_ls(strc);
		else
			multifile(ac, j, av, strc);
	}
	return (0);
}
