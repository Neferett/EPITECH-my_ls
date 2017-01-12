/*
** utils_list_sort.c for utils_list_sort in /home/Neferett/PSU_2016_my_ls
** 
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
** 
** Started on  Mon Nov 28 22:47:29 2016 Bonaldi Jordan
** Last update Sun Dec  4 16:17:00 2016 Bonaldi Jordan
*/

#include "project.h"

void    swap(t_list *l1, t_list *l2)
{
  int   a;
  char  *arr;

  if ((arr = l1->s) && (l1->s = l2->s) && (l2->s = arr)) {}
  if ((arr = l1->r) && (l1->r = l2->r) && (l2->r = arr)) {}
  if ((arr = l1->rtime) && (l1->rtime = l2->rtime) && (l2->rtime = arr)) {}
  if ((arr = l1->time_m) && (l1->time_m = l2->time_m) && (l2->time_m = arr)) {}
  if ((a = l1->time_d) && (l1->time_d = l2->time_d) && (l2->time_d = a)) {}
  if ((arr = l1->time_h) && (l1->time_h = l2->time_h) && (l2->time_h = arr)) {}
  if ((arr = l1->time_s) && (l1->time_s = l2->time_s) && (l2->time_s = arr)) {}
  if (((a = l1->id) ? 1 : 1) && (l1->id = l2->id) && (l2->id = a)) {}
  if ((arr = l1->uid) && (l1->uid = l2->uid) && (l2->uid = arr)) {}
  if ((arr = l1->gr) && (l1->gr = l2->gr) && (l2->gr = arr)) {}
  if (((a = l1->c) ? 1 : 1) && (l1->c = l2->c) && (l2->c = a)) {}
  if ((!(a = l1->size) ? 1 : 1) && (!(l1->size = l2->size) ? 1 : 1) &&
      (!(l2->size = a) ? 1 : 1)) {}
  if ((!(a = l1->is_dir) ? 1 : 1) &&
      (!(l1->is_dir = l2->is_dir) ? 1 : 1) &&
      (!(l2->is_dir = a) ? 1 : 1)) {}
}

Boolean         my_sort_list(t_list     *l)
{
  t_list        *tmp;

  tmp = l;
  while (tmp->n != l)
    {
      if (tmp->n->n != l && my_strcmp_withoutmaj(tmp->n->s, tmp->n->n->s) > 0)
	{
	  swap(tmp->n, tmp->n->n);
	  tmp = l;
	}
      else
	tmp = tmp->n;
    }
  return (true);
}

Boolean         my_sort_list_time(t_list     *l)
{
  t_list        *tmp;

  tmp = l;
  while (tmp->p != l)
    {
      if (tmp->p->p != l &&
	  my_strcmp_withoutmaj(tmp->p->rtime, tmp->p->p->rtime) > 0)
  	{
  	  swap(tmp->p, tmp->p->p);
  	  tmp = l;
  	}
      else
  	tmp = tmp->p;
    }
  return (true);
}

Boolean		my_rev_list(t_list	*l)
{
  t_list	*c;
  t_list	*t;

  c = l;
  while (c->n != l)
    {
      t = c->n;
      c->n = c->p;
      c->p = t;
      c = t;
    }
  return (true);
}
