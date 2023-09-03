#include "push_swap.h"

void	ft_trie_lb_1(int i, int len, t_struct *data, int nb)
{
	(void)nb;
	len = len / 2;
	if (i > len)
	{
		len = ft_len_listb(data);
		while (len > i)
		{
			data->lb = rrb(data);
			i++;
		}
	}
	else if (i < len || i == len)
		ft_trie_lb_1helper(i, len, data, nb);
}

void	ft_trie_lb_1helper(int i, int len, t_struct *data, int nb)
{
	(void)nb;
	if (i < len)
	{
		while (i > 0)
		{
				data->lb = rb(data);
			i--;
		}
	}
	else if (i == len)
	{
		while (i > 0)
		{
				data->lb = rb(data);
			i--;
		}
	}
}