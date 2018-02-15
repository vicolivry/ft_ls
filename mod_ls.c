/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mod_ls.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/09 11:12:09 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/15 19:20:09 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

char	*chmod_ls(t_st stat)
{
	char	*str;

	if (!(str = malloc(11)))
		return (NULL);
	str[0] = S_ISREG(stat.st_mode) ? '-' : 0;
	str[0] = S_ISDIR(stat.st_mode) ? 'd' : str[0];
	str[0] = S_ISCHR(stat.st_mode) ? 'c' : str[0];
	str[0] = S_ISBLK(stat.st_mode) ? 'b' : str[0];
	str[0] = S_ISFIFO(stat.st_mode) ? 'p' : str[0];
	str[0] = S_ISLNK(stat.st_mode) ? 'l' : str[0];
	str[0] = S_ISSOCK(stat.st_mode) ? 's' : str[0];
	str[1] = (stat.st_mode & S_IRUSR) ? 'r' : '-';
	str[2] = (stat.st_mode & S_IWUSR) ? 'w' : '-';
	str[3] = (stat.st_mode & S_IXUSR) ? 'x' : '-';
	str[4] = (stat.st_mode & S_IRGRP) ? 'r' : '-';
	str[5] = (stat.st_mode & S_IWGRP) ? 'w' : '-';
	str[6] = (stat.st_mode & S_IXGRP) ? 'x' : '-';
	str[7] = (stat.st_mode & S_IROTH) ? 'r' : '-';
	str[8] = (stat.st_mode & S_IWOTH) ? 'w' : '-';
	str[9] = (stat.st_mode & S_IXOTH) ? 'x' : '-';
	str[10] = '\0';
	return (str);
}

char	*time_ls(t_st st)
{
	char	*tmp1;
	char	*tmp;
	char	*str;

	tmp = ctime(&st.st_mtime);
	tmp1 = ft_strsub(tmp, 4, 12);
	str = tmp1;
	return (str);
}
