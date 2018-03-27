/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse_ls.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/07 15:56:20 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/27 19:04:50 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

t_len_ls		init_len(void)
{
	t_len_ls	len;

	len.nlnk = 0;
	len.pwd = 0;
	len.gp = 0;
	len.size = 0;
	len.name = 0;
	len.min = 0;
	len.maj = 0;
	return (len);
}

t_pars_ls		init_pars_ls(void)
{
	t_pars_ls	pars;

	pars.u = 0;
	pars.l = 0;
	pars.r = 0;
	pars.rr = 0;
	pars.a = 0;
	pars.t = 0;
	pars.rc = 0;
	pars.data = NULL;
	return (pars);
}

int				parse_ls(t_pars_ls *pars, const char *str)
{
	int		i;

	i = 1;
	while (str[i])
	{
		if (!ft_strchr(FLAGS_LS, str[i]))
		{
			ft_printf("ft_ls: illegal option -- %c", str[i]);
			ft_printf("\nusage: ft_ls [%s] [file ...]\n", FLAGS_LS);
			return (0);
		}
		else
		{
			pars->l = ft_strchr(str, 'l') ? 1 : pars->l;
			pars->r = ft_strchr(str, 'r') ? 1 : pars->r;
			pars->rr = ft_strchr(str, 'R') ? 1 : pars->rr;
			pars->a = ft_strchr(str, 'a') ? 1 : pars->a;
			pars->t = ft_strchr(str, 't') ? 1 : pars->t;
			pars->u = ft_strchr(str, 'u') ? 1 : pars->u;
			pars->g = ft_strchr(str, 'g') ? 1 : pars->g;
			pars->l = ft_strchr(str, 'g') ? 1 : pars->l;
		}
		i++;
	}
	return (1);
}
