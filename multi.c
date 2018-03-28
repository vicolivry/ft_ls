/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   multi.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/08 18:28:49 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/28 14:35:11 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void	multifile3(t_data_ls *tmp, t_pars_ls strc)
{
	while (tmp)
	{
		strc.rr ? ft_ls_r(tmp->name, &strc) : ft_ls(tmp->name, &strc);
		if (check_permission(tmp->name))
		{
			display(strc, strc.data);
			strc.rc = 1;
			free_ls(strc.data);
		}
		tmp = tmp->next;
		strc.data = NULL;
	}
}

static void	multifile2(t_data_ls *nofile, t_data_ls *nodir, t_data_ls *multi,
		t_pars_ls strc)
{
	t_data_ls *tmp;

	if (nofile)
		print_no_file(nofile);
	if (nodir)
		print_no_dir(nodir, &strc);
	tmp = multi;
	if (strc.t)
		insert_time(&nodir, strc);
	if (multi && multi->next && (!nofile || !nodir))
	{
		ft_printf("%s:\n", tmp->name);
		strc.rc = 0;
	}
	multifile3(tmp, strc);
	strc.data = new_data_ls();
	free_multi(nofile, nodir, multi, strc);
}

void		multifile(int ac, int j, const char **av, t_pars_ls strc)
{
	t_data_ls *multi;
	t_data_ls *tmp;
	t_data_ls *nofile;
	t_data_ls *nodir;

	multi = NULL;
	nofile = NULL;
	nodir = NULL;
	tmp = NULL;
	while (ac-- > j)
	{
		if (!check_exist(av[ac]))
			nofile = no_such_file(av[ac], nofile, &strc);
		else if (!check_dir(av[ac]))
			nodir = no_dir(av[ac], nodir, &strc);
		else
		{
			tmp = new_data_ls();
			tmp->name = ft_strdup(av[ac]);
			tmp = parse_multi_ls(tmp);
			strc.r && !strc.t ? rev_ascii_sort(&multi, tmp) :
				ascii_sort(&multi, tmp);
		}
	}
	multifile2(nofile, nodir, multi, strc);
}
