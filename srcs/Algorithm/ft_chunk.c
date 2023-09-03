#include "push_swap.h"

int	ft_chunk_helper(t_struct *data, int compare, int little)
{
	ft_take_first_second_algo100(data, compare, little);
	if (ft_len_listb(data) == 2)
		if (data->lb->next->num < data->lb->next->next->num)
			data->lb = rrb(data);
	return (0);
}

int	ft_chunk(t_struct *data, int moyenne, int token)
{
	int			littlech1;
	int			littlech2;
	int			compare;
	int			little;
	t_list_a	*la;

	la = data->la->next;
	littlech1 = ft_found_pos_little_first_part(data, moyenne);
	littlech2 = ft_found_pos_little_last_part(data, moyenne);
	if (littlech1 <= littlech2 && littlech1 != -1)
		compare = 0;
	else
		compare = 1;
	if (compare == 1)
		little = ft_found_little_100_75(data, littlech2, la);
	else if (compare == 0)
		little = ft_found_little_100_25(data, littlech1, moyenne);
	if (token < 2)
		return (ft_chunk_helper(data, compare, little), 0);
	if ((compare == 1 && littlech2 >= 15) || (compare == 0 && littlech1 >= 15))
		return (ft_wrong_little(data, littlech1, moyenne, compare), 0);
	ft_take_100alg(data, compare, little, moyenne);
	return (0);
}