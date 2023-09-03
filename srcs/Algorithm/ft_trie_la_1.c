#include "push_swap.h"

void	ft_trie_la_1(int i, int len, t_struct *data, int nb)
{
	(void)nb;
	len = len / 2;
	if (i > len)
	{
		len = ft_len_lista(data);
		while (len > i)
		{
			data->la = rra(data);
			i++;
		}
	}
	else if (i < len || i == len)
		ft_trie_la_1helper(i, len, data, nb);
}

void	ft_trie_la_1helper(int i, int len, t_struct *data, int nb)
{
	(void)nb;
	if (i < len)
	{
		while (i > 0)
		{
			data->la = ra(data);
			i--;
		}
	}
	else if (i == len)
	{
		while (i > 0)
		{
			data->la = ra(data);
			i--;
		}
	}
}
