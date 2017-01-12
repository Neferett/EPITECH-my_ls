/*
** utils_error.c for my_exit in /home/Neferett/PSU_2016_my_ls
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Sun Dec  4 14:16:14 2016 Bonaldi Jordan
** Last update Sun Dec  4 15:44:58 2016 Bonaldi Jordan
*/

#include <errno.h>
#include "lib.h"
#include "printf.h"

void	my_exit(int errno, int line, char *file)
{
  my_printf("Exception error(%d): %s:%d\n", errno, file, line);
  exit(84);
}
