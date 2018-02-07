/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   data_ls.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/07 18:31:51 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/07 20:47:26 by volivry     ###    #+. /#+    ###.fr     */
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
	DIR				*dirp;
	t_data_ls		*tmp;
	char		*str;

	tmp = *data;
	if ((dirp = opendir(file)) == NULL)
		return (NULL);
	while ((dp = readdir(dirp)) != NULL)
	{
		if (tmp->next == NULL)
			tmp->next = new_data_ls("crotte");
		str = dp->d_name;
		tmp->name = ft_strdup(str);
		tmp->time = 25;
	ft_printf("Dans DATA : %s\n%d\n\n", tmp->name, tmp->time);
		tmp = tmp->next;
	}
	return (*data);
}
