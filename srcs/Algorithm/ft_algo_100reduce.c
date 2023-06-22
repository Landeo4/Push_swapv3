/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_100reduce.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:25:08 by tpotilli          #+#    #+#             */
/*   Updated: 2023/06/22 17:29:10 by tpotilli         ###   ########.fr       */
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
	int			compare;

	la = data->la->next;
	lita1 = ft_found_pos_little_first_part(data, chunk, la);
	lita2 = ft_found_pos_little_last_part(data, chunk, la);
	if (lita1 <= lita2)
		compare = 0;
	else
		compare = 1;
	if (compare == 1)
		lit = ft_found_little_100_75(data, lita2, la);
	else if (compare == 0)
		lit = ft_found_little_100_25(data, lita1, chunk);
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

void	ft_trie_100_manager(t_struct *data, int chunk)
{
	int			len;
	int			lbnum;
	int			lanum;
	t_list_b	*lb;

	lb = data->lb->next;
	lbnum = ft_found_best_place100(data, lb);
	lanum = ft_reduce_managera(data, chunk);
	ft_printf("TRIE MANAGER mon lbnum %d, mon lanum %d\n", lbnum, lanum);
	len = ft_len_listb(data);
	if (lbnum > lanum)
		ft_trie_lb_1(lbnum, len ,data, lanum);
	else if (lbnum < lanum)
		ft_trie_lb_0(lbnum, len ,data, lanum);
}

void	ft_trie_lb_1(int i, int len, t_struct *data, int nb)
{
	//ft_printf("nb %d dans lb1\n", nb);
	len = len / 2;
	if (i > len)
	{
		len = ft_len_listb(data);
		while (len > i)
		{
			if (nb != data->la->next->num)
				data = rrr(data);
			else
				data->lb = rrb(data);
			i++;
		}
	}
	else if (i < len || i == len)
		ft_trie_lb_1helper(i, len, data, nb);
}

void	ft_trie_lb_1helper(int i, int len, t_struct *data, int nb)
{
	if (i < len)
	{
		while (i > 0)
		{
			if (nb != data->la->next->num)
				data = rr(data);
			else
				data->lb = rb(data);
			i--;
		}
	}
	else if (i == len)
	{
		while (i > 0)
		{
			if (nb != data->la->next->num)
				data = rr(data);
			else
				data->lb = rb(data);
			i--;
		}
	}
}

void	ft_trie_lb_0(int i, int len, t_struct *data, int nb)
{
	//ft_printf("nb %d dans lb0\n", nb);
	len = len / 2;
	if (i > len)
	{
		len = ft_len_listb(data);
		while (len > i)
		{
			if (nb != data->la->next->num)
				data = rrr(data);
			else
				data->lb = rrb(data);
			i++;
		}
	}
	else if (i < len || i == len)
		ft_trie_lb_0helper(i, len, data, nb);
}

void	ft_trie_lb_0helper(int i, int len, t_struct *data, int nb)
{
	if (i < len)
	{
		while (i > 0)
		{
			if (nb != data->la->next->num)
				data = rr(data);
			else
				data->lb = rb(data);
			i--;
		}
	}
	else if (i == len)
	{
		while (i > 0)
		{
			if (nb != data->la->next->num)
				data = rr(data);
			else
				data->lb = rb(data);
			i--;
		}
	}
}

void	ft_trie_la_1(int i, int len, t_struct *data, int nb)
{
	//ft_printf("nb %d dans la1\n", nb);
	len = len / 2;
	if (i > len)
	{
		len = ft_len_lista(data);
		while (len > i)
		{
			if (nb != data->la->next->num)
				data = rrr(data);
			else
				data->la = rra(data);
			i++;
		}
	}
	else if (i < len || i == len)
		ft_trie_lb_1helper(i, len, data, nb);
}

void	ft_trie_la_1helper(int i, int len, t_struct *data, int nb)
{
	if (i < len)
	{
		while (i > 0)
		{
			if (nb != data->la->next->num)
				data = rr(data);
			else
				data->la = ra(data);
			i--;
		}
	}
	else if (i == len)
	{
		while (i > 0)
		{
			if (nb != data->la->next->num)
				data = rr(data);
			else
				data->la = ra(data);
			i--;
		}
	}
}

void	ft_trie_la_0(int i, int len, t_struct *data, int nb)
{
	//ft_printf("nb %d dans la0\n", nb);
	len = len / 2;
	if (i > len)
	{
		len = ft_len_lista(data);
		while (len > i)
		{
			if (nb != data->la->next->num)
				data = rrr(data);
			else
				data->la = rra(data);
			i++;
		}
	}
	else if (i < len || i == len)
		ft_trie_lb_0helper(i, len, data, nb);
}

void	ft_trie_la_0helper(int i, int len, t_struct *data, int nb)
{
	if (i < len)
	{
		while (i > 0)
		{
			if (nb != data->la->next->num)
				data = rr(data);
			else
				data->la = ra(data);
			i--;
		}
	}
	else if (i == len)
	{
		while (i > 0)
		{
			if (nb != data->la->next->num)
				data = rr(data);
			else
				data->la = ra(data);
			i--;
		}
	}
}