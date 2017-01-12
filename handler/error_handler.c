/*
** error_handler.c for error_handler in /home/Neferett/PSU_2016_my_ls
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Sun Nov 27 15:11:10 2016 Bonaldi Jordan
** Last update Sun Dec  4 17:33:11 2016 Bonaldi Jordan
*/

#include "project.h"

Boolean		wrong_flag(char c, t_flag *flag)
{
  if (!flag->help)
    {
      my_printf("my_ls: invalid option -- '%c'\n", c);
      my_printf("Try './my_ls --help' for more information\n");
      free_flag(flag);
    }
  exit(0);
  return (true);
}

void		handle_error(int e, char *path)
{
  if (e == 2 &&
      my_printf("my_ls: cannot access '%s': %s\n", path, strerror(e))) {}
  else if (e == 13 &&
	   my_printf("my_ls: cannot open directory '%s': %s\n",
		     path, strerror(e))) {}
  else if (my_printf("my_ls: cannot access '%s': %s\n",
		     path, strerror(e))) {}
}
