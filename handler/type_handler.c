/*
** type_handler.c for type_handler in /home/Neferett/PSU_2016_my_ls
** 
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
** 
** Started on  Mon Nov 28 16:32:48 2016 Bonaldi Jordan
** Last update Sun Dec  4 20:22:00 2016 Bonaldi Jordan
*/

#include "project.h"

char		get_type(int a)
{
  char		c;

  if (S_ISREG(a))
    c = '-';
  if ((S_ISREG(a) && (c = '-'))
      || (S_ISDIR(a) && (c = 'd'))
      || (S_ISBLK(a) && (c = 'b'))
      || (S_ISCHR(a) && (c = 'c'))
      || (S_ISFIFO(a) && (c = 'p'))
      || (S_ISLNK(a) && (c = 'l'))) {}
    return (c);
}

char		*get_rights(struct stat s)
{
  char		*str;

  if (!(str = malloc(10 * sizeof(char))))
    my_exit(errno, 33, "type_handler.c\0");
  str[0] = (s.st_mode & S_IRUSR) ? 'r' : '-';
  str[1] = (s.st_mode & S_IWUSR) ? 'w' : '-';
  str[2] = (s.st_mode & S_IXUSR) ? 'x' : '-';
  str[3] = (s.st_mode & S_IRGRP) ? 'r' : '-';
  str[4] = (s.st_mode & S_IWGRP) ? 'w' : '-';
  str[5] = (s.st_mode & S_IXGRP) ? 'x' : '-';
  str[6] = (s.st_mode & S_IROTH) ? 'r' : '-';
  str[7] = (s.st_mode & S_IWOTH) ? 'w' : '-';
  str[8] = (s.st_mode & S_IXOTH) ? ((s.st_mode & S_ISVTX) ? 't' : 'x') : '-';
  str[9] = 0;
  return (str);
}
