/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   s_fmt.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/07 18:14:50 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/08 17:51:03 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int	s_fmt(const char *file, t_pars_ls pars, t_data_ls *data)
{
	struct dirent	*dp;
	DIR				*dirp;
	char			*filename;

	data = parse_data_ls(file, &data);
	while (data->next)
	{
		if (ft_strcmp(data->dir->d_name, ".")
				&& ft_strcmp(data->dir->d_name, ".."))
		{
			ft_printf("%s\n", data->dir->d_name);
			ft_printf("TYPE: %i\n", data->dir->d_type);
			ft_printf("MODE: %d\n", data->stat.st_mode);
		}
		data = data->next;
	}
	return (0);
}
