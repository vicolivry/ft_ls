/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/28 14:58:43 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/28 15:36:21 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_ls2(const char *file, t_data_ls *tmp, t_pars_ls *strc)
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

static void	ft_ls_end(DIR *dirp, t_data_ls *tmp, t_pars_ls *strc)
{
	ft_memdel((void**)&tmp);
	if (strc->t)
		insert_time(&strc->data, *strc);
	tmp = strc->data;
	while (tmp)
	{
		maxlen(strc->data, tmp);
		tmp = tmp->next;
	}
	closedir(dirp);
}

void		ft_ls(const char *file, t_pars_ls *strc)
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
			tmp->path = ft_strdup(str);
			ft_memdel((void**)&str);
			tmp = parse_data_ls(tmp, *strc);
			strc->r && !strc->t ? rev_ascii_sort(&strc->data, tmp) :
				ascii_sort(&strc->data, tmp);
			tmp = new_data_ls();
		}
		ft_ls_end(dirp, tmp, strc);
	}
	else
		ft_ls2(file, tmp, strc);
}
