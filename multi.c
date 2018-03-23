/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   multi.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/08 18:28:49 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/22 17:25:35 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void print_no_file(t_data_ls *nofile, t_pars_ls *strc)
{
	if (nofile->next)
	{
//		insert_sort(&nofile, *strc);
		while (nofile->next)
		{
			errno = nofile->error;
			ft_putstr_fd("ft_ls: ", 2);
			ft_putstr_fd(nofile->name, 2);
			perror(" ");
			nofile = nofile->next;
		}
		strc->rc = 1;
	}
}

static void print_no_dir(t_data_ls *nodir, t_pars_ls *strc)
{
	t_data_ls *tmp;

	tmp = nodir;
	while (tmp->next)
	{
		maxlen(strc, tmp);
		tmp = tmp->next;
	}
	tmp = nodir;
/*	if (nodir->next)
		insert_sort(&nodir, *strc);*/
	print_noflag2(strc, tmp);
}

static void free_multi(t_data_ls *nofile, t_data_ls *nodir, t_data_ls *multi,
					   t_pars_ls strc)
{
	free_ls(strc.data);
	free_ls(multi);
	free_ls(nodir);
	free_ls(nofile);
}

static void multifile2(t_data_ls *nofile, t_data_ls *nodir, t_data_ls *multi,
					   t_pars_ls strc)
{
	t_data_ls *tmp;

	print_no_file(nofile, &strc);
	print_no_dir(nodir, &strc);
/*	if (multi->next)
		insert_sort(&multi, strc);*/
	tmp = multi;
	while (tmp->next)
	{
		strc.rr ? ft_ls_r(tmp->name, &strc) : ft_ls(tmp->name, &strc);
		if (check_permission(tmp->name))
		{
			display(strc, strc.data);
			free_ls(strc.data);
		}
		tmp = tmp->next;
		strc.data = new_data_ls();
	}
	free_multi(nofile, nodir, multi, strc);
}

void multifile(int ac, int j, const char **av, t_pars_ls strc)
{
	t_data_ls *multi;
	t_data_ls *tmp;
	t_data_ls *nofile;
	t_data_ls *nodir;

	multi = new_data_ls();
	nofile = new_data_ls();
	nodir = new_data_ls();
	tmp = multi;
	while (ac-- > j)
	{
		if (!check_exist(av[ac]))
			nofile = no_such_file(av[ac], nofile);
		else if (!check_dir(av[ac]))
			nodir = no_dir(av[ac], nodir);
		else
		{
			tmp->name = ft_strdup(av[ac]);
			tmp = parse_multi_ls(tmp);
			tmp->next = new_data_ls();
			tmp = tmp->next;
		}
	}
	multifile2(nofile, nodir, multi, strc);
}
