/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_100_helper2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 22:17:25 by tpotilli          #+#    #+#             */
/*   Updated: 2023/05/10 19:56:49 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_take_25_algo100(t_struct *data, int compare, int little)
{
	if (compare == 1)
	{
		while (data->la->next->num != little)
			rra(data);
		pb(data);
	}
	else if (compare == 0)
	{
		while (data->la->next->num != little)
			ra(data);
		pb(data);
	}
}

bool	ft_compare_little(t_struct *data, int littlech1, int littlech2)
{
	int		len;

	len = ft_len_lista(data);
	while (42)
	{
		if (littlech2 == len)
		{
			littlech2++;
			return 1;
		}
		else if (littlech1 == 0)
			return (0);
		littlech2++;
		littlech1--;
	}
	return (0);
}

//found the little number in chunk1
int	ft_found_little_chunk1_100(t_struct *data)
{
	int			i;
	int			nb;
	t_list_a	*tab;
	int			len;

	len = ft_len_lista(data);
	len = len / 5;
	i = 1;
	tab = data->la->next;
	nb = data->la->next->num;
	while (tab)
	{
		if (nb > tab->num)
			nb = tab->num;
		tab = tab->next;
		i++;
		if (len < 0)
			break ;
		len--;
	}
	return (nb);
}

//found the little number in chunk5
int	ft_found_little_chunk5_100(t_struct *data)
{
	int			i;
	int			nb;
	t_list_a	*tab;
	int			len;

	len = ft_len_lista(data);
	len = len * 0.75;
	i = 1;
	tab = data->la->next;
	nb = data->la->next->num;
	while (i != len)
		i++;
	while (tab)
	{
		if (nb > tab->num)
			nb = tab->num;
		tab = tab->next;
		i++;
	}
	return (i);
}

int	ft_found_little_100(t_struct *data)
{
	int			i;
	int			nb;
	t_list_a	*tab;

	i = 1;
	tab = data->la->next;
	nb = data->la->next->num;
	while (tab)
	{
		if (nb > tab->num)
			nb = tab->num;
		tab = tab->next;
		i++;
	}
	return (nb);
}

/*
void		ft_take_75_algo100(t_struct *data, int little)
{
	int			len;
	t_list_a	*tmp;

	tmp = data->la->next;
	len = ft_len_lista(data);
	if (tmp->num < moyenne)
		tmp = pb(data);
	while (len > 0)
	{
		tmp = ra(data);
		tmp = data->la->next;
		while (tmp->num < moyenne)
		{
			len--;
			tmp = pb(data);
			tmp = data->la->next;
		}
		len--;
	}
}
*/
/*
void	ft_algo_100_helper(t_struct *data)
{
	t_list_b	*lb;
	int			num;
	int			i;
	int			pos;

	i = 0;
	pos = ft_found_pos_little(data);
	num = ft_found_little(data);
	lb = data->lb->next;
	while (i < pos)
	{
		i++;
		if (lb->num == num)
			break ;
		lb = lb->next;
	}
	lb = data->lb->next;
	ft_tri_100(lb, data);
}

void	ft_tri_100(t_list_b *lb, t_struct *data)
{
	while (lb)
	{
		if (ft_tri_100_done(data) == 1)
			return ;
		ft_100_action(lb, data);
		lb = data->lb->next;
	}
}

void	ft_100_action(t_list_b *tmp, t_struct *data)
{
	int	len;

	len = ft_len_listb(data);
	len = len / 2;
	if (tmp->next)
	{
		if (tmp->num > tmp->next->num)
			data->lb = sb(data->lb);
		data->lb = rb(data);
	}
}

int	ft_found_pos_little_100(t_struct *data)
{
	int			i;
	t_list_b	*tab;
	int			nb;

	i = 1;
	tab = data->lb->next;
	nb = ft_found_little(data);
	while (tab)
	{
		if (nb != tab->num)
			tab = tab->next;
		else
			break ;
		i++;
	}
	return (i);
}

int	ft_found_little_100(t_struct *data)
{
	int			i;
	int			nb;
	t_list_b	*tab;

	i = 1;
	tab = data->lb->next;
	nb = data->lb->next->num;
	while (tab)
	{
		if (nb > tab->num)
			nb = tab->num;
		tab = tab->next;
		i++;
		if (i > 25)
			break ;
	}
	return (nb);
}
*/
