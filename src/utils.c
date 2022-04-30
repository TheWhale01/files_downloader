#include "downloader.h"

char	*get_filename(char *url)
{
	int end;

	end = strlen(url) -1;
	while (end > 0 && url[end - 1] != '/')
		end--;
	return (&url[end]);
}


char	*ft_strjoin(char *s1, char *s2)
{
	size_t	lens1;
	size_t	lens2;
	char	*s3;

	lens1 = 0;
	lens2 = 0;
	if (s1)
		lens1 = strlen(s1);
	if (s2)
		lens2 = strlen(s2);
	s3 = malloc((lens1 + lens2 + 1) * sizeof(char));
	if (!s3)
		return (NULL);
	memcpy(s3, s1, lens1);
	memcpy(s3 + lens1, s2, lens2);
	s3[lens1 + lens2] = '\0';
	if (s1)
		free(s1);
	return (s3);
}