/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/13 16:16:04 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/15 13:40:34 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	display(t_pars_ls strc, t_data_ls *data)
{
	t_data_ls	*tmp;

	tmp = data;
	printf("PATH = %s\n", tmp->path);
	while (tmp->next)
	{
		if (strc.l)
		{
			printf("%s  %2d %s  %s %6d %s ", tmp->chmod, tmp->nlnk,
					tmp->pwd, tmp->gp, tmp->size, tmp->date);
			printf("%-17s\n", tmp->name);
		}
		else
			printf("-->%s\n", tmp->name);
		free(tmp->name);
		tmp = tmp->next;
	}
	ft_putchar('\n');
	tmp = data;
	while (tmp)
	{
		if (tmp->oth_lst)

			display(strc, tmp->oth_lst);
		tmp = tmp->next;
	}
}
