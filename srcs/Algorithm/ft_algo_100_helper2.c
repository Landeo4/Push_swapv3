/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_100_helper2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 22:17:25 by tpotilli          #+#    #+#             */
/*   Updated: 2023/06/17 18:55:01 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
int	ft_somme_algo_100(t_struct *data, int argc, int token)
{
	int			chiffre;
	int			len;
	t_list_a	*la;
	double		last;

	if (token == 0)
		last = 0.40;
	else if (token == 1)
		last = 0.82;
	else if (token == 2)
		last = 1.24;
	else if (token == 3)
		last = 1.66;
	else if (token == 4)
		last =  2.07;
		
	ft_printf("")
	return (chiffre);
}*/

int	ft_somme_algo_100(t_list_a *la, int argc, int token, int len)
{
	int			chiffre;
	double		last;

	if (token == 5)
	{
		chiffre = 2147483647;
		return (chiffre);
	}
	last = token * 0.2;
	printf("mon operation est donc token = %d * 0.20 donc mon last = %f\n la len est de %d", token, last, len);
	chiffre = 0;
	//chiffre = chiffre * token;
	chiffre = ft_somme_100helper(len, argc, la, token);
	printf("du coup chunk = chiffre %d et last %f, et mon argc est de %d\n", chiffre, last, argc);
	chiffre = chiffre * last;
	ft_printf("%d\n\n",chiffre);
	return (chiffre);
}

int		ft_somme_100helper(int len, int argc, t_list_a *la, int token)
{
	static int chiffre;

	if (token > 1)
	{
		return (chiffre);
	}
	chiffre = 0;
	while (len > 0 && la)
	{
		chiffre = chiffre + la->num;
		la = la->next;
		len--;
	}
	chiffre = chiffre / argc;
	chiffre = chiffre * 2;
	return (chiffre);
}

//gerer le probleme de argc et la chunk
/*
int	ft_somme_algo_100(t_struct *data, int argc, int token)
{
	int			chiffre;
	int			len;
	t_list_a	*la;
	double		last;

	if (token == 0)
		last = 0.40;
	else if (token == 1)
		last = 0.80;
	else if (token == 2)
		last = 1.22;
	else if (token == 3)
		last = 1.62;
	else if (token == 4)
	{
		chiffre = 2147483647;
		return (chiffre);
	}
	printf("mon token est de %d et mon last %lf \n", token, last);
	la = data->la->next;
	chiffre = 0;
	len = ft_len_lista(data);
	ft_printf("la len est de %d\n", len);
	while (len > 0)
	{
		chiffre = chiffre + la->num;
		la = la->next;
		len--;
	}
	chiffre = chiffre / argc - 1;
	chiffre = chiffre * last ;
	ft_printf("le chunk1 est de %d\n\n", chiffre);
	return (chiffre);
}
*/

void	ft_take_25_algo100(t_struct *data, int compare, int little)
{
	int		lit1;
	int		lit2;

	if (ft_len_lista(data) == 1)
		lit1 = 0;
	else if (compare == 1)
	{
		while (data->la->next->num != little)
			data->la = rra(data);
		ft_printf("ma liste ressemble a ca\n");
		ft_print_listb(data);
	}
	else if (compare == 0)
	{
		while (data->la->next->num != little)
			data->la = ra(data);
		ft_printf("ma liste ressemble a ca\n");
		ft_print_listb(data);
	}
	lit1 = ft_trie_100_b_little(data, little); // trouver s'il y a un chiffre inferieur
	lit2 = ft_trie_100_b_biggest(data, little);// trouver s'il y a un chiffre superieur
	ft_100_swap_manager(data, lit1, lit2);
}

bool	ft_compare_little(t_struct *data, int littlech1, int littlech2)
{
	(void)data;
	ft_printf("===============================\nen arrivant \nlittle1 = %d et little2 = %d\n", littlech1, littlech2);
	while (42)
	{
		if (littlech2 == 1)
		{
			littlech2++;
			return 1;
		}
		else if (littlech1 == 0)
			return (0);
		ft_printf("===============================\nlittle1 = %d et little2 = %d\n", littlech1, littlech2);
		littlech2--;
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


/*
void	ft_take_25_algo100(t_struct *data, int compare, int little)
{
	int		lit1;
	int		lit2;

	if (compare == 1)
	{
		while (data->la->next->num != little)
			data->la = rra(data);
		ft_print_listb(data);
	}
	else if (compare == 0)
	{
		while (data->la->next->num != little)
			data->la = ra(data);
		ft_print_listb(data);
	}
	lit1 = ft_trie_100_b_little(data, little);
	lit2 = ft_trie_100_b_biggest(data, little);
	ft_100_swap_manager(data, lit1, lit2);
}
*/

/*
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
*/

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
