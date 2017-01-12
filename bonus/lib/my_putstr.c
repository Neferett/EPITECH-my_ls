/*
** my_putstr.c for my_putstr in /home/Neferett/CPool_Day04
** 
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
** 
** Started on  Thu Oct  6 09:21:58 2016 Bonaldi Jordan
** Last update Sun Nov 13 21:12:28 2016 Bonaldi Jordan
*/

#include "lib.h"

int	my_putstr(char *str)
{
  if (str && *str)
    {
      my_putchar(*str);
      my_putstr(str + 1);
    }
  return (0);
}
