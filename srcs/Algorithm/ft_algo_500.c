/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_500.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: landeo <landeo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 13:27:25 by tpotilli          #+#    #+#             */
/*   Updated: 2023/07/06 13:28:16 by landeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// if i loose it all sleep and fall

void	ft_algo_500_manager(t_struct *data, int argc)
{
	int			moyennech1;
	int			token;
	int			i;
	int			first;

	i = 0;
	token = 1;
	first = 0;
	while (token != 100)
	{
		moyennech1 = ft_helper500man(token, moyennech1, data, argc);
		while (i < 500)
		{
			i++;
			first++;
			if (ft_len_lista(data) == 0)
				break ;
			if (ft_chunk500(data, moyennech1, first) == -1)
				break ;
			//ft_print_listb(data);
		}
		if (ft_len_lista(data) == 0)
			break ;
		i = 0;
		token++;
	}
	ft_algo500manager_helper2(data);
}

int	ft_algo500manager_helper2(t_struct *data)
{
	int	len;

	len = ft_len_listb(data);
	ft_make_list_right100(data, len);
	while (len > 0)
	{
		data->lb = pa(data);
		len--;
	}
	return (0);
}

int	ft_helper500man(int token, int moyennech1, t_struct *data, int argc)
{
	int			len;
	t_list_a	*la;

	la = data->la->next;
	len = ft_len_lista(data);
	moyennech1 = ft_somme_algo_500(la, argc, token, len);
	return (moyennech1);
}

int	ft_chunk500(t_struct *data, int moyenne, int token)
{
	int			littlech1;
	int			littlech2;
	int			compare;
	int			little;
	t_list_a	*la;

	la = data->la->next;
	littlech1 = ft_found_pos_little_first_part500(data, moyenne);
	littlech2 = ft_found_pos_little_last_part500(data, moyenne);
	if (littlech1 <= littlech2 && littlech1 != -1)
		compare = 0;
	else
		compare = 1;
	if (compare == 1)
		little = ft_found_little_500_75(data, littlech2, la);
	else if (compare == 0)
		little = ft_found_little_500_25(data, littlech1, moyenne);
	//ft_printf("little %d, compare %d, littlech1 %d, littlech2 %d, moyenne %d\n", little, compare, littlech1, littlech2, moyenne);
	ft_printf("%d\n", little);
	if (token < 3)
		return (ft_chunk_helper500(data, compare, little), 0);
	while (ft_opti_manager(data, little) == -1)
	{
		little = la->num;
		la = la->next;
	}
	if ((compare == 1 && littlech2 >= 15) || (compare == 0 && littlech1 >= 15))
		return (-1);
	ft_take_25_algo500(data, compare, little, moyenne);
	return (0);
}

int	ft_chunk_helper500(t_struct *data, int compare, int little)
{
	ft_take_first_second_algo500(data, compare, little);
	if (ft_len_listb(data) == 2)
		if (data->lb->next->num < data->lb->next->next->num)
			data->lb = rrb(data);
	return (0);
}
