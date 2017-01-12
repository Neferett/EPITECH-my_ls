/*
** utils.c for utils in /home/Neferett/PSU_2016_my_ls
** 
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
** 
** Started on  Sun Nov 27 20:53:32 2016 Bonaldi Jordan
** Last update Sun Dec  4 14:26:16 2016 Bonaldi Jordan
*/

#include "project.h"

Boolean		free_flag(t_flag *flag)
{
  free(flag->path);
  free(flag);
  return (true);
}

Boolean		free_list(t_list *l)
{
  t_list	*tmp2;
  t_list	*tmp;

  tmp = l;
  tmp2 = NULL;
  while (tmp->n != l)
    {
      tmp2 = tmp->n;
      free(tmp->n->s);
      free(tmp->n->r);
      free(tmp->n->time_m);
      free(tmp->n->time_h);
      free(tmp->n->time_s);
      free(tmp->n->rtime);
      free(tmp->n->uid);
      free(tmp->n->gr);
      free(tmp);
      tmp = tmp2;
    }
  return (true);
}

Boolean		free_t_l_t_l(t_l_t_l *l)
{
  t_l_t_l	*tmp2;
  t_l_t_l	*tmp;

  tmp = l;
  tmp2 = NULL;
  while (tmp->n != l)
    {
      tmp2 = tmp->n;
      free_list(tmp->n->l);
      free(tmp->n->s);
      free(tmp);
      tmp = tmp2;
    }
  return (true);
}

Boolean		free_all(t_l_t_l *l, t_flag *f, char **t)
{
  free_flag(f);
  free_t_l_t_l(l);
  while (*t)
    {
      free(*t);
      t++;
    }
  return (true);
}

int		my_size_tab(char **tab)
{
  return (*tab ? my_size_tab(++tab) + 1 : 0);
}
