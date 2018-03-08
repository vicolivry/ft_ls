/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   multi_utils.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/21 11:51:13 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/08 18:41:56 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

t_data_ls	*parse_multi_ls(t_data_ls *data)
{
	t_st	st;

	lstat(data->name, &st);
	data->len = ft_strlen(data->name);
	data->time = st.st_mtime;
	return (data);
}

int			check_exist(const char *str)
{
	t_st	st;

	if ((lstat(str, &st)) == -1)
		return (0);
	return (1);
}

int			check_dir(const char *str)
{
	DIR		*dirp;
	t_dir	*dp;
	int		ret;

	ret = 0;
	if ((dirp = opendir(str)) != NULL)
	{
		if ((dp = readdir(dirp)) != NULL)
			ret = dp->d_type == DT_DIR ? 1 : 0;
		closedir(dirp);
	}
	return (ret);
}

t_data_ls	*no_such_file(const char *str, t_data_ls *data)
{
	t_data_ls	*tmp;

	tmp = data;
	while (tmp->next)
		tmp = tmp->next;
	tmp->name = ft_strdup(str);
	tmp->error = errno;
	tmp->next = new_data_ls();
	return (data);
}

t_data_ls	*no_dir(const char *str, t_data_ls *data)
{
	t_data_ls	*tmp;
	t_st		st;
	t_passwd	*pswd;
	t_gp		*grp;

	tmp = data;
	while (tmp->next)
		tmp = tmp->next;
	tmp->name = ft_strdup(str);
	tmp->path = ft_strdup(str);
	lstat(str, &st);
	tmp->chmod = chmod_ls(st);
	pswd = getpwuid(st.st_uid);
	grp = getgrgid(st.st_gid);
	tmp->gp = ft_strdup(grp->gr_name);
	tmp->pwd = ft_strdup(pswd->pw_name);
	tmp->blck = st.st_blocks;
	tmp->nlnk = st.st_size;
	tmp->time = st.st_mtime;
	tmp->link = tmp->chmod[0] == 'l' ? fill_link((char*)str, st) : tmp->link;
	tmp->date = time_ls(tmp->time);
	tmp->next = new_data_ls();
	return (data);
}
