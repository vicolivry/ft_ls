/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sort_utils_ls.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/12 17:53:17 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/26 18:21:24 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	insert_time(t_data_ls **data, t_pars_ls strc)
{
	t_data_ls	*sorted;
	t_data_ls	*tmp;
	t_data_ls	*next;

	sorted = NULL;
	tmp = *data;
	while (tmp)
	{
		next = tmp->next;
		strc.r ? rev_time_sort(&sorted, tmp) : time_sort(&sorted, tmp);
		tmp = next;
	}
	*data = sorted;
}

void	ascii_sort(t_data_ls **data, t_data_ls *newb)
{
	t_data_ls	*tmp;

	if (*data == NULL || ft_strcmp((*data)->name, newb->name) > 0)
	{
		newb->next = *data;
		*data = newb;
	}
	else
	{
		tmp = *data;
		while (tmp->next && ft_strcmp(tmp->next->name, newb->name) < 0)
			tmp = tmp->next;
		newb->next = tmp->next;
		tmp->next = newb;
	}
}

void	rev_ascii_sort(t_data_ls **data, t_data_ls *newb)
{
	t_data_ls	*tmp;

	if (*data == NULL || ft_strcmp((*data)->name, newb->name) < 0)
	{
		newb->next = *data;
		*data = newb;
	}
	else
	{
		tmp = *data;
		while (tmp->next && ft_strcmp(tmp->next->name, newb->name) > 0)
			tmp = tmp->next;
		newb->next = tmp->next;
		tmp->next = newb;
	}
}

void	time_sort(t_data_ls **data, t_data_ls *newb)
{
	t_data_ls	*tmp;

	if (*data == NULL || ((*data)->time <= newb->time &&
				ft_strcmp((*data)->name, newb->name) >= 0))
	{
		newb->next = *data;
		*data = newb;
	}
	else
	{
		tmp = *data;
		while (tmp->next && tmp->next->time >= newb->time)
			tmp = tmp->next;
		newb->next = tmp->next;
		tmp->next = newb;
	}
}

void	rev_time_sort(t_data_ls **data, t_data_ls *newb)
{
	t_data_ls	*tmp;

	if (*data == NULL || ((*data)->time >= newb->time &&
				ft_strcmp((*data)->name, newb->name) <= 0))
	{
		newb->next = *data;
		*data = newb;
	}
	else
	{
		tmp = *data;
		while (tmp->next && tmp->next->time < newb->time)
			tmp = tmp->next;
		newb->next = tmp->next;
		tmp->next = newb;
	}
}
