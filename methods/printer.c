/*
** printer.c for printer in /home/Neferett/PSU_2016_my_ls
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Wed Nov 30 21:39:12 2016 Bonaldi Jordan
** Last update Sun Dec  4 20:25:31 2016 Bonaldi Jordan
*/

#include "project.h"

void		printer_ls(t_list *tmp, t_flag *f)
{
  if (!my_strcmp(f->r ? tmp->p->time_y : tmp->n->time_y, "2016"))
    my_printf("%c%s %d %s %s %d %s %d %s:%s %s\n",
	      f->r ? tmp->p->c : tmp->n->c,
	      f->r ? tmp->p->r : tmp->n->r,
	      f->r ? tmp->p->id : tmp->n->id, f->r ? tmp->p->uid : tmp->n->uid,
	      f->r ? tmp->p->gr : tmp->n->gr,
	      f->r ? tmp->p->size : tmp->n->size,
	      f->r ? tmp->p->time_m : tmp->n->time_m,
	      f->r ? tmp->p->time_d : tmp->n->time_d,
	      f->r ? tmp->p->time_h : tmp->n->time_h,
	      f->r ? tmp->p->time_s : tmp->n->time_s,
	      f->r ? tmp->p->s : tmp->n->s);
  else
    my_printf("%c%s %d %s %s %d %s %d %s %s\n",
	      f->r ? tmp->p->c : tmp->n->c,
	      f->r ? tmp->p->r : tmp->n->r,
	      f->r ? tmp->p->id : tmp->n->id, f->r ? tmp->p->uid : tmp->n->uid,
	      f->r ? tmp->p->gr : tmp->n->gr,
	      f->r ? tmp->p->size : tmp->n->size,
	      f->r ? tmp->p->time_m : tmp->n->time_m,
	      f->r ? tmp->p->time_d : tmp->n->time_d,
	      f->r ? tmp->p->time_y : tmp->n->time_y,
	      f->r ? tmp->p->s : tmp->n->s);
}

void		printer_not_dir(t_list *l, t_flag *f)
{
  t_list	*tmp;

  tmp = l;
  while (f->r ? tmp->p != l : tmp->n != l)
    {
      if (f->l && (f->r ? *(tmp->p->s) != '.' : *(tmp->n->s) != '.'))
	printer_ls(tmp, f);
      else
	if (f->r ? *(tmp->p->s) != '.' : *(tmp->n->s) != '.')
	  my_printf("%s\n", f->r ? tmp->p->s : tmp->n->s);
      f->r ? (tmp = tmp->p) : (tmp = tmp->n);
    }
}

Boolean	ls_printer(t_l_t_l *l, t_flag *f, int size)
{
  t_l_t_l	*tmp;

  tmp = l;
  while (tmp->p != l)
    {
      if (size > 1 && my_printf("%s:\n", tmp->p->s)) {}
      if (f->l && my_printf("total %u\n", tmp->p->i)) {}
      printer_not_dir(tmp->p->l, f);
      if (tmp->p->p != l && size > 1 && my_printf("\n")) {}
      tmp = tmp->p;
    }
  return (true);
}
