/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sort_utils_ls.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/12 17:53:17 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/14 18:09:15 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	ascii_sort(t_data_ls *lst)
{
	t_data_ls	*tmp;
	int			swap;

	swap = 0;
	tmp = lst;
	while (tmp->next->next)
	{
		if (ft_strcmp(tmp->name, tmp->next->name) > 0)
		{
			swap_lst(&tmp, &tmp->next);
			swap = 1;
		}
		tmp = tmp->next;
	}
	if (swap)
		ascii_sort(lst);
}

void	rev_ascii_sort(t_data_ls *lst)
{
	t_data_ls	*tmp;
	int			swap;

	swap = 0;
	tmp = lst;
	if (!tmp->empty)
		while (tmp->next->next)
		{
			if (ft_strcmp(tmp->name, tmp->next->name) < 0)
			{
				swap_lst(&tmp, &tmp->next);
				swap = 1;
			}
			tmp = tmp->next;
		}
	if (swap)
		rev_ascii_sort(lst);
}

void	time_sort(t_data_ls *lst)
{
	t_data_ls	*tmp;
	int			swap;

	swap = 0;
	tmp = lst;
	while (tmp->next->next)
	{
		if (tmp->time < tmp->next->time)
		{
			swap_lst(&tmp, &tmp->next);
			swap = 1;
		}
		tmp = tmp->next;
	}
	if (swap)
		time_sort(lst);
}

void	rev_time_sort(t_data_ls *lst)
{
	t_data_ls	*tmp;
	int			swap;

	swap = 0;
	tmp = lst;
	while (tmp->next->next)
	{
		if (tmp->time > tmp->next->time)
		{
			swap_lst(&tmp, &tmp->next);
			swap = 1;
		}
		tmp = tmp->next;
	}
	if (swap)
		rev_time_sort(lst);
}
