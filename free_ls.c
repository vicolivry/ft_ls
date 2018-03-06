/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free_ls.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/06 16:47:09 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/06 17:50:41 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int		free_ls(t_data_ls *data)
{
	t_data_ls	*tmp;
	t_data_ls	*tmp2;

	tmp = data;

	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp->path);
		free(tmp->name);
		free(tmp->gp);
		free(tmp->date);
		free(tmp->pwd);
		free(tmp);
		tmp = tmp2;
	}
	tmp = data;
	while (tmp->next)
	{
		if (tmp->oth_lst)
			free_ls(tmp->oth_lst);
		tmp = tmp->next;
	}
	return (0);
}
