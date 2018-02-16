/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/07 15:21:13 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 14:08:10 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "./libftprintf/printf.h"
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <grp.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <time.h>

# define FLAGS_LS "-Ralrt"

typedef struct			s_pars_ls
{
	int					l;
	int					r;
	int					rr;
	int					a;
	int					t;
	int					total_bck;
	char				**poly_arg;
	struct s_data_ls	*data;
}						t_pars_ls;

typedef struct			s_data_ls
{
	char				*name;
	char				*path;
	struct dirent		*dir;
	struct stat			stat;
	int					nlnk;
	char				*chmod;
	char				*pwd;
	char				*gp;
	char				*date;
	int					size;
	int					len;
	int					blck;
	struct s_data_ls	*oth_lst;
	struct s_data_ls	*next;
}						t_data_ls;

typedef struct dirent	t_dir;
typedef struct stat		t_st;
typedef struct passwd	t_passwd;
typedef struct group	t_gp;

int						s_fmt(const char *file, t_pars_ls strc);
int						l_fmt(const char *file, t_pars_ls strc);
t_data_ls				*new_data_ls(void);
t_data_ls				*parse_data_ls(t_data_ls *data);
int						parse_ls(t_pars_ls *pars, const char *str);
t_pars_ls				init_pars_ls(void);
void						ft_ls(const char *file, t_pars_ls strc);
char					*chmod_ls(t_st stat);
char					*time_ls(t_st stat);
void					ft_ls_r(const char *file, t_pars_ls strc);
int						maxlen(t_data_ls *data);
int						check_permission(t_data_ls *data);
int						total_bck(t_data_ls *data);

void					display(t_pars_ls strc, t_data_ls *data);
#endif
