/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   multi_utils2.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/28 14:34:37 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/28 15:45:05 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_no_file(t_data_ls *nofile)
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

void	print_no_dir(t_data_ls *nodir, t_pars_ls *strc)
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

void	free_multi(t_data_ls *nofile, t_data_ls *nodir, t_data_ls *multi,
		t_pars_ls strc)
{
	free_ls(strc.data);
	free_ls(multi);
	free_ls(nodir);
	free_ls(nofile);
}
