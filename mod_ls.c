/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mod_ls.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/09 11:12:09 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/27 14:46:44 by volivry     ###    #+. /#+    ###.fr     */
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
	str[9] = (stat.st_mode & S_ISVTX) ? 'T' : str[9];
	str[10] = '\0';
	return (str);
}

char	*time_ls(time_t date)
{
	char	*str;
	char	*tmp;
	time_t	now;
	int		i;

	i = -1;
	str = ft_strnew(12);
	tmp = ctime(&date);
	time(&now);
	if (now - date > 15778800 || now - date < 0)
	{
		while (i++ < 5)
			str[i] = tmp[4 + i];
		str[i] = ' ';
		while (i++ < 11)
			str[i] = tmp[12 + i];
	}
	else
		while (i++ < 11)
			str[i] = tmp[4 + i];
	return (str);
}
