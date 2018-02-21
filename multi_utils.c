/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   multi_utils.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/21 11:51:13 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/21 18:11:43 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static t_data_ls	*parse_multi_ls(t_data_ls *data)
{
	t_st	st;

	lstat(data->name, &st);
	data->len = ft_strlen(data->name);
	data->time = st.st_mtime;
	return (data);
}

void			multifile(int ac, int j, const char **av, t_pars_ls strc)
{
	t_data_ls	*multi;
	t_data_ls	*tmp;

	multi = new_data_ls();
	tmp = multi;
	while (ac-- > j)
	{
		if (!check_arg(av[ac]))
			ft_printf("ft_ls: %s: No such file or directory\n", av[ac]);
		else
		{
			tmp->name = ft_strdup(av[ac]);
			tmp = parse_multi_ls(tmp);
			if (tmp->next == NULL)
				tmp->next = new_data_ls();
			tmp = tmp->next;
		}
	}
	if (multi->next)
	{
		ascii_sort(multi);
		if (strc.t)
			time_sort(multi);
	}
	while (multi->next)
	{
		strc.rr ? ft_ls_r(multi->name, strc) : ft_ls(multi->name, strc);
		display(strc, strc.data);
		strc.data = new_data_ls();
		multi = multi->next;
	}
}
