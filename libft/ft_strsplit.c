/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/03 12:04:15 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/03 12:04:29 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_lenword(const char *str, char c)
{
	int	count;

	if (str == NULL || c == 0)
		return (0);
	count = 0;
	while (*str != c)
	{
		str++;
		count++;
	}
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		var[3];

	var[2] = 0;
	var[0] = ft_wordcount(s, c);
	if (s == NULL || c == 0)
		return (NULL);
	if ((tab = (char **)malloc(sizeof(char *) * var[0] + 1)) == NULL)
		return (NULL);
	while (var[0]--)
	{
		while (*s == c && *s)
			s++;
		if (*s != '\0')
		{
			var[1] = 0;
			if ((tab[var[2]] = malloc(ft_lenword(s, c) + 1)) == NULL)
				return (NULL);
			while (*s && *s != c)
				tab[var[2]][var[1]++] = *s++;
			tab[var[2]++][var[1]] = '\0';
		}
	}
	tab[var[2]] = NULL;
	return (tab);
}
