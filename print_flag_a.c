/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_flag_a.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/12 18:48:23 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/12 18:49:23 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_flag_a(t_pars_ls strc, t_data_ls *data)
{
	t_data_ls	*tmp;

	tmp = data;
	ascii_sort(tmp);
	if (ft_strcmp(tmp->path, "./") && ft_strcmp(tmp->name, "../"))
		ft_printf("%s\n", tmp->path);
	ft_printf("total %d\n", total_bck(tmp));
	while (tmp->next)
	{
		if (strc.l)
		{
			ft_printf("%s  %2d %s  %s %6d %s ", tmp->chmod, tmp->nlnk,
					tmp->pwd, tmp->gp, tmp->size, tmp->date);
			ft_printf("%-*s\n", strc.len.name, tmp->name);
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
