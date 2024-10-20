#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	j = ft_strlen(s1);
	if (i == j)
		return (ft_strdup(""));
	j -= 1;
	while (j > i && ft_strchr(set, s1[j]))
		j--;
	ptr = ft_substr(s1, i, j - i +1);
	return (ptr);
}
