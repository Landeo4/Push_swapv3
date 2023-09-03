/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_100reduce.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceatgie <ceatgie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:25:08 by tpotilli          #+#    #+#             */
/*   Updated: 2023/09/03 11:07:30 by ceatgie          ###   ########.fr       */
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

int	ft_reduce_managera(t_struct *data, int chunk)
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
	//ft_printf("TRIE MANAGER mon lbnum %d, mon lanum %d, len %d\n", lbnum, lanum, len);
	if (token == 1)
		ft_trie_lb_1(lbnum, len, data, lanum);
	else
		ft_trie_la_1(lanum, len, data, lbnum);
}
