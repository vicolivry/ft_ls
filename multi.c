/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   multi.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/08 18:28:49 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/12 17:36:39 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_no_file(t_data_ls *nofile, t_pars_ls strc)
{
	if (nofile->next)
	{
		strc.r ? rev_ascii_sort(nofile) : ascii_sort(nofile);
		if (strc.t)
			strc.r ? rev_time_sort(nofile) : time_sort(nofile);
		while (nofile->next)
		{
			errno = nofile->error;
			ft_putstr_fd("ft_ls: ", 2);
			ft_putstr_fd(nofile->name, 2);
			perror(" ");
			nofile = nofile->next;
		}
	}
}

static void	print_no_dir(t_data_ls *nodir, t_pars_ls strc)
{
	if (nodir->next)
	{
		strc.r ? rev_ascii_sort(nodir) : ascii_sort(nodir);
		if (strc.t)
			strc.r ? rev_time_sort(nodir) : time_sort(nodir);
		while (nodir->next)
		{
			if (strc.l)
			{
				ft_printf("%s  %2d %s  %s %6d %s ", nodir->chmod, nodir->nlnk,
						nodir->pwd, nodir->gp, nodir->size, nodir->date);
				ft_printf("%-*s\n", strc.len.name, nodir->name);
			}
			else
				ft_printf("%s\n", nodir->name);
			nodir = nodir->next;
		}
		ft_putchar_fd('\n', 2);
	}
}

static void	multifile2(t_data_ls *nofile, t_data_ls *nodir, t_data_ls *multi,
		t_pars_ls strc)
{
	t_data_ls	*tmp;

	print_no_file(nofile, strc);
	print_no_dir(nodir, strc);
	if (multi->next)
	{
		strc.r ? rev_ascii_sort(multi) : ascii_sort(multi);
		if (strc.t)
			strc.r ? rev_time_sort(multi) : time_sort(multi);
	}
	tmp = multi;
	while (tmp->next)
	{
		strc.rr ? ft_ls_r(tmp->name, strc) : ft_ls(tmp->name, strc);
		maxlen(&strc, strc.data);
		display(strc, strc.data);
		tmp = tmp->next;
	}
	free_ls(strc.data);
	free_ls(multi);
	free_ls(nodir);
	free_ls(nofile);
}

void		multifile(int ac, int j, const char **av, t_pars_ls strc)
{
	t_data_ls	*multi;
	t_data_ls	*tmp;
	t_data_ls	*nofile;
	t_data_ls	*nodir;

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
			if (tmp->next == NULL)
				tmp->next = new_data_ls();
			tmp = tmp->next;
		}
	}
	multifile2(nofile, nodir, multi, strc);
}
