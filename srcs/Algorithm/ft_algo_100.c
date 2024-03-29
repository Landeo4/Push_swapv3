/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_100.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceatgie <ceatgie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:19:06 by tpotilli          #+#    #+#             */
/*   Updated: 2023/09/03 10:52:47 by ceatgie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	This function takes as parameter: 
**
**	data
**
** =====================================================
** =====================================================
**
** ft_algo_50 will sort all input under 100 except 10 and less
*/

void	ft_algo_100_manager(t_struct *data, int argc)
{
	int			moyennech1;
	int			token;
	int			i;
	int			first;

	i = 0;
	token = 1;
	first = 0;
	while (token != 6)
	{
		moyennech1 = ft_helper100man(token, moyennech1, data, argc);
		while (i < 20)
		{
			i++;
			ft_chunk(data, moyennech1, first);
			ft_printf("moyenne %d\n", moyennech1);
			first++;
			//ft_print_listb(data);
			if (ft_len_lista(data) == 0)
				break ;
		}
		i = 0;
		token++;
	}
	ft_algo100manager_helper2(data);
}

int	ft_algo100manager_helper2(t_struct *data)
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

int	ft_helper100man(int token, int moyennech1, t_struct *data, int argc)
{
	int			len;
	t_list_a	*la;

	la = data->la->next;
	len = ft_len_lista(data);
	moyennech1 = ft_somme_algo_100(la, argc, token, len);
	return (moyennech1);
}

void	ft_wrong_little(t_struct *data, int lit1, int moyenne, int compare)
{
	int	little;
	int	lit2;

	lit2 = ft_found_pos_little_last_part(data, moyenne);
	if (compare == 1 && lit2 >= 15)
	{
		little = data->la->next->num;
		lit1 = ft_trie_100_b_little(data, little);
		lit2 = ft_trie_100_b_biggest(data, little);
		ft_100_swap_manager(data, lit1, lit2, moyenne);
		return ;
	}
	else if (compare == 0 && lit1 >= 15)
	{
		little = data->la->next->num;
		lit1 = ft_trie_100_b_little(data, little);
		lit2 = ft_trie_100_b_biggest(data, little);
		ft_100_swap_manager(data, lit1, lit2, moyenne);
		return ;
	}
}
