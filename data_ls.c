/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   data_ls.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/07 18:31:51 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 17:57:05 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

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
	new->len = 0;
	new->size = 0;
	return (new);
}

t_data_ls	*parse_data_ls(t_data_ls *data)
{
	t_st		st;
	t_passwd	*pswd;
	t_gp		*grp;
	char		*tmpath;

	data->name = ft_strdup(data->dir->d_name);
	tmpath = ft_strjoin(data->path, data->name);
	stat(tmpath, &st);
	free(tmpath);
	data->name = ft_strdup(data->dir->d_name);
	data->len = ft_strlen(data->name);
	data->chmod = chmod_ls(st);
	data->blck = st.st_blocks;
	data->nlnk = st.st_nlink;
	data->size = st.st_size;
	data->date = time_ls(st);
	if (check_permission(data))
	{
		pswd = getpwuid(st.st_uid);
		grp = getgrgid(st.st_gid);
		data->gp = ft_strdup(grp->gr_name);
		data->pwd = ft_strdup(pswd->pw_name);
	}
	return (data);
}

