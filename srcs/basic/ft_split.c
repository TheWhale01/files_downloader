#include <stdlib.h>

int is_in(char c, char *charset)
{
	int i;

	i = -1;
	while (charset[++i] != '\0')
		if (charset[i] == c)
			return (1);
	return (0);
}

int count_words(char *str, char *charset)
{
	int i;
	int words;

	i = -1;
	words = 0;
	while (str[++i] != '\0')
		if (is_in(str[i], charset) == 0 && is_in(str[i + 1], charset) == 1)
			words++;
	if (is_in(str[i - 1], charset) == 0)
		return (words + 1);
	return (words);
}

int word_len(char *str, char *charset, int word_num)
{
	int i;

	i = word_num;
	while (is_in(str[i], charset) == 0 && str[i])
		i++;
	return (i);
}

char **ft_split(char *str, char *charset)
{
	int i;
	int j;
	int k;
	char **string;

	if (!(string = malloc(sizeof(char *) * (count_words(str, charset) + 1))))
		return (0);
	i = -1;
	k = 0;
	while (++i < count_words(str, charset) && str[k])
	{
		while (is_in(str[k], charset) == 1)
			k++;
		if (!(string[i] = malloc(sizeof(char) * word_len(str, charset, k) + 1)))
			return (0);
		j = 0;
		while (is_in(str[k], charset) == 0 && str[k])
			string[i][j++] = str[k++];
		string[i][j] = '\0';
	}
	string[i] = 0;
	return (string);
}
