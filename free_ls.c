/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free_ls.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/06 16:47:09 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/12 14:35:02 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int free_ls(t_data_ls *data)
{
	t_data_ls	*tmp;
	t_data_ls	*tmp2;

	tmp = data;
	while (tmp)
	{
		if (tmp->access && tmp->oth_lst)
			free_ls(tmp->oth_lst);
		tmp = tmp->next;
	}
	tmp = data;
	while (tmp)
	{
		tmp2 = tmp->next;
		ft_memdel((void**)&tmp->date);
		ft_memdel((void**)&tmp->chmod);
		ft_memdel((void**)&tmp->name);
		ft_memdel((void**)&tmp->path);
		ft_memdel((void**)&tmp->pwd);
		ft_memdel((void**)&tmp->gp);
		ft_memdel((void**)&tmp->link);
		ft_memdel((void**)&tmp->link);
		ft_memdel((void**)&tmp);
		tmp = tmp2;
	}
	ft_memdel((void**)&tmp2);
	return (0);
}
