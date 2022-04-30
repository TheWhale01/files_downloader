#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <readline/readline.h>

#define BUFFER_SIZE 2048

typedef struct s_list
{
	int	fd;
	int	mb;
	char *url;
	char *filename;
	struct s_list *next;
}	t_list;

typedef struct s_data
{
	char *line;
	CURL *curl;
	t_list *urls;
} t_data;

int	line_len(char *str);

char	*get_next_line(int fd);
char	*get_filename(char *url);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);

void	dl_file(t_data *data);
void	free_data(t_data *data);
void	clear_list(t_list **lst);
void	create_files(t_data *data);
void 	make_connection(t_data *data);
void	add_node(t_list **lst, t_list *new);
void	safe_exit(int exit_code, char *exit_msg, t_data *data);

size_t	lstsize(t_list **lst);
size_t	ft_strlen(const char *str);

t_list	*create_node(char *str);

#endif
