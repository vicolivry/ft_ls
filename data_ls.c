/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   data_ls.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/07 18:31:51 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/09 17:51:02 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

t_data_ls	*new_data_ls(const char *str)
{
	t_data_ls	*new;

	if ((new = (t_data_ls*)malloc(sizeof(*new))) == NULL)
		return (NULL);
	new->dir = NULL;
	new->chmod = NULL;
	new->next = NULL;
	return (new);
}

t_data_ls	*parse_data_ls(const char *file, t_pars_ls strc)
{
	t_dir		*dp;
	t_st		st;
	DIR			*dirp;
	t_data_ls	*tmp;
	t_passwd	*pswd;
	t_gp		*grp;

	tmp = strc.data;
	if ((dirp = opendir(file)) == NULL)
	{/*
		dirp = opendir(ft_strcat("../", file));
		while (ft_strcmp(dp->d_name, file))
			dp = readdir(dirp);
		*/
	}
	while ((dp = readdir(dirp)) != NULL)
	{
		stat(dp->d_name, &st);
		if (tmp->next == NULL)
			tmp->next = new_data_ls("");
		pswd = getpwuid(st.st_uid);
		grp = getgrgid(st.st_gid);
		tmp->pwd = pswd->pw_name;
		tmp->name = dp->d_name;
		tmp->dir = dp;
		tmp->stat = st;
		tmp->gp = grp->gr_name;
		tmp->chmod = chmod_ls(tmp);
		tmp->nlnk = st.st_nlink;
		tmp->size = st.st_size;
		tmp->date = time_ls(tmp);
		if (dp->d_type == DT_DIR)
			tmp->oth_lst = new_data_ls(dp->d_name);
		tmp = tmp->next;
	}
	closedir(dirp);
	return (strc.data);
}
