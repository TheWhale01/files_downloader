#ifndef __LIB_H__
#define __LIB_H__

#include <curl/curl.h>

#define STDIN 0
#define STDOUT 1
#define STDERR 2
#define BUFF_LEN 2048

/*    BASIC    */

int ft_strlen(char *str);

void ft_putchar(char c);
void ft_putstr(char *str);
void ft_fputstr(char *str, int output);

char **ft_split(char *str, char *charset);

/*    PARSER    */

int get_fd(int ac, char **av);
void print_error(char *filename, int fd, CURLcode code);

/*    FILE.C    */

char **read_file(int fd);

/*    DL.C    */

int dl_file(char *url);

#endif
