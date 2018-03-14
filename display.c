/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/06 13:38:59 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/14 17:37:42 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_noflag2(t_pars_ls strc, t_data_ls *tmp)
{
	while (tmp->next)
	{
		if (tmp->name[0] != '.')
		{
			if (strc.l)
			{
				ft_printf("%s %*d ", tmp->chmod, strc.len.nlnk,
						tmp->nlnk);
				if (!strc.g)
					ft_printf("%-*s ", strc.len.pwd, tmp->pwd);
				ft_printf("%-*s ", strc.len.gp, tmp->gp);
				if (tmp->chmod[0] == 'b' || tmp->chmod[0] == 'c')
					ft_printf("%*d, %*d ", strc.len.maj, tmp->major,
							strc.len.min, tmp->minor);
				else
					ft_printf("%*d ", strc.len.min ? strc.len.min +
							strc.len.maj + 2 : strc.len.size, tmp->size);
				ft_printf(" %s %s", tmp->date, tmp->name);
				tmp->link ? ft_printf(" %s\n", tmp->link) : ft_putchar('\n');
			}
			else
				ft_printf("%s\n", tmp->name);
		}
		tmp = tmp->next;
	}
}

static void	print_noflag3(t_pars_ls strc, t_data_ls *tmp)
{
	while (tmp->next)
	{
		if (!tmp->access && tmp->oth_lst && strc.rr)
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
			print_noflag(strc, tmp->oth_lst);
		tmp = tmp->next;
	}
}

void		print_noflag(t_pars_ls strc, t_data_ls *data)
{
	t_data_ls	*tmp;
	static int	rc = 0;

	tmp = data;
	if (rc)
		ft_putstr("\n");
	if (tmp->access)
		tmp->empty = tmp->next->next->next ? 0 : 1;
	if (tmp->access)
		strc.r ? rev_ascii_sort(tmp) : ascii_sort(tmp);
	if (tmp->access && strc.t)
		strc.r ? rev_time_sort(tmp) : time_sort(tmp);
	if (rc && tmp->path && ft_strcmp(tmp->path, "./") &&
			ft_strcmp(tmp->name, "../"))
	{
		tmp->path[ft_strlen(tmp->path) - 1] = ':';
		ft_printf("%s\n", tmp->path);
	}
	rc = 1;
	if (strc.l && !tmp->empty)
		ft_printf("total %d\n", total_bck(tmp));
	print_noflag2(strc, tmp);
	tmp = data;
	print_noflag3(strc, tmp);
}

void		display(t_pars_ls strc, t_data_ls *data)
{
	if (!strc.a)
		print_noflag(strc, data);
	else if (strc.a)
		print_flag_a(strc, data);
}
