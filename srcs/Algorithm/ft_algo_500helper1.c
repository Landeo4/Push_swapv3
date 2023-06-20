/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_500helper1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 13:27:48 by tpotilli          #+#    #+#             */
/*   Updated: 2023/06/18 17:49:01 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_found_pos_little_first_part500(t_struct *data, int chunk, t_list_a *la)
{
	int			i;
	t_list_a	*tab;
	int			nb;
	int			len;

	len = ft_len_lista(data);
	len = len / 2;
	i = 1;
	tab = la;
	nb = la->num;
	while (tab && len > 0)
	{
		if (nb <= chunk)
		{
			return (i);
		}
		i++;
		len--;
		tab = tab->next;
		nb = tab->num;
	}
	return (0);
}

int	ft_found_pos_little_last_part500(t_struct *data, int chunk, t_list_a *la)
{
	int			i;
	t_list_a	*tab;
	int			len;
	int			len2;

	len2 = 1;
	len = ft_len_lista(data);
	len = len * 0.5;
	i = len / 5;
	tab = la->next;
	while (len2 < len)
	{
		tab = tab->next;
		len2++;
	}
	while (len2 < ft_len_lista(data))
	{
		if (tab->num < chunk)
			i = 0;
		tab = tab->next;
		len2++;
		i++;
	}
	return (i);
}

int	ft_found_little_500_25(t_struct *data, int pos, int chunk)
{
	t_list_a	*tab;
	int			nb;
	int			len;
	int			nb2;

	len = ft_len_lista(data);
	tab = data->la->next;
	nb = ft_found_little(data);
	if (nb > chunk)
	{
		nb2 = ft_found_little(data);
		while (len > 0)
		{
			if (data->la->next->num == nb2)
				return (nb2);
			data->la = ra(data);
			len--;
		}
	}
	else
		nb = ft_500else(pos, nb, tab);
	return (nb);
}

int	ft_500else(int pos, int nb, t_list_a *tab)
{
	while (pos != 0)
	{
		nb = tab->num;
		tab = tab->next;
		pos--;
	}
	return (nb);
}

int	ft_found_little_500_75(t_struct *data, int pos, t_list_a *la)
{
	t_list_a	*tab;
	int			nb;
	int			ch;
	int			len;

	ch = ft_len_lista(data);
	ch = ch - pos;
	len = 0;
	tab = la;
	while (len != ch && tab->next)
	{
		tab = tab->next;
		nb = tab->num;
		len++;
	}
	return (nb);
}
