/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/16 13:12:41 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/14 13:46:26 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void	min_maj_ls(t_pars_ls *strc, t_data_ls *tmp)
{
	if (tmp->minor || tmp->major)
	{
		strc->len.min = ft_nb_len(tmp->minor) > strc->len.min ?
			ft_nb_len(tmp->minor) : strc->len.min;
		strc->len.maj = ft_nb_len(tmp->major) > strc->len.maj ?
			ft_nb_len(tmp->major) : strc->len.maj;
	}
}

void		maxlen(t_pars_ls *strc, t_data_ls *data)
{
	t_data_ls	*tmp;

	tmp = data;
		strc->len.name = ft_strlen(tmp->name) > strc->len.name ?
			ft_strlen(tmp->name) : strc->len.name;
		strc->len.nlnk = ft_nb_len(tmp->nlnk) > strc->len.nlnk ?
			ft_nb_len(tmp->nlnk) : strc->len.nlnk;
		strc->len.pwd = ft_strlen(tmp->pwd) > strc->len.pwd ?
			ft_strlen(tmp->pwd) : strc->len.pwd;
		strc->len.gp = ft_strlen(tmp->gp) > strc->len.gp ? ft_strlen(tmp->gp)
			: strc->len.gp;
		strc->len.size = ft_nb_len(tmp->size) > strc->len.size ?
			ft_nb_len(tmp->size) : strc->len.size;
		min_maj_ls(strc, tmp);
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
	while (tmp->next)
	{
		total += tmp->blck;
		tmp = tmp->next;
	}
	return (total);
}
