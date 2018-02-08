/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   data_ls.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/07 18:31:51 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/08 17:51:07 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

t_data_ls	*new_data_ls(const char *str)
{
	t_data_ls	*new;

	if ((new = (t_data_ls*)malloc(sizeof(*new))) == NULL)
		return (NULL);
	new->name = str;
	new->time = 0;
	new->next = NULL;
	return (new);
}

t_data_ls	*parse_data_ls(const char *file, t_data_ls **data)
{
	struct dirent	*dp;
	struct stat		st;
	DIR				*dirp;
	t_data_ls		*tmp;

	tmp = *data;
	if ((dirp = opendir(file)) == NULL)
		return (NULL);
	while ((dp = readdir(dirp)) != NULL)
	{
		stat(dp->d_name, &st);
		if (tmp->next == NULL)
			tmp->next = new_data_ls("");
		tmp->dir = dp;
		tmp->stat = st;
		tmp = tmp->next;
		tmp->stat = st;
	}
	closedir(dirp);
	return (*data);
}
