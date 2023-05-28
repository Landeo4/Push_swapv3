/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_100_b2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:45:19 by tpotilli          #+#    #+#             */
/*   Updated: 2023/05/28 17:53:43 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_100_swap_manager(t_struct *data, int lit1, int lit2)
{
	int			i;
	t_list_b	*lb;

	i = ft_found_pos_lb_big(data);
	lb = data->lb->next;
	ft_printf("salut je passe par le swap manager et mes lit sont lit1 %d, lit2 %d\n", lit1, lit2);
	ft_make_list_right(data, i);
	ft_print_listb(data);
	if (lit1 == -1 && lit2 == -1)
	{
		i = ft_found_best_place100(data, lb);
		ft_take_best_place100(data, i);
		data->la = pb(data);
	}
	if (lit1 == -1) // s'il y aucune occurence inferieur
		data->la = pb(data);
	else if (lit2 == -1) // s'il y aucune occurence superieur
	{
		data->lb = rrb(data);
		data->la = pb(data);
	}
}
// je suis en train d'essayer de regler le probleme de rb
void	ft_make_list_right(t_struct *data, int i)
{
	int		len;

	len = ft_len_listb(data);
	len = len / 2;
	if (ft_verif_lb = -1)
		return ;
	if (i > len)
	{
		len = ft_len_listb(data);
		while (i < len)
		{
			data->lb = rrb(data);
			i++;
		}
		return ;
	}
	else if (i < len)
	{
		while (i < len)
		{
			data->lb = rb(data);
			i++;
		}
		return ;
	}
}

int		ft_found_pos_lb_big(t_struct *data)
{
	int			nb;
	t_list_b	*lb;
	int			i;

	lb = data->lb->next->next;
	nb = data->lb->next->num;
	i = 0;
	while (lb)
	{
		if (nb > lb->num)
		{
			nb = lb->num;
			i = 0;
		}
		lb = lb->next;
	}
	ft_printf("MON i EST %d \n", i);
	return (i);
}

int		ft_found_big_lb_100(t_struct *data)
{
	int			nb;
	t_list_b	*lb;

	lb = data->lb->next->next;
	nb = data->lb->next->num;
	while (lb)
	{
		if (nb < lb->num)
			nb = lb->num;
		lb = lb->next;
	}
	ft_printf("MON PLUS GROS CHIFFRE EST %d \n", nb);
	return (nb);
}

//void	ft_take100(t_struct *data, int token)