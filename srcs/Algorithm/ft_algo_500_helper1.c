/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_500_helper1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceatgie <ceatgie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:59:10 by tpotilli          #+#    #+#             */
/*   Updated: 2023/09/03 11:15:28 by ceatgie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_found_pos_little_first_part500(t_struct *data, int chunk)
{
	int			i;
	t_list_a	*tab;
	int			nb;
	int			len;

	len = ft_len_lista(data);
	len = len / 2;
	i = 1;
	tab = data->la->next;
	nb = tab->num;
	while (tab && len > 0)
	{
		if (nb <= chunk)
		{
			ft_printf("nb lit1 = %d\n", nb);
			return (i);
		}
		i++;
		len--;
		tab = tab->next;
		nb = tab->num;
	}
	return (-1);
}

int	ft_found_pos_little_last_part500(t_struct *data, int chunk)
{
	int			i;
	t_list_a	*tab;
	int			len;
	int			len2;

	len2 = 0;
	len = ft_len_lista(data);
	len = len * 0.5;
	i = len / 5;
	tab = data->la->next;
	while (len2++ < len)
		tab = tab->next;
	while (len2 < (len * 2))
	{
		if (tab->num < chunk)
			i = 1;
		tab = tab->next;
		len2++;
		i++;
	}
	ft_printf("nb lit2 = %d\n", tab->num);
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

int	ft_found_little_500_75(t_struct *data, int pos)
{
	t_list_a	*tab;
	int			nb;
	int			ch;
	int			len;
	t_list_a	*la;

	la = data->la->next;
	ch = ft_len_lista(data);
	ch = ch - pos;
	len = 0;
	tab = la;
	while (len != ch && tab->next)
	{
		tab = tab->next;
		len++;
	}
	nb = tab->num;
	ft_printf("tab->num %d\n", tab->num);
	return (nb);
}

//ici probleme de moyenne et nombre recup
//voir a la ligne 2285 environ