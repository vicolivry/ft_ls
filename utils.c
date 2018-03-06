/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/16 13:12:41 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/06 15:43:46 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void		maxlen(t_pars_ls *strc, t_data_ls *data)
{
	t_data_ls	*tmp;

	tmp = data;
	while (tmp->next)
	{
		strc->len.name = ft_strlen(tmp->name) > strc->len.name ?
			ft_strlen(tmp->name) : strc->len.name;
		strc->len.nlnk = ft_strlen(ft_itoa(tmp->nlnk)) > strc->len.nlnk ?
			ft_strlen(ft_itoa(tmp->nlnk)) : strc->len.nlnk;
		strc->len.pwd = ft_strlen(tmp->pwd) > strc->len.pwd ? ft_strlen(tmp->pwd)
			: strc->len.pwd;
		strc->len.gp = ft_strlen(tmp->gp) > strc->len.gp ? ft_strlen(tmp->gp)
			: strc->len.gp;
		strc->len.size = ft_strlen(ft_itoa(tmp->size)) > strc->len.size ?
			ft_strlen(ft_itoa(tmp->size)) : strc->len.size;
		tmp = tmp->next;
	}
	tmp = data;
	while (tmp)
	{
		if (tmp->oth_lst)
			maxlen(strc, tmp->oth_lst);
		tmp = tmp->next;
	}
}

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
