/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/16 13:12:41 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/27 11:52:49 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void	min_maj_ls(t_data_ls *data, t_data_ls *tmp)
{
	if (tmp->minor || tmp->major)
	{
		data->len.min = ft_nb_len(tmp->minor) > data->len.min ?
			ft_nb_len(tmp->minor) : data->len.min;
		data->len.maj = ft_nb_len(tmp->major) > data->len.maj ?
			ft_nb_len(tmp->major) : data->len.maj;
	}
}

void		maxlen(t_data_ls *data1, t_data_ls *data2)
{
	t_data_ls	*tmp;

	tmp = data2;
	data1->len.name = ft_strlen(tmp->name) > data1->len.name ?
		ft_strlen(tmp->name) : data1->len.name;
	data1->len.nlnk = ft_nb_len(tmp->nlnk) > data1->len.nlnk ?
		ft_nb_len(tmp->nlnk) : data1->len.nlnk;
	data1->len.pwd = ft_strlen(tmp->pwd) > data1->len.pwd ?
		ft_strlen(tmp->pwd) : data1->len.pwd;
	data1->len.gp = ft_strlen(tmp->gp) > data1->len.gp ? ft_strlen(tmp->gp)
		: data1->len.gp;
	data1->len.size = ft_nb_len(tmp->size) > data1->len.size ?
		ft_nb_len(tmp->size) : data1->len.size;
	min_maj_ls(data1, tmp);
	tmp = tmp->next;
}

int			check_permission(char *str)
{
	DIR	*dirp;

	if ((dirp = opendir(str)) != NULL)
	{
		closedir(dirp);
		return (1);
	}
	return (0);
}

int			total_bck(t_data_ls *data)
{
	t_data_ls	*tmp;
	int			total;

	total = 0;
	tmp = data;
	while (tmp)
	{
		total += tmp->blck;
		tmp = tmp->next;
	}
	return (total);
}
