#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	while (*ptr)
	{
		if ((char) c == *ptr)
			return (ptr);
		ptr++;
	}
	if ((char) c == 0)
		return (ptr);
	return (NULL);
}
