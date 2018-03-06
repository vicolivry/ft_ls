/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   multi_utils.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/21 11:51:13 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/06 17:46:05 by volivry     ###    #+. /#+    ###.fr     */
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
/*
static int			check_access(const char *str)
{
	t_st	st;
	char	*chmod;

	lstat (str, &st);
	chmod = chmod_ls(st);
	if (chmod[1] == '-')
		return (0);
	return (1);
}
*/
static int			check_dir(const char *str)
{
	DIR		*dirp;
	t_dir	*dp;
	int		ret;

	ret = 0;
	if ((dirp = opendir(str)) != NULL)
		if ((dp = readdir(dirp)) != NULL)
			ret = dp->d_type == DT_DIR ? 1 : 0;
	closedir(dirp);
	return (ret);
}

void				multifile(int ac, int j, const char **av, t_pars_ls strc)
{
	t_data_ls	*multi;
	t_data_ls	*tmp;

	multi = new_data_ls();
	tmp = multi;
	while (ac-- > j)
	{
		if (!check_dir(ac[av]))
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
		strc.r ? rev_ascii_sort(multi) : ascii_sort(multi);
		if (strc.t)
			strc.r ? rev_time_sort(multi) : time_sort(multi);
	}
	tmp = multi;
	while (tmp->next)
	{
		strc.rr ? ft_ls_r(multi->name, strc) : ft_ls(multi->name, strc);
		maxlen(&strc, strc.data);
		display(strc, strc.data);
		free_ls(strc.data);
		strc.data = new_data_ls();
		tmp = tmp->next;
	}
}
