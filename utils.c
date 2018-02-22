/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/16 13:12:41 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/22 18:26:11 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int		maxlen(t_data_ls *data)
{
	t_data_ls	*tmp;
	int			len;

	tmp = data;
	len = 0;
	while (tmp->next)
	{
		len = tmp->next->len > tmp->len ? tmp->next->len : len;
		tmp = tmp->next;
	}
	return (len + 1);
}
/*
static int			check_access(const char *str)
{
	t_st	st;
	char	*chmod;

	lstat (str, &st);
	chmod = chmod_ls(st);
	if (chmod[1] == '-')
		return (0);
	return (1);
}
*/
int		check_permission(t_data_ls *data)
{
	if (data->chmod[1] == '-' || data->chmod[4] == '-')
		return (0);
	return (1);
}

int		total_bck(t_data_ls *data)
{
	t_data_ls	*tmp;
	int			total;

	total = 0;
	tmp = data;
	while (tmp->next)
	{
		total += tmp->blck;
		tmp = tmp->next;
	}
	return (total);
}
