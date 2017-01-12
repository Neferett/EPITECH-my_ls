/*
** flag_handler.c for flag_handler in /home/Neferett/PSU_2016_my_ls
** 
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
** 
** Started on  Sun Nov 27 14:48:37 2016 Bonaldi Jordan
** Last update Sun Dec  4 14:23:31 2016 Bonaldi Jordan
*/

#include "project.h"

static	Boolean		init_flag(t_flag *flag)
{
  flag->l = false;
  flag->R = false;
  flag->d = false;
  flag->r = false;
  flag->t = false;
  flag->help = false;
  flag->path = NULL;
  return (true);
}

static Boolean	set_flag(char **argv, t_flag *flag)
{
  int		i;

  i = 0;
  flag->path = malloc(1);
  *flag->path = 0;
  while (argv[++i])
    if (*argv[i] == '-' && *(argv[i] + 1) == '-' && (argv[i] += 2) &&
	!my_strcmp(argv[i], "help\0") && (flag->help = true)) {}
    else if (*argv[i] == '-' && (++argv[i]))
      while (*argv[i])
	if ((*argv[i] == 'l' ? (flag->l = true) : *argv[i] == 'R' ?
	     (flag->R = true) : *argv[i] == 'd' ? (flag->d = true) :
	     *argv[i] == 'r' ? (flag->r = true) : *argv[i] == 't' ?
	     (flag->t = true) : wrong_flag(*argv[i], flag)) && argv[i]++) {}
	else
	  argv[i]++;
    else
      {
	if (!*flag->path && (flag->path = my_strdup(argv[i]))) {}
	else if ((flag->path = my_strcat(flag->path, " ")) &&
		 (flag->path = my_strcat(flag->path, argv[i]))) {}
      }
  return (true);
}

t_flag		*handle_flag(int argc, char **argv)
{
  t_flag	*flag;

  if (!(flag = malloc(sizeof(t_flag))))
    my_exit(errno, 57, "flag_handler.c\0");
  init_flag(flag);
  if (argc == 1 && (flag->path = my_strdup((argv[1] ? argv[1] : ".\0"))))
    return (flag);
  else if (set_flag(argv, flag)) {}
  if (!*flag->path && (flag->path = my_strdup(".\0"))) {}
  return (flag);
}
