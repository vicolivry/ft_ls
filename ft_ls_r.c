/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls_r.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/12 16:09:30 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/23 17:59:42 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

static void	recurse(const char *file, t_data_ls **data, t_pars_ls *strc)
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
		maxlen(strc, tmp);
		insert_sort(data, *strc, tmp);
		recurse2(tmp, str, strc);
		tmp = new_data_ls();
	}
	closedir(dirp);
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
		tmp->oth_lst = new_data_ls();
		str = ft_strjoin(tmp->path, tmp->name);
		recurse(str, &tmp->oth_lst, strc);
		ft_memdel((void**)&str);
	}
}

static void	ft_ls_r2(t_data_ls *tmp, char *str, t_pars_ls *strc)
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
			tmp->access && ft_strcmp(tmp->name, ".")
			&& ft_strcmp(tmp->name, ".."))
	{
		tmp->oth_lst = new_data_ls();
//		tmp->oth_lst->name = ft_strdup(tmp->name);
//		tmp->oth_lst = parse_data_ls(tmp, *strc);
		str = ft_strjoin(tmp->path, tmp->name);
		recurse(str, &tmp->oth_lst, strc);
		ft_memdel((void**)&str);
	}
}

static void	ft_ls_r3(const char *file, t_data_ls *tmp, t_pars_ls *strc)
{
	if (strc->rc)
	{
		ft_putchar('\n');
		ft_printf("%s:\n", file);
	}
	ft_putstr_fd("ft_ls: ", 2);
	if (file[ft_strlen(file) - 1] != '/')
		ft_putstr_fd(file, 2);
	ft_putstr_fd(": Permission denied\n", 2);
	tmp->next = NULL;
	strc->rc = 1;
}

void		ft_ls_r(const char *file, t_pars_ls *strc)
{
	t_dir		*dp;
	DIR			*dirp;
	t_data_ls	*tmp;
	char		*str;

	tmp = new_data_ls();
	if ((dirp = opendir(file)) != NULL)
	{
		while ((dp = readdir(dirp)) != NULL)
		{
			tmp->dir = dp;
			str = ft_strjoin(file, "/");
			tmp->path = file[ft_strlen(file) - 1] == '/' ? ft_strdup(file)
				: ft_strdup(str);
			ft_memdel((void**)&str);
			tmp = parse_data_ls(tmp, *strc);
			maxlen(strc, tmp);
			insert_sort(&strc->data, *strc, tmp);
			ft_ls_r2(tmp, str, strc);

			tmp = new_data_ls();
		}
		closedir(dirp);
	}
	else
		ft_ls_r3(file, tmp, strc);
	while (!strc->data->oth_lst)
		strc->data = strc->data->next;
}
