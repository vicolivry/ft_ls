/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sort_utils_ls.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/12 17:53:17 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/23 14:11:56 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"
/*
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
		if (ft_strcmp(tmp->name, tmp->next->name) > 0)
		{
			swap_lst(&tmp, &tmp->next);
			swap = 1;
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
		while (tmp->next->next->next)
		{
			if (ft_strcmp(tmp->name, tmp->next->name) < 0)
			{
				swap_lst(&tmp, &tmp->next);
				swap = 1;
			}
			tmp = tmp->next;
		}
			if (ft_strcmp(tmp->name, tmp->next->name) < 0)
			{
				swap_lst(&tmp, &tmp->next);
				swap = 1;
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
	if (!tmp->empty)
	while (tmp->next->next)
	{
		if (tmp->time < tmp->next->time)
		{
			swap_lst(&tmp, &tmp->next);
			swap = 1;
		}
		tmp = tmp->next;
	}
		if (tmp->time < tmp->next->time)
		{
			swap_lst(&tmp, &tmp->next);
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
	if (!tmp->empty)
	while (tmp->next->next)
	{
		if (tmp->time > tmp->next->time)
		{
			swap_lst(&tmp, &tmp->next);
			swap = 1;
		}
		tmp = tmp->next;
	}
		if (tmp->time > tmp->next->time)
		{
			swap_lst(&tmp, &tmp->next);
			swap = 1;
		}
	if (swap)
		rev_time_sort(lst);
}*/

static void	insert_time(t_data_ls **data, t_pars_ls strc)
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

void	insert_sort(t_data_ls **data, t_pars_ls strc, t_data_ls *newb)
{
	strc.r ? rev_ascii_sort(data, newb) : ascii_sort(data, newb);
	if (strc.t)
		insert_time(data, strc);
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

	if (*data == NULL || (*data)->time < newb->time)
	{
		newb->next = *data;
		*data = newb;
	}
	else
	{
		tmp = *data;
		while (tmp->next && tmp->next->time > newb->time)
			tmp = tmp->next;
		newb->next = tmp->next;
		tmp->next = newb;
	}
}

void	rev_time_sort(t_data_ls **data, t_data_ls *newb)
{
	t_data_ls	*tmp;

	if (*data == NULL || ((*data)->time > newb->time))
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
