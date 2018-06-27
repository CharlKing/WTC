#include <unistd.h>

int	ft_list_size(t_list *begin_list)
{
	int count = 0;

	while(begin_list->next != '\0')_
	{
		begin_list->next++;
		count++;
	}
	return (count);
}
