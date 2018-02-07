/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse_ls.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/07 15:56:20 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/07 19:01:24 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

t_pars_ls	init_pars_ls(t_pars_ls pars)
{
	pars.l = 0;
	pars.r = 0;
	pars.rr = 0;
	pars.a = 0;
	pars.t = 0;
	return (pars);
}
