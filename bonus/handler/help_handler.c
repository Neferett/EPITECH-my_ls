/*
** help_handler.c for help_handler in /home/Neferett/PSU_2016_my_ls
** 
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
** 
** Started on  Sun Nov 27 20:34:05 2016 Bonaldi Jordan
** Last update Sun Dec  4 13:54:58 2016 Bonaldi Jordan
*/

#include "project.h"

Boolean		help_handler(t_flag *flag)
{
  my_printf("Usage: my_ls [OPTION]... [FILE]...\n");
  my_printf("List information about the FILEs "
"(the current directory by default).\n");
  my_printf("Sort entries alphabetically if none -t is specified.\n\n");
  my_printf("Mandatory arguments to long options "
"are mandatory for short options too.\n");
  my_printf("  -l\tuse long listing format\n");
  my_printf("  -R\tlist subdirectories recursively\n");
  my_printf("  -d\tlist directories "
	    "themselves, not their contents\n");
  my_printf("  -r\treverse order while sorting\n");
  my_printf("  -t\tsort by modification time, newest first\n");
  free_flag(flag);
  return (true);
}
