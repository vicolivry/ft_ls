/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/07 15:21:13 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/07 14:30:55 by volivry     ###    #+. /#+    ###.fr     */
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

typedef struct			s_len_ls
{
	int					nlnk;
	int					pwd;
	int					gp;
	int					size;
	int					name;
}						t_len_ls;

typedef struct			s_pars_ls
{
	int					l;
	int					r;
	int					rr;
	int					a;
	int					t;
	int					total_bck;
	t_len_ls			len;
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
	int					access;
	time_t				time;
	char*				link;
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
void					ft_ls(const char *file, t_pars_ls strc);
char					*chmod_ls(t_st stat);
char					*time_ls(time_t date);
void					ft_ls_r(const char *file, t_pars_ls strc);
void					maxlen(t_pars_ls *strc, t_data_ls *data);
int						check_permission(t_data_ls *data);
int						total_bck(t_data_ls *data);
void					swap_lst(t_data_ls **lst1, t_data_ls **lst2);
void					ascii_sort(t_data_ls *lst);
void					rev_ascii_sort(t_data_ls *lst);
void					time_sort(t_data_ls *lst);
void					rev_time_sort(t_data_ls *lst);
void					display(t_pars_ls strc, t_data_ls *data);
int						free_ls(t_data_ls *data);
void					multifile(int ac, int j, const char **av, t_pars_ls strc);
#endif
