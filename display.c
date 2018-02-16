/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/13 16:16:04 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 18:04:37 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_flag_a(t_pars_ls strc, t_data_ls *data)
{
	t_data_ls	*tmp;

	tmp = data;
	if (ft_strcmp(tmp->path, "./") && ft_strcmp(tmp->name, "../"))
		ft_printf("%s\n", tmp->path);
	ft_printf("total %d\n", total_bck(tmp));
	while (tmp->next)
	{
		if (strc.l)
		{
			ft_printf("%s  %2d %s  %s %6d %s ", tmp->chmod, tmp->nlnk,
					tmp->pwd, tmp->gp, tmp->size, tmp->date);
			ft_printf("%-*s\n", maxlen(data), tmp->name);
		}
		else
			ft_printf("%s\n", tmp->name);
		tmp = tmp->next;
	}
	ft_putchar('\n');
	tmp = data;
	while (tmp->next)
	{
		if (tmp->oth_lst)
			display(strc, tmp->oth_lst);
		tmp = tmp->next;
	}
}


static void	print_noflag(t_pars_ls strc, t_data_ls *data)
{
	t_data_ls	*tmp;

	tmp = data;
	if (ft_strcmp(tmp->path, "./") && ft_strcmp(tmp->name, "../"))
		ft_printf("%s\n", tmp->path);
	if (strc.l)
		ft_printf("total %d\n", total_bck(tmp));
	while (tmp->next)
	{
		if (tmp->name[0] != '.')
		{
			if (strc.l)
			{
				ft_printf("%s  %2d %s  %s %6d %s ", tmp->chmod, tmp->nlnk,
						tmp->pwd, tmp->gp, tmp->size, tmp->date);
				ft_printf("%-*s\n", maxlen(data), tmp->name);
			}
			else
				ft_printf("%s\n", tmp->name);
		}
		tmp = tmp->next;
	}
	ft_putchar('\n');
	tmp = data;
	while (tmp)
	{
		if (tmp->oth_lst && tmp->name[0] != '.')
			display(strc, tmp->oth_lst);
		tmp = tmp->next;
	}
}

void	display(t_pars_ls strc, t_data_ls *data)
{
	if (!strc.a)
		print_noflag(strc, data);
	else if (strc.a)
		print_flag_a(strc, data);
}
