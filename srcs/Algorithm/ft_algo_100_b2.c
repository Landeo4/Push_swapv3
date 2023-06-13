/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_100_b2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:45:19 by tpotilli          #+#    #+#             */
/*   Updated: 2023/06/13 10:47:09 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_100_swap_manager(t_struct *data, int lit1, int lit2)
{
	int			cpt;
	t_list_b	*lb;
	int			len;

	len = ft_len_listb(data);
	lb = data->lb->next;
	ft_print_listb(data);
	if (lit1 != -1 && lit2 != -1)
	{
		ft_printf("je passe le premier if de swap manager\n");
		cpt = ft_found_best_place100(data, lb);
		ft_printf("mon cpt est de %d \n", cpt);
		ft_take_best_place100(data, cpt);
		data->la = pb(data);
		if (data->lb->next->num < data->lb->next->next->num)
			data->lb = sb(data->lb, data);
		return ;
	}
	else if (lit2 == -1)
	{
		ft_printf("je passe par le lit2 == -1\n");
		cpt = ft_make_best_place_alg100(data, lb);
		data->la = pb(data);
		return ;
	}
	else if (lit1 == -1)
	{
		ft_printf("je passe par le lit1 == -1\n");
		cpt = ft_found_lower_b(data);
		ft_take_best_place102(data, cpt);
		data->la = pb(data);
	}
	ft_print_listb(data);
	lb = data->lb->next;
	if (len > 4)
	{
		if (data->lb->next->num < data->lb->next->next->num)
		{
			while (lb->next)
				lb = lb->next;
			ft_printf("lb->num =  %d\n", lb->num);
			if (lb->num > data->lb->next->num)
				data->lb = rrb(data);
			else
				data->lb = sb(data->lb, data);
			if (data->lb->next->num < data->lb->next->next->num 
				&& data->lb->next->next->num > data->lb->next->next->next->num)
				data->lb = sb(data->lb, data);
		}
	}
	else
		if (data->lb->next->num < data->lb->next->next->num)
			data->lb = sb(data->lb, data);
	ft_printf("ma liste ressemble maintenant a ca apres ma fonction manager\n");
}

/*
void	ft_100_swap_manager(t_struct *data, int lit1, int lit2)
{
	int			cpt;
	t_list_b	*lb;
	int			i;

	i = ft_found_pos_lb_big(data);
	lb = data->lb->next;
	ft_printf("salut je passe par le swap manager et mes lit1 et lit2 sont lit1 %d, lit2 %d\n", lit1, lit2);
	ft_printf("avant mon make list right\n");
	ft_print_listb(data);
	ft_make_list_right(data, i);
	ft_print_listb(data);
	if (lit1 != -1 && lit2 != -1)
	{
		ft_printf("je passe le premier if de swap manager\n");
		cpt = ft_found_best_place100(data, lb);
		ft_printf("mon cpt est de %d \n", cpt);
		ft_take_best_place100(data, cpt);
		data->la = pb(data);
	}
	else if (lit2 == -1) // s'il y aucune occurence inferieur
	{
		data->la = pb(data);
		ft_printf("je passe par le lit2 == -1\n");
	}
	else if (lit1 == -1) // s'il y aucune occurence superieur
	{
		data->la = pb(data);
		data->lb = rb(data);
		ft_printf("je passe par le lit1 == -1\n");
	}
	else
	{
		lit2 = lit1;
		while (lit1 != ft_len_listb(data))
		{
			lit1++;
			data->lb = rrb(data);
		}
		data->la = pb(data);
	}
	if (data->lb->next->num < data->lb->next->next->num)
		data->lb = sb(data->lb, data);
	ft_printf("ma liste ressemble maintenant a ca apres ma fonction manager\n");
	ft_print_listb(data);
}
*/
// je suis en train d'essayer de regler le probleme de rb
/*
void	ft_make_list_right(t_struct *data, int i)
{
	t_list_b	*lb;
	int			nb;
	int			j;
	(void)j;

	ft_printf("le i dans make list right est de %d\n", i);
	j = 0;
	lb = data->lb->next;
	nb = lb->num;
	while (lb && lb->next)
	{
		if (nb < lb->num)
			nb = lb->num;
		lb = lb->next;
		i++;
	}
	lb = data->lb->next;
	//ft_helper_100(data, nb, j);
}

void	ft_helper_100(t_struct *data, int nb, int i)
{
	int		len;

	len = ft_len_listb(data);
	len = len / 2;
	if (i > len)
	{
		len = ft_len_listb(data);
		while (i < len && nb != data->lb->next->num)
		{
			data->lb = rrb(data);
			i++;
		}
	}
	else if (i < len)
	{
		while (i < len && nb != data->lb->next->num)
		{
			data->lb = rb(data);
			i++;
		}
	}
}
*/

int		ft_make_best_place_alg100(t_struct *data, t_list_b *lb)
{
	int			nb;
	int			len;

	len = ft_len_listb(data);
	nb = data->lb->next->num;
	while (lb)
	{
		if (nb < lb->num)
			nb = lb->num;
		lb = lb->next;
	}
	ft_printf("mon nb vaut %d\n", nb);
	while (len > 0)
	{
		if (data->lb->next->num == nb)
			return (0);
		data->lb = rb(data);
		len--;
	}
	return (-1);
}

int			ft_found_lower_b(t_struct *data)
{
	t_list_b	*lb;
	int			nb;

	lb = data->lb->next;
	nb = data->lb->next->num;
	while (lb && lb->next)
	{
		if (nb > lb->num)
			nb = lb->num;
		lb = lb->next;
	}
	ft_printf("mon nb dans le lit1 -1 est de %d\n", nb);
	return (nb);
}

void	ft_make_list_right(t_struct *data, int i)
{
	int		len;

	ft_printf("le i dans make list right est de %d\n", i);
	len = ft_len_listb(data);
	len = len / 2;
	if (ft_verif_lb(data) == -1)
		return ;
	if (i > len)
	{
		len = ft_len_listb(data);
		while (i > len)
		{
			data->lb = rb(data);
			i++;
		}
		return ;
	}
	else if (i < len)
	{
		while (i < len)
		{
			data->lb = rrb(data);
			i++;
		}
		return ;
	}
}

int		ft_verif_lb(t_struct *data)
{
	t_list_b	*lb;
	int			nb;

	lb = data->lb;
	if (data->lb->next->num < data->lb->next->next->num)
	{
		lb = sb(lb, data);
	}
	nb = data->lb->next->num;
	lb = data->lb->next;
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
	lb = data->lb->next;
	while (lb)
	{
		if (nb == nb2)
			return (i);
		nb = lb->num;
		lb = lb->next;
		i++;
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