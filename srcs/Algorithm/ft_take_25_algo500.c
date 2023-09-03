#include "push_swap.h"

void	ft_take_25_algo500(t_struct *data, int compare, int little, int chunk)
{
	int		nb;
	int		len;

	(void)chunk;
	(void)nb;
	len = ft_len_listb(data);
	len = len / 2;
	//nb = best_place_manager(data, little);
	//ft_printf("nb %d, little %d, len %d, nb2 %d\n", nb, little, len);
	ft_take_25_helper500(data, little, compare);
	//lit1 = ft_trie_500_b_little(data, little);
	//lit2 = ft_trie_500_b_biggest(data, little);
	data->la = pb(data);
	//ft_printf("checkpoint la placer\n");
	//ft_printf("%d dasdasdasd\n", data->la->next->num);
	//ft_500_swap_manager(data, lit1, lit2, chunk);
}

/*void	ft_take_25_algo500(t_struct *data, int compare, int little, int chunk)
{
	int		lit1;
	int		lit2;
	int		nb;
	int		len;

	len = ft_len_listb(data);
	len = len / 2;
	nb = best_place_manager(data, little);
	//ft_printf("nb %d, little %d, len %d, nb2 %d\n", nb, little, len);
	if (ft_len_lista(data) == 1)
		lit1 = 0;
	ft_take_25_helper500(data, little, nb, compare);
	lit1 = ft_trie_500_b_little(data, little);
	lit2 = ft_trie_500_b_biggest(data, little);
	//ft_printf("checkpoint la placer\n");
	ft_printf("%d dasdasdasd\n", data->la->next->num);
	ft_500_swap_manager(data, lit1, lit2, chunk);
}*/

void	ft_take_25_helper500(t_struct *data, int little, int compare)
{
	int	nb2;
	int	len;

	(void)nb2;
	len = ft_len_listb(data);
	len = len / 2;
	//nb2 = ft_best_place_b_mang500(data, little);
	//ft_printf("nb2 = %d\n", nb2);
	if (compare == 1)
	{
		while (data->la->next->num != little)
		{
			data->la = rra(data);
			//nb--;
		}
		return ;
	}
	else
	{
		while (data->la->next->num != little)
		{
			data->la = ra(data);
		//	nb++;
		}
	}
}