/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sort_ls.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/18 13:10:23 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/12 18:12:05 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static t_data_ls	*new_swap(t_data_ls *lst1)
{
	t_data_ls	*tmp;

	tmp = new_data_ls();
	tmp->link = lst1->link;
	tmp->name = lst1->name;
	tmp->path = lst1->path;
	tmp->dir = lst1->dir;
	tmp->access = lst1->access;
	tmp->nlnk = lst1->nlnk;
	tmp->chmod = lst1->chmod;
	tmp->pwd = lst1->pwd;
	tmp->gp = lst1->gp;
	tmp->date = lst1->date;
	tmp->time = lst1->time;
	tmp->size = lst1->size;
	tmp->len = lst1->len;
	tmp->blck = lst1->blck;
	tmp->oth_lst = lst1->oth_lst;
	tmp->minor = lst1->minor;
	tmp->major = lst1->major;
	return (tmp);
}

static void			swap_lst2(t_data_ls **lst2, t_data_ls **tmp)
{
	(*lst2)->name = (*tmp)->name;
	(*lst2)->path = (*tmp)->path;
	(*lst2)->dir = (*tmp)->dir;
	(*lst2)->nlnk = (*tmp)->nlnk;
	(*lst2)->chmod = (*tmp)->chmod;
	(*lst2)->pwd = (*tmp)->pwd;
	(*lst2)->link = (*tmp)->link;
	(*lst2)->gp = (*tmp)->gp;
	(*lst2)->time = (*tmp)->time;
	(*lst2)->date = (*tmp)->date;
	(*lst2)->size = (*tmp)->size;
	(*lst2)->len = (*tmp)->len;
	(*lst2)->blck = (*tmp)->blck;
	(*lst2)->access = (*tmp)->access;
	(*lst2)->oth_lst = (*tmp)->oth_lst;
	(*lst2)->minor = (*tmp)->minor;
	(*lst2)->major = (*tmp)->major;
}

void				swap_lst(t_data_ls **lst1, t_data_ls **lst2)
{
	t_data_ls	*tmp;

	tmp = new_swap(*lst1);
	(*lst1)->name = (*lst2)->name;
	(*lst1)->link = (*lst2)->link;
	(*lst1)->path = (*lst2)->path;
	(*lst1)->dir = (*lst2)->dir;
	(*lst1)->nlnk = (*lst2)->nlnk;
	(*lst1)->access = (*lst2)->access;
	(*lst1)->chmod = (*lst2)->chmod;
	(*lst1)->pwd = (*lst2)->pwd;
	(*lst1)->gp = (*lst2)->gp;
	(*lst1)->date = (*lst2)->date;
	(*lst1)->time = (*lst2)->time;
	(*lst1)->size = (*lst2)->size;
	(*lst1)->len = (*lst2)->len;
	(*lst1)->blck = (*lst2)->blck;
	(*lst1)->oth_lst = (*lst2)->oth_lst;
	(*lst1)->minor = (*lst2)->minor;
	(*lst1)->major = (*lst2)->major;
	swap_lst2(lst2, &tmp);
	free(tmp);
}
