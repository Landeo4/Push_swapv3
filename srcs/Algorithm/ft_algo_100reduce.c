/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_100reduce.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: landeo <landeo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:25:08 by tpotilli          #+#    #+#             */
/*   Updated: 2023/06/29 15:20:02 by landeo           ###   ########.fr       */
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

/*
int		ft_reduce_managera(t_struct *data, int chunk)
{
	int			lita1;
	int			lita2;
	int			lit;
	t_list_a	*la;
	int			compare;

	la = data->la->next;
	lita1 = ft_found_pos_little_first_part(data, chunk);
	lita2 = ft_found_pos_little_last_part(data, chunk);
	if (lita1 <= lita2 && lita1 != -1)
		compare = 0;
	else
		compare = 1;
	ft_printf("compare %d lita1 %d, lita2 %d, chunk %d\n", compare, lita1, lita2, chunk);
	if (compare == 1)
		lit = ft_found_little_100_75(data, lita2, la);
	else if (compare == 0)
		lit = ft_found_little_100_25(data, lita1, chunk);
	if ((compare == 1 && lita2 > 25) || (compare == 0 && lita1 > 25))
		return (-1);
	return (lit);
}
*/

int		ft_reduce_managera(t_struct *data, int chunk)
{
	int			lita1;
	int			lita2;
	int			compare;

	lita1 = ft_found_pos_little_first_part(data, chunk);
	lita2 = ft_found_pos_little_last_part(data, chunk);
	if (lita1 <= lita2 && lita1 != -1)
		compare = 0;
	else
		compare = 1;
	ft_printf("compare %d lita1 %d, lita2 %d, chunk %d\n", compare, lita1, lita2, chunk);
	if ((compare == 1 && lita2 >= 25) || (compare == 0 && lita1 >= 25))
		return (-1);
	if (lita1 == 1 && compare == 0)
		return (-1);
	else if (compare == 1)
		return (lita2);
	else
		return (lita1);
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

void	ft_trie_100_manager(t_struct *data, int chunk, int token)
{
	int			len;
	int			lbnum;
	int			lanum;
	t_list_b	*lb;

	lb = data->lb->next;
	lbnum = ft_found_best_place100(data, lb, data->la->next->num);
	lanum = ft_reduce_managera(data, chunk);
	len = ft_len_listb(data);
	ft_printf("TRIE MANAGER mon lbnum %d, mon lanum %d, len %d\n", lbnum, lanum, len);
	if (token == 1)
		ft_trie_lb_1(lbnum, len ,data, lanum);
	else
		ft_trie_la_1(lanum, len, data, lbnum);
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
			if (nb > 0)
				data = rrr(data);
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
	if (i < len)
	{
		//ft_printf("la %d\n", nb);
		while (i > 0)
		{
			//ft_printf("la %d\n", data->la->next->num);
			if (nb > 0)
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
			if (nb > 0)
				data = rr(data);
			else
				data->lb = rb(data);
			i--;
			nb--;
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
			if (nb > 0)
				data = rrr(data);
			else
				data->la = rra(data);
			i++;
			nb--;
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
			if (nb > 0)
				data = rr(data);
			else
				data->la = ra(data);
			i--;
			nb--;
		}
	}
	else if (i == len)
	{
		while (i > 0)
		{
			if (nb > 0)
				data = rr(data);
			else
				data->la = ra(data);
			i--;
			nb--;
		}
	}
}
