/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   multi.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/08 18:28:49 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/27 19:02:11 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_no_file(t_data_ls *nofile)
{
	if (nofile)
	{
		while (nofile)
		{
			errno = nofile->error;
			ft_putstr_fd("ft_ls: ", 2);
			ft_putstr_fd(nofile->name, 2);
			perror(" ");
			nofile = nofile->next;
		}
	}
}

static void	print_no_dir(t_data_ls *nodir, t_pars_ls *strc)
{
	t_data_ls *tmp;

	tmp = nodir;
	if (strc->t)
		insert_time(&nodir, *strc);
	while (tmp)
	{
		maxlen(nodir, tmp);
		tmp = tmp->next;
	}
	tmp = nodir;
	if (nodir)
		print_noflag2(strc, nodir, tmp);
}

static void	free_multi(t_data_ls *nofile, t_data_ls *nodir, t_data_ls *multi,
		t_pars_ls strc)
{
	free_ls(strc.data);
	free_ls(multi);
	free_ls(nodir);
	free_ls(nofile);
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
