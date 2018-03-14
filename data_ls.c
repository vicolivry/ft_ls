/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   data_ls.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/07 18:31:51 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/14 17:58:25 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"
#include <unistd.h>

t_data_ls	*new_data_ls(void)
{
	t_data_ls	*new;

	if ((new = (t_data_ls*)malloc(sizeof(*new))) == NULL)
		return (NULL);
	new->dir = NULL;
	new->chmod = NULL;
	new->next = NULL;
	new->oth_lst = NULL;
	new->path = NULL;
	new->date = NULL;
	new->name = NULL;
	new->nlnk = 0;
	new->pwd = NULL;
	new->gp = NULL;
	new->date = NULL;
	new->access = 0;
	new->len = 0;
	new->size = 0;
	new->blck = 0;
	new->time = 0;
	new->minor = 0;
	new->major = 0;
	new->empty = 0;
	new->link = NULL;
	return (new);
}

char		*fill_link(char *path, t_st st)
{
	char	*str;
	char	*ret;
	int		eof;
	char	*tmp;
	int		i;

	i = -1;
	ret = ft_strdup("-> ");
	if ((str = malloc(st.st_size + 1)) == NULL)
		return (NULL);
	if (st.st_size)
		eof = readlink((const char*)path, str, st.st_size);
	else
		eof = readlink((const char*)path, str, 4);
	while (str[i++])
		if (str[i] == ' ' || str[i] == '\n')
			str[i] = '\0';
	str[eof] = '\0';
	tmp = ft_strjoin(ret, str);
	ft_memdel((void**)&ret);
	ret = ft_strdup(tmp);
	ft_memdel((void**)&tmp);
	ft_memdel((void**)&str);
	return (ret);
}

static void	min_maj_ls(t_data_ls **data, t_st st)
{
	(*data)->minor = st.st_rdev & 0xffffff;
	(*data)->major = (st.st_rdev >> 24) & 0xff;
}

static void	parse_data_2(t_data_ls **data, t_st st, t_pars_ls strc)
{
	(*data)->blck = st.st_blocks;
	(*data)->nlnk = st.st_nlink;
	(*data)->size = st.st_size;
	(*data)->time = strc.u ? st.st_atime : st.st_mtime;
}

t_data_ls	*parse_data_ls(t_data_ls *data, t_pars_ls strc)
{
	t_st		st;
	t_passwd	*pswd;
	t_gp		*grp;
	char		*tmpath;

	data->name = ft_strdup(data->dir->d_name);
	tmpath = ft_strjoin(data->path, data->name);
	lstat(tmpath, &st);
	if (S_ISDIR(st.st_mode) || data->dir->d_type == 0)
		data->access = check_permission(tmpath);
	data->len = ft_strlen(data->name);
	data->chmod = chmod_ls(st);
	pswd = getpwuid(st.st_uid);
	grp = getgrgid(st.st_gid);
	data->gp = grp ? ft_strdup(grp->gr_name) : ft_itoa(st.st_gid);
	data->pwd = pswd ? ft_strdup(pswd->pw_name) : ft_itoa(st.st_uid);
	parse_data_2(&data, st, strc);
	data->link = S_ISLNK(st.st_mode) ? fill_link(tmpath, st) : data->link;
	data->date = time_ls(data->time);
	if (S_ISCHR(st.st_mode) || S_ISBLK(st.st_mode))
		min_maj_ls(&data, st);
	data->next = NULL;
	ft_memdel((void**)&tmpath);
	return (data);
}
