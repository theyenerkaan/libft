#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	if (!dest && !src)
		return (dest);
	if (dest <= src)
		return (ft_memcpy(dest, src, len));
	else
	{
		while (len--)
		{
			((char *)dest)[len] = ((char *)src)[len];
		}
	}
	return (dest);
}
