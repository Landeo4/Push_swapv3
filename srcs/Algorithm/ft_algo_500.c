/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_500.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 13:27:25 by tpotilli          #+#    #+#             */
/*   Updated: 2023/06/18 17:49:19 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_algo_500_manager(t_struct *data, int argc)
{
	int			moyennech1;
	int			token;
	int			i;
	int			first;

	i = 0;
	token = 1;
	first = 0;
	while (token != 12)
	{
		moyennech1 = ft_helper500man(token, moyennech1, data, argc);
		while (i < 45)
		{
			i++;
			ft_chunk(data, moyennech1, first);
			first++;
		}
		i = 0;
		token++;
	}
	ft_alg500_last(data, moyennech1, first);
	ft_algo500manager_helper2(data);
}

void	ft_alg500_last(t_struct *data, int moyennech1, int first)
{
	int	len;

	len = ft_len_lista(data);
	while (len != 0)
	{
		ft_chunk(data, moyennech1, first);
		len--;
	}
}

int	ft_algo500manager_helper2(t_struct *data)
{
	int	len;

	len = ft_len_listb(data);
	ft_make_list_right500(data, len);
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

int	ft_chunk_500(t_struct *data, int moyenne, int token)
{
	int			littlech1;
	int			littlech2;
	int			compare;
	int			little;
	t_list_a	*la;

	la = data->la->next;
	littlech1 = ft_found_pos_little_first_part500(data, moyenne, la);
	littlech2 = ft_found_pos_little_last_part500(data, moyenne, la);
	if (littlech1 >= littlech2)
		compare = 0;
	else
		compare = 1;
	if (compare == 1)
		little = ft_found_little_500_75(data, littlech2, la);
	else if (compare == 0)
		little = ft_found_little_500_25(data, littlech1, moyenne);
	if (token < 2)
	{
		ft_chunk_helper(data, compare, little);
		return (0);
	}
	ft_take_25_algo500(data, compare, little);
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
