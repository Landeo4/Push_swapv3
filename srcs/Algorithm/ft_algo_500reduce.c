/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_500reduce.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotillion <tpotillion@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:25:08 by tpotilli          #+#    #+#             */
/*   Updated: 2023/08/31 02:47:00 by tpotillion       ###   ########.fr       */
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

int	ft_reduce_managera500(t_struct *data, int chunk)
{
	int			lita1;
	int			lita2;
	int			compare;

	lita1 = ft_found_pos_little_first_part500(data, chunk);
	lita2 = ft_found_pos_little_last_part500(data, chunk);
	if (lita1 <= lita2 && lita1 != -1)
		compare = 0;
	else
		compare = 1;
	//ft_printf("compare %d lita1 %d, lita2 %d, chunk %d\n", compare, lita1, lita2, chunk);
	if ((compare == 1 && lita2 >= 25) || (compare == 0 && lita1 >= 25))
		return (-1);
	if (lita1 == 1 && compare == 0)
		return (-1);
	else if (compare == 1)
		return (lita2);
	else
		return (lita1);
}

void	ft_trie_500_manager(t_struct *data, int chunk, int token)
{
	int			len;
	int			lbnum;
	int			lanum;
	t_list_b	*lb;

	lb = data->lb->next;
	lbnum = ft_found_best_place500(data, lb, data->la->next->num);
	lanum = ft_reduce_managera500(data, chunk);
	len = ft_len_listb(data);
	//ft_printf("TRIE MANAGER mon lbnum %d, mon lanum %d, len %d\n", lbnum, lanum, len);
	if (token == 1)
		ft_trie_lb_1500(lbnum, len, data, lanum);
	else
		ft_trie_la_1500(lanum, len, data, lbnum);
}

void	ft_trie_lb_1500(int i, int len, t_struct *data, int nb)
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
		ft_trie_lb_1helper500(i, len, data, nb);
}

void	ft_trie_lb_1helper500(int i, int len, t_struct *data, int nb)
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

void	ft_trie_la_1500(int i, int len, t_struct *data, int nb)
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
		ft_trie_la_1helper500(i, len, data, nb);
}

void	ft_trie_la_1helper500(int i, int len, t_struct *data, int nb)
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
