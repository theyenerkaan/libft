#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if ((char) c == s[i])
		{
			s += i;
			return ((char *)s);
		}
		i--;
	}
	return (NULL);
}
