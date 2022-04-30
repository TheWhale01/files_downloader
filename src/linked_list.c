#include "downloader.h"

size_t	lstsize(t_list **lst)
{
	size_t len;
	t_list	*tmp;

	if (!lst)
		return (0);
	len = 0;
	tmp = *lst;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

t_list	*create_node(char *str)
{
	t_list *node;

	if (!(node = malloc(sizeof(t_list))))
		return (NULL);
	node->next = NULL;
	node->url = str;
	return (node);
}

void	add_node(t_list **lst, t_list *new)
{
	if (!lst)
		return ;
	new->next = *lst;
	*lst = new;
}

void	clear_list(t_list **lst)
{
	if (!lst || !*lst)
		return ;
	clear_list(&(*lst)->next);
	free((*lst)->url);
	free(*lst);
}