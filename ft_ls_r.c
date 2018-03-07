/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls_r.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/12 16:09:30 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/07 13:43:44 by volivry     ###    #+. /#+    ###.fr     */
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
	char		*str;

	tmp = data;
	dirp = opendir(file);
	while ((dp = readdir(dirp)) != NULL)
	{
		tmp->dir = dp;
		str = ft_strjoin(file, "/");
		tmp->path = ft_strdup(str);
		ft_memdel((void**)&str);
		tmp = parse_data_ls(tmp);
		if (tmp->dir->d_type == DT_DIR && !tmp->access)
		{
			str = ft_strjoin(tmp->path, tmp->name);
			ft_memdel((void**)&tmp->path);
			tmp->path = ft_strdup(str);
			ft_memdel((void**)&str);
			str = ft_strjoin(tmp->path, "/");
			ft_memdel((void**)&tmp->path);
			tmp->path = ft_strdup(str);
			ft_memdel((void**)&str);
		}
		else if (tmp->dir->d_type == DT_DIR && tmp->access &&
				ft_strcmp(tmp->name, ".") && ft_strcmp(tmp->name, ".."))
		{
			tmp->oth_lst = new_data_ls();
			str = ft_strjoin(tmp->path, tmp->name);
			recurse(str, tmp->oth_lst);
			ft_memdel((void**)&str);

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
	int			i;
	char		*str;

	i = 0;
	tmp = strc.data;
	
	dirp = opendir(file);
	while ((dp = readdir(dirp)) != NULL)
	{
		tmp->dir = dp;
		str = ft_strjoin(file, "/");
		tmp->path = ft_strdup(str);
		ft_memdel((void**)&str);
		tmp = parse_data_ls(tmp);
		if (tmp->dir->d_type == DT_DIR && !tmp->access)
		{
			str = ft_strjoin(tmp->path, tmp->name);
			ft_memdel((void**)&tmp->path);
			tmp->path = ft_strdup(str);
			ft_memdel((void**)&str);
			str = ft_strjoin(tmp->path, "/");
			ft_memdel((void**)&tmp->path);
			tmp->path = ft_strdup(str);
			ft_memdel((void**)&str);
		}
		else if (tmp->dir->d_type == DT_DIR && tmp->access &&
				ft_strcmp(tmp->name, ".") && ft_strcmp(tmp->name, ".."))
		{
			tmp->oth_lst = new_data_ls();
			str = ft_strjoin(tmp->path, tmp->name);
			recurse(str, tmp->oth_lst);
			ft_memdel((void**)&str);
		}
		if (tmp->next == NULL)
			tmp->next = new_data_ls();
		tmp = tmp->next;
	}
	closedir(dirp);
}
