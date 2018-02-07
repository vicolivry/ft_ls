/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/07 15:21:13 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/07 20:08:17 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "./libftprintf/printf.h"
# include <dirent.h>

# define FLAGS_LS "-Ralrt"

typedef struct			s_pars_ls
{
	int					l;
	int					r;
	int					rr;
	int					a;
	int					t;
}						t_pars_ls;

typedef struct			s_data_ls
{
	const char			*name;
	int					time;
	struct s_data_ls	*next;
}						t_data_ls;

int						s_fmt(const char *file,
		t_pars_ls pars, t_data_ls *data);
int						l_fmt(const char *file,
		t_pars_ls pars, t_data_ls *data);
t_data_ls				*new_data_ls(const char *str);
t_data_ls				*parse_data_ls(const char *file, t_data_ls **data);


#endif
