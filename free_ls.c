/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free_ls.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/06 16:47:09 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/09 17:35:24 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int free_ls(t_data_ls *data)
{
	t_data_ls *tmp;
	t_data_ls *tmp2;

	tmp = data;
	while (tmp)
	{
		tmp2 = tmp->next;
		if (tmp->path)
		ft_memdel((void **)&tmp->path);
		if (tmp->name)
		ft_memdel((void **)&tmp->name);
		if (tmp->gp)
		ft_memdel((void **)&tmp->gp);
		if (tmp->date)
		ft_memdel((void **)&tmp->date);
		if (tmp->pwd)
		ft_memdel((void **)&tmp->pwd);
		if (tmp->chmod)
		ft_memdel((void **)&tmp->chmod);
		if (tmp)
		free(tmp);
		tmp = tmp2;
	}
	tmp = data;
	while (tmp->next)
	{
		if (tmp->oth_lst)
			free_ls(tmp);
		tmp = tmp->next;
	}
	return (0);
}
