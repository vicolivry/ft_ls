/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   recurse.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/28 16:58:32 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/28 17:01:22 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void	recurse_end(DIR *dirp, t_data_ls *tmp, t_pars_ls *strc,
		t_data_ls **data)
{
	ft_memdel((void**)&tmp);
	if (strc->t)
		insert_time(data, *strc);
	tmp = *data;
	while (tmp)
	{
		maxlen(*data, tmp);
		tmp = tmp->next;
	}
	closedir(dirp);
}

void		recurse(const char *file, t_data_ls **data, t_pars_ls *strc)
{
	t_dir		*dp;
	DIR			*dirp;
	t_data_ls	*tmp;
	char		*str;

	*data = NULL;
	tmp = new_data_ls();
	dirp = opendir(file);
	while ((dp = readdir(dirp)) != NULL)
	{
		tmp->dir = dp;
		str = ft_strjoin(file, "/");
		tmp->path = file[ft_strlen(file) - 1] == '/' ? ft_strdup(file)
			: ft_strdup(str);
		ft_memdel((void**)&str);
		tmp = parse_data_ls(tmp, *strc);
		strc->r ? rev_ascii_sort(data, tmp) : ascii_sort(data, tmp);
		recurse2(tmp, str, strc);
		tmp = new_data_ls();
	}
	recurse_end(dirp, tmp, strc, data);
}

void		recurse2(t_data_ls *tmp, char *str, t_pars_ls *strc)
{
	if (tmp->dir->d_type == DT_DIR && !tmp->access)
	{
		tmp->oth_lst = new_data_ls();
		str = ft_strjoin(tmp->path, tmp->name);
		ft_memdel((void**)&tmp->path);
		tmp->oth_lst->path = ft_strdup(str);
		ft_memdel((void**)&str);
		str = ft_strjoin(tmp->oth_lst->path, "/");
		ft_memdel((void**)&tmp->oth_lst->path);
		tmp->oth_lst->path = ft_strdup(str);
		ft_memdel((void**)&str);
		tmp->oth_lst->access = 0;
		tmp->oth_lst->name = ft_strdup(tmp->name);
	}
	else if ((tmp->dir->d_type == DT_DIR || tmp->dir->d_type == 0) &&
			tmp->access &&
			ft_strcmp(tmp->name, ".") && ft_strcmp(tmp->name, ".."))
	{
		str = ft_strjoin(tmp->path, tmp->name);
		recurse(str, &tmp->oth_lst, strc);
		ft_memdel((void**)&str);
	}
}
