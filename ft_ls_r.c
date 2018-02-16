/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls_r.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/12 16:09:30 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 18:06:12 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

static void	recurse(const char *file, t_data_ls *data)
{
	t_dir		*dp;
	DIR			*dirp;
	t_data_ls	*tmp;

	tmp = data;
	dirp = opendir(file);
	while ((dp = readdir(dirp)) != NULL)
	{
		tmp->dir = dp;
		tmp->path = ft_strjoin(file, "/");
		tmp = parse_data_ls(tmp);
		if (tmp->dir->d_type == DT_DIR && check_permission(tmp) &&
				ft_strcmp(tmp->name, ".") && ft_strcmp(tmp->name, ".."))
		{
			tmp->oth_lst = new_data_ls();
			tmp->oth_lst->path = ft_strjoin(tmp->path, tmp->name);
			recurse(tmp->oth_lst->path, tmp->oth_lst);
		}
		if (tmp->next == NULL)
			tmp->next = new_data_ls();
		tmp = tmp->next;
	}
	closedir(dirp);
}

void		ft_ls_r(const char *file, t_pars_ls strc)
{
	t_dir		*dp;
	DIR			*dirp;
	t_data_ls	*tmp;

	tmp = strc.data;
	dirp = opendir(file);
	while ((dp = readdir(dirp)) != NULL)
	{
		tmp->dir = dp;
		tmp->path = ft_strjoin(file, "/");
		tmp = parse_data_ls(tmp);
		if (tmp->dir->d_type == DT_DIR && check_permission(tmp) &&
				ft_strcmp(tmp->name, ".") && ft_strcmp(tmp->name, ".."))
		{
			tmp->oth_lst = new_data_ls();
			tmp->oth_lst->path = ft_strjoin(tmp->path, tmp->name);
			recurse(tmp->oth_lst->path, tmp->oth_lst);
		}
		if (tmp->next == NULL)
			tmp->next = new_data_ls();
		tmp = tmp->next;
	}
	closedir(dirp);
	display(strc, strc.data);
}
