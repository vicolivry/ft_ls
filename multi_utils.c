/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   multi_utils.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/21 11:51:13 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/27 19:02:14 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

t_data_ls	*parse_multi_ls(t_data_ls *data)
{
	t_st	st;

	lstat(data->name, &st);
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
	int		ret;
	t_st	st;

	lstat(str, &st);
	ret = S_ISDIR(st.st_mode) ? 1 : 0;
	return (ret);
}

t_data_ls	*no_such_file(const char *str, t_data_ls *data, t_pars_ls *strc)
{
	t_data_ls	*tmp;

	tmp = new_data_ls();
	tmp->name = ft_strdup(str);
	tmp->error = errno;
	strc->r && !strc->t ? rev_ascii_sort(&data, tmp) : ascii_sort(&data, tmp);
	return (data);
}

t_data_ls	*no_dir(const char *str, t_data_ls *data, t_pars_ls *strc)
{
	t_data_ls	*tmp;
	t_st		st;
	t_passwd	*pswd;
	t_gp		*grp;

	tmp = new_data_ls();
	tmp->name = ft_strdup(str);
	tmp->path = ft_strdup(str);
	lstat(str, &st);
	tmp->chmod = chmod_ls(st);
	pswd = getpwuid(st.st_uid);
	grp = getgrgid(st.st_gid);
	tmp->gp = ft_strdup(grp->gr_name);
	tmp->pwd = ft_strdup(pswd->pw_name);
	tmp->blck = st.st_blocks;
	tmp->nlnk = st.st_nlink;
	tmp->time = st.st_mtime;
	tmp->size = st.st_size;
	tmp->link = tmp->chmod[0] == 'l' ? fill_link((char*)str, st) : tmp->link;
	tmp->date = time_ls(tmp->time);
	strc->r && !strc->t ? rev_ascii_sort(&data, tmp) : ascii_sort(&data, tmp);
	tmp->next = NULL;
	return (data);
}
