#include "list.h"

t_list  *sort_list(t_list* lst, int (*cmp)(int, int))
{
	int swap;
	int tmp_data;
	t_list *tmp;

	swap = 1;
	if (lst == 0)
		return (0);
	while (swap)
	{
		swap = 0;
		tmp = lst;

		while(tmp -> next)
		{
			if (cmp(tmp->data, tmp->next->data) == 0)
			{
				tmp_data = tmp->data;
				tmp->data = tmp->next->data;
				tmp->next->data = tmp_data;
				swap = 1;
			}
			tmp = tmp->next;
		}
	}
	return (tmp);
}
