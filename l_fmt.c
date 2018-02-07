/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   l_fmt.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/07 18:14:13 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/07 18:31:43 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int	l_fmt(const char *file, t_pars_ls pars, t_data_ls *data)
{
	struct dirent	*dp;
	DIR				*dirp;
	char			*filename;

	dirp = opendir(file);
	if (dirp == NULL)
		return (1);
	while ((dp = readdir(dirp)) != NULL)
	{
		if (ft_strcmp(dp->d_name, ".") && ft_strcmp(dp->d_name, ".."))
		{
			filename = dp->d_name;
			ft_printf("%-17s", filename);
		}
	}
	return (0);
}
