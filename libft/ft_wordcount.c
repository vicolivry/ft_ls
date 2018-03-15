/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wordcount.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/03 12:06:48 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/03 12:06:51 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_wordcount(const char *str, char c)
{
	size_t			i;
	unsigned int	count;

	i = 0;
	count = 0;
	if (str == NULL || c == 0)
		return (0);
	while (str[i] == c && str[i])
		i++;
	while (str[i])
	{
		if (str[i] != c && str[i])
		{
			count++;
			while (str[i] != c)
				i++;
		}
		i++;
	}
	return (count);
}
