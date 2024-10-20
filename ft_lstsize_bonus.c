#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	lstlen;

	if (!lst)
		return (0);
	lstlen = 1;
	while (lst->next)
	{
		lst = lst->next;
		lstlen++;
	}
	return (lstlen);
}
