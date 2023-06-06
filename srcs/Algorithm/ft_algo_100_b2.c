/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_100_b2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:45:19 by tpotilli          #+#    #+#             */
/*   Updated: 2023/06/06 17:03:18 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// mon probleme viens de mon if (lit1 == -1 && lit2 == -1)
void	ft_100_swap_manager(t_struct *data, int lit1, int lit2)
{
	int			cpt;
	t_list_b	*lb;
	int			i;

	i = ft_found_pos_lb_big(data);
	lb = data->lb->next;
	ft_printf("salut je passe par le swap manager et mes lit1 et lit2 sont lit1 %d, lit2 %d\n", lit1, lit2);
	ft_make_list_right(data, i);
	ft_print_listb(data);
	if (lit1 != -1 && lit2 != -1)
	{
		cpt = ft_found_best_place100(data, lb);
		ft_printf("mon cpt est de %d \n", cpt);
		ft_take_best_place100(data, cpt);
		data->la = pb(data);
	}
	else if (lit2 == -1) // s'il y aucune occurence inferieur
		data->la = pb(data);
	else if (lit1 == -1) // s'il y aucune occurence superieur
	{
		data->la = pb(data);
		data->lb = rb(data);
	}
	else
	{
		lit2 = lit1;
		while (lit1 != ft_len_listb(data))
		{
			lit1++;
			rrb(data);
		}
		pb(data);
	}
	if (data->lb->next->num < data->lb->next->next->num)
		data->lb = sb(lb, data);
	ft_printf("ma liste ressemble maintenant a ca\n");
	ft_print_listb(data);
}
// je suis en train d'essayer de regler le probleme de rb
void	ft_make_list_right(t_struct *data, int i)
{
	int		len;

	len = ft_len_listb(data);
	len = len / 2;
	if (ft_verif_lb(data) == -1)
		return ;
	if (i > len)
	{
		len = ft_len_listb(data);
		while (i > len)
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
// peut etre que plus tard cette fonction fera bug mon programme car ca echangera des nb qui viennent d'etre push dans b
int		ft_verif_lb(t_struct *data)
{
	t_list_b	*lb;
	int			nb;

	lb = data->lb->next;
	if (data->lb->next->num < data->lb->next->next->num)
	{
		lb = sb(lb, data);
	}
	nb = data->lb->next->num;
	while (lb)
	{
		if (nb < lb->num)
			return (0);
		lb = lb->next;
	}
	return (-1);
}

int		ft_found_pos_lb_big(t_struct *data)
{
	int			nb;
	int			nb2;
	t_list_b	*lb;
	int			i;

	lb = data->lb->next->next;
	nb = data->lb->next->num;
	nb2 = data->lb->next->num;
	i = 0;
	while (lb)
	{
		if (nb < lb->num)
			nb = lb->num;
		lb = lb->next;
	}
	while (lb)
	{
		if (nb == nb2)
			return (i);
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