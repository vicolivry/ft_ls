/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   s_fmt.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/07 18:14:50 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/09 16:22:30 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int	s_fmt(const char *file, t_pars_ls strc)
{
	while (strc.data->next)
	{
		if (ft_strcmp(strc.data->dir->d_name, ".")
				&& ft_strcmp(strc.data->dir->d_name, ".."))
		{
		if (strc.data->dir->d_type == DT_DIR && strc.rr)
		{
			ft_printf("%s\n", strc.data->name);
			ft_ls(strc.data->name, strc);
		}
			ft_printf("%-17s", strc.data->name);
			ft_printf("%s\n", strc.data->chmod);
		}
		strc.data = strc.data->next;
	}
	return (0);
}
