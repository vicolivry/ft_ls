/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/06 13:38:59 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/27 19:27:22 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void	long_format(t_data_ls *tmp, t_data_ls *data, t_pars_ls *strc)
{
	ft_printf("%s  %*d ", tmp->chmod, data->len.nlnk,
			tmp->nlnk);
	if (!strc->g)
		ft_printf("%-*s ", data->len.pwd, tmp->pwd);
	ft_printf(" %-*s  ", data->len.gp, tmp->gp);
	if (tmp->chmod[0] == 'b' || tmp->chmod[0] == 'c')
		ft_printf("%*d, %*d ", data->len.maj, tmp->major,
				data->len.min, tmp->minor);
	else
		ft_printf("%*d ", data->len.min ? data->len.min +
				data->len.maj + 2 : data->len.size, tmp->size);
	ft_printf("%s %s", tmp->date, tmp->name);
	tmp->link ? ft_printf(" %s\n", tmp->link) : ft_putchar('\n');
}

void		print_noflag2(t_pars_ls *strc, t_data_ls *data, t_data_ls *tmp)
{
	while (tmp)
	{
		if (tmp->name[0] != '.')
		{
			if (strc->l)
				long_format(tmp, data, strc);
			else
				ft_printf("%s\n", tmp->name);
		}
		tmp = tmp->next;
		strc->rc = 1;
	}
}

static void	print_noflag3(t_pars_ls *strc, t_data_ls *tmp)
{
	while (tmp)
	{
		if (!tmp->access && tmp->oth_lst && strc->rr)
		{
			tmp->oth_lst->path[ft_strlen(tmp->oth_lst->path) - 1] = ':';
				ft_putchar('\n');
			ft_printf("%s\n", tmp->oth_lst->path);
			ft_putstr_fd("ft_ls: ", 2);
			ft_putstr_fd(tmp->oth_lst->name, 2);
			ft_putstr_fd(": Permission denied\n", 2);
			free_ls(tmp->oth_lst);
		}
		if (tmp->access && tmp->oth_lst && tmp->name[0] != '.')
			print_noflag(*strc, tmp->oth_lst);
		tmp = tmp->next;
	}
	strc->rc = 1;
}

void		print_noflag(t_pars_ls strc, t_data_ls *data)
{
	t_data_ls	*tmp;

	tmp = data;
	if (strc.rc)
		ft_putstr("\n");
	if (tmp->access)
		tmp->empty = tmp->next->next ? 0 : 1;
	if (strc.rc && tmp->path && ft_strcmp(tmp->path, "./") &&
			ft_strcmp(tmp->name, "../"))
	{
		tmp->path[ft_strlen(tmp->path) - 1] = ':';
		ft_printf("%s\n", tmp->path);
	}
	if (strc.l && !tmp->empty)
		ft_printf("total %d\n", total_bck(tmp));
	print_noflag2(&strc, data, tmp);
	tmp = data;
	print_noflag3(&strc, tmp);
}

void		display(t_pars_ls strc, t_data_ls *data)
{
	if (!strc.a)
		print_noflag(strc, data);
	else if (strc.a)
		print_flag_a(strc, data);
}
