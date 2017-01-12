/*
** utils_lists.c for list2_utils in /home/Neferett/PSU_2016_my_ls
** 
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
** 
** Started on  Wed Nov 30 21:31:27 2016 Bonaldi Jordan
** Last update Thu Dec  1 10:45:49 2016 Bonaldi Jordan
*/

#include "project.h"

t_l_t_l  *create_t_l_t()
{
  t_l_t_l        *c;

  if ((c = malloc(sizeof(*c)))
      && (c->n = c) && (c->p = c)) {}
  return (c);
}
