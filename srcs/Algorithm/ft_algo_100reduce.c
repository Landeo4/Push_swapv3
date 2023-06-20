/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_100reduce.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:25:08 by tpotilli          #+#    #+#             */
/*   Updated: 2023/06/20 22:55:10 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	This function takes as parameter: 
**
**	data
**	chunk
** =====================================================
** =====================================================
**
** ft_reduce_managera is used to take the position of the
** little a to able the use of rr or rrr
*/

int		ft_reduce_managera(t_struct *data, int chunk)
{
	int			lita1;
	int			lita2;
	int			lit;
	t_list_a	*la;

	la = data->la->next;
	lita1 = ft_found_pos_little_first_part(data, chunk, la);
	lita2 = ft_found_pos_little_last_part(data, chunk, la);
	if (lita1 < lita2)
		lit = lita1;
	else if (lita1 >= lita2)
	{
		lit = lita2;
		lita2 = lita2 * -1;
	}
	//ft_printf("mon lita1 = %d, mopn lita2 = %d\n donc lit = %d", lita1, lita2, lit);
	return (lit);
}

/*int		ft_reduce_managerb(t_struct *data)
{
	int			lita1;
	int			lita2;
	int			compare;
	int			lit;
	t_list_a	*la;

	la = data->la->next;
	lita1 = ft_found_pos_little_first_part(data, chunk, la);
	lita2 = ft_found_pos_little_last_part(data, chunk, la);
	if (lita1 < lita2)
		lit = lita1;
	else if (lita1 >= lita2)
	{
		lit = lita2;
		lita2 = lita2 * -1;
	}
	return (lit)
}
*/

void	ft_trie_lb_1(int i, int len, t_struct *data, int nb)
{
	if (i > len)
	{
		len = ft_len_listb(data);
		while (len > i)
		{
			if (nb > 1)
				data = rr(data);
			else
				data->lb = rrb(data);
			i++;
			nb--;
		}
	}
	else if (i < len || i == len)
		ft_trie_lb_1helper(i, len, data, nb);
}

void	ft_trie_lb_1helper(int i, int len, t_struct *data, int nb)
{
	if (i > len)
		return ;
	if (i < len)
	{
		while (i > 0)
		{
			if (nb > 1)
				data = rr(data);
			else
				data->lb = rb(data);
			i--;
			nb--;
		}
	}
	else if (i == len)
	{
		while (i > 0)
		{
			if (nb > 1)
				data = rr(data);
			else
				data->lb = rb(data);
			i--;
			nb--;
		}
	}
}

void	ft_trie_lb_0(int i, int len, t_struct *data, int nb)
{
	nb = nb * -1;
	if (i > len)
	{
		len = ft_len_listb(data);
		while (len > i)
		{
			if (nb > 1)
				data = rrr(data);
			else
				data->lb = rrb(data);
			i++;
			nb--;
		}
	}
	else if (i < len || i == len)
		ft_trie_lb_0helper(i, len, data, nb);
}

void	ft_trie_lb_0helper(int i, int len, t_struct *data, int nb)
{
	if (i > len)
		return ;
	if (i < len)
	{
		while (i > 0)
		{
			if (nb > 1)
				data = rrr(data);
			else
				data->lb = rb(data);
			i--;
			nb--;
		}
	}
	else if (i == len)
	{
		while (i > 0)
		{
			if (nb > 1)
				data = rrr(data);
			else
				data->lb = rb(data);
			i--;
			nb--;
		}
	}
}
