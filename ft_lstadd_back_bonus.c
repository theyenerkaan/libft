#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*l_ptr;

	if (!lst || !(*lst))
	{
		*lst = new;
		return ;
	}
	l_ptr = ft_lstlast(*lst);
	l_ptr->next = new;
}
