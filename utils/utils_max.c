/*
** utils_max.c for max in /home/Neferett/PSU_2016_my_ls
** 
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
** 
** Started on  Wed Nov 30 22:30:11 2016 Bonaldi Jordan
** Last update Thu Dec  1 10:26:46 2016 Bonaldi Jordan
*/

#include "project.h"

int	gms(t_list *l)
{
  int	i;
  t_list	*tmp;

  tmp = l;
  i = 0;
  while (tmp->n != l)
    {
      if (tmp->n->size >= i &&
	  tmp->n->size >= tmp->n->n->size && (i = tmp->n->size)) {}
      tmp = tmp->n;
    }
  return (mil(i));
}

int	gmu(t_list *l)
{
  int	i;
  t_list	*tmp;

  tmp = l;
  i = 0;
  while (tmp->n != l)
    {
      if (tmp->n->id >= i &&
	  tmp->n->id >= tmp->n->n->id && (i = tmp->n->id)) {}
      tmp = tmp->n;
    }
  return (mil(i));
}

int	get_max_s(t_list *l)
{
  t_list	*tmp;
  int	i;
  int	tempi;
  int	tempj;

  tmp = l;
  i = 0;
  while (tmp->n != l)
    {
      tempi = tmp->n->time_d;
      tempj = tmp->n->n->time_d;
      if (tempi >= i && tempi >= tempj && (i = tempi)) {}
      tmp = tmp->n;
    }
  return (mil(i));
}
