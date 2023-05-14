/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_100_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:29:41 by tpotilli          #+#    #+#             */
/*   Updated: 2023/05/14 23:19:11 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//This fonction will test where the num of A would be place
void	ft_trie_100(t_struct *data, int little)
{
	t_list_b	*lb;
	int			i;
	int			lit1;
	int			lit2;

	lb = data->lb->next;
	ft_printf("================on passe a l'algo dans B================\ndata->lb->next = %d et mon little est de -> %d\n", lb->num, little);
	lit1 = ft_trie_100_b_little(data, little);
	lit2 = ft_trie_100_b_biggest(data, little);
	ft_printf("================les deux tries donne================\nlittle =  %d et mon little little2 = %d\n", lit1, lit2);
	if (lit1 > 0 && lit2 > 0)
	{
		ft_printf("SALUT LES AMIS JE PASSE PAR LA\n");
		i = ft_found_best_place100(data, little);
		ft_sort_b100(data, i);
	}
	if (lit1 == -1)
		ft_take_b_100(data, lit2, 1);
	else if (lit2 == -1)
		ft_take_b_100(data, lit1, 0);
}

int		ft_found_best_place100(t_struct *data, int little)
{
	t_list_b	*lb;
	int			big;
	int			lit;
	int			i;
	(void)little;

	lb = data->lb->next;
	big = lb->num;
	lit = lb->num;
	while (lb)
	{
		if (lb->num < lb->next->num)
			big = lb->next->num;
		else if (lb->num > lb->next->num)
			lit = lb->next->num;
		lb = lb->next;
		i++;
	}
	i = ft_take_best_place100(data, i, big, lit);
	return (i);
}

void	ft_sort_b100(t_struct *data, int i)
{
	int		len;

	len = ft_len_listb(data);
	len = len / 2;
	ft_printf("SALUT LES AMIS JE PASSE PAR LA\n");
	if (i > len)
	{
		while (i > len)
		{
			rrb(data);
			i++;
		}
	}
	else if (i < len)
	{
		while (i < len)
		{
			rb(data);
			i++;
		}
	}
}

// trouve l'endroit ou mettre le nb s'il est ni trop grand ni trop grand
int		ft_take_best_place100(t_struct *data, int i, int big, int little)
{
	t_list_b	*lb;

	lb = data->lb->next;
	while (lb)
	{
		if (data->la->next->num > little && data->la->next->num < big)
			break ;
		i++;
		lb = lb->next;
	}
	return (i);
}

//trouver si il y a des chiffres superieur
int		ft_trie_100_b_little(t_struct *data, int little)
{
	t_list_b	*lb;
	int			i;
	int			nb;

	i = 1;
	lb = data->lb->next;
	nb = data->la->next->num;
	ft_printf("================on passe a la partie des chiffre inferieur================\ndata->lb->next = %d et mon little est de -> %d\n", lb->num, little);
	while (lb)
	{
		if (nb < lb->num)
			return (i);
		i++;
		lb = lb->next;
	}
	return (-1);
}

//trouver si il y a des chiffres superieur
int		ft_trie_100_b_biggest(t_struct *data, int little)
{
	t_list_b	*lb;
	int			i;
	int			nb;

	i = 1;
	lb = data->lb->next;
	nb = data->la->next->num;
	ft_printf("================on passe a la partie des chiffre superieur================\ndata->lb->next = %d et mon little est de superieur-> %d\n", lb->num, little);
	while (lb)
	{
		if (nb > lb->num)
			return (i);
		i++;
		lb = lb->next;
	}
	return (-1);
}

//mettre a la bonne place le lit dans lb
int		ft_take_b_100(t_struct *data, int lit, int token)
{
	t_list_b	*lb;
	(void)lb;

	lb = data->lb->next;
	if (token == 1)
	{
		while (lit > 0)
		{
			data->lb = rrb(data);
			lit--;
		}
	}
	else if (token == 0)
	{
		while (lit > 0)
		{
			data->lb = rb(data);
			lit--;
		}
	}
	return (0);
}










/*
void	ft_trie_100(t_struct *data, int little)
{
	t_list_b	*lb;
	int			i;
	int			lit1;
	int			lit2;

	lb = data->lb->next;
	ft_printf("================on passe a l'algo dans B================\ndata->lb->next = %d et mon little est de -> %d\n", lb->num, little);
	lit1 = ft_trie_100_b_little(data, little);
	lit2 = ft_trie_100_b_biggest(data, little);
	ft_printf("================les deux tries donne================\nlittle =  %d et mon little little2 = %d\n", lit1, lit2);
	if (lit1 == -1 && lit2 == -1)
	{
		i = ft_found_best_place100(data, little);
		ft_sort_b100(data, i);
	}
	if (lit1 == -1)
		ft_take_b_100(data, lit2, 1);
	else if (lit2 == -1)
		ft_take_b_100(data, lit1, 0);
}

int		ft_found_best_place100(t_struct *data, int little)
{
	t_list_b	*lb;
	int			big;
	int			lit;
	int			i;
	(void)little;

	lb = data->lb->next;
	big = lb->num;
	lit = lb->num;
	while (lb)
	{
		if (lb->num < lb->next->num)
			big = lb->next->num;
		else if (lb->num > lb->next->num)
			lit = lb->next->num;
		lb = lb->next;
		i++;
	}
	lb = data->lb->next;
	i = ft_take_best_place100(data, i, big, lit);
	return (i);
}

void	ft_sort_b100(t_struct *data, int i)
{
	int		len;

	len = ft_len_listb(data);
	len = len / 2;
	ft_printf("SALUT LES AMIS JE PASSE PAR LA\n");
	if (i > len)
	{
		while (i > len)
		{
			rrb(data);
			i++;
		}
	}
	else if (i < len)
	{
		while (i < len)
		{
			rb(data);
			i++;
		}
	}
}

// trouve l'endroit ou mettre le nb s'il est ni trop grand ni trop grand
int		ft_take_best_place100(t_struct *data, int i, int big, int little)
{
	t_list_b	*lb;

	lb = data->lb->next;
	while (lb)
	{
		if (data->la->next->num > little && data->la->next->num < big)
			break ;
		i++;
		lb = lb->next;
	}
	return (i);
}

//trouver si il y a des chiffres superieur
int		ft_trie_100_b_little(t_struct *data, int little)
{
	t_list_b	*lb;
	int			i;
	int			nb;

	i = 1;
	lb = data->lb->next;
	nb = data->la->next->num;
	ft_printf("================on passe a la partie des chiffre inferieur================\ndata->lb->next = %d et mon little est de -> %d\n", lb->num, little);
	while (lb)
	{
		if (nb < lb->num)
			return (i);
		i++;
		lb = lb->next;
	}
	return (-1);
}

//trouver si il y a des chiffres superieur
int		ft_trie_100_b_biggest(t_struct *data, int little)
{
	t_list_b	*lb;
	int			i;
	int			nb;

	i = 1;
	lb = data->lb->next;
	nb = data->la->next->num;
	ft_printf("================on passe a la partie des chiffre superieur================\ndata->lb->next = %d et mon little est de superieur-> %d\n", lb->num, little);
	while (lb)
	{
		if (nb > lb->num)
			return (i);
		i++;
		lb = lb->next;
	}
	return (-1);
}

//mettre a la bonne place le lit dans lb
int		ft_take_b_100(t_struct *data, int lit, int token)
{
	t_list_b	*lb;
	(void)lb;

	lb = data->lb->next;
	if (token == 1)
	{
		while (lit > 0)
		{
			data->lb = rrb(data);
			lit--;
		}
	}
	else if (token == 0)
	{
		while (lit > 0)
		{
			data->lb = rb(data);
			lit--;
		}
	}
	return (0);
}
*/

/*
void	ft_trie_100(t_struct *data, int little)
{
	t_list_b	*lb;
	int			i;
	int			lit1;
	int			lit2;

	lb = data->lb->next;
	ft_printf("================on passe a l'algo dans B================\ndata->lb->next = %d et mon little est de -> %d\n", lb->num, little);
	lit1 = ft_trie_100_b_little(data, little);
	lit2 = ft_trie_100_b_biggest(data, little);
	if (lit1 == -1 && lit2 == -1)
	{
		i = ft_found_best_place100(data, little);
		ft_sort_b100(data, i);
	}
	if (lit1 == -1)
		ft_take_b_100(data, lit2, 1);
	else if (lit2 == -1)
		ft_take_b_100(data, lit1, 0);
}

int		ft_found_best_place100(t_struct *data, int little)
{
	t_list_b	*lb;
	int			big;
	int			lit;
	int			i;
	(void)little;

	lb = data->lb->next;
	big = lb->num;
	lit = lb->num;
	while (lb)
	{
		if (lb->num < lb->next->num)
			big = lb->next->num;
		else if (lb->num > lb->next->num)
			lit = lb->next->num;
		lb = lb->next;
		i++;
	}
	lb = data->lb->next;
	i = ft_take_best_place100(data, i, big, lit);
	return (i);
}

void	ft_sort_b100(t_struct *data, int i)
{
	int		len;

	len = ft_len_listb(data);
	len = len / 2;
	ft_printf("SALUT LES AMIS JE PASSE PAR LA\n");
	if (i > len)
	{
		while (i > len)
		{
			rrb(data);
			i++;
		}
	}
	else if (i < len)
	{
		while (i < len)
		{
			rb(data);
			i++;
		}
	}
}

// trouve l'endroit ou mettre le nb s'il est ni trop grand ni trop grand
int		ft_take_best_place100(t_struct *data, int i, int big, int little)
{
	t_list_b	*lb;

	lb = data->lb->next;
	while (lb)
	{
		if (data->la->next->num > little && data->la->next->num < big)
			break ;
		i++;
		lb = lb->next;
	}
	return (i);
}

//trouver si il y a des chiffres superieur
int		ft_trie_100_b_little(t_struct *data, int little)
{
	t_list_b	*lb;
	int			i;
	int			nb;

	i = 1;
	lb = data->lb->next;
	nb = data->la->next->num;
	ft_printf("================on passe a la partie des chiffre inferieur================\ndata->lb->next = %d et mon little est de -> %d\n", lb->num, little);
	while (lb)
	{
		if (nb > lb->num)
			return (1);
		i++;
		lb = lb->next;
	}
	return (i);
}

//trouver si il y a des chiffres superieur
int		ft_trie_100_b_biggest(t_struct *data, int little)
{
	t_list_b	*lb;
	int			i;
	int			nb;

	i = 1;
	lb = data->lb->next;
	nb = data->la->next->num;
	ft_printf("================on passe a la partie des chiffre superieur================\ndata->lb->next = %d et mon little est de superieur-> %d\n", lb->num, little);
	while (lb)
	{
		if (nb > lb->num)
			return (i);
		i++;
		lb = lb->next;
	}
	return (-1);
}

//mettre a la bonne place le lit dans lb
int		ft_take_b_100(t_struct *data, int lit, int token)
{
	t_list_b	*lb;
	(void)lb;

	lb = data->lb->next;
	if (token == 1)
	{
		while (lit > 0)
		{
			data->lb = rrb(data);
			lit--;
		}
	}
	else if (token == 0)
	{
		while (lit > 0)
		{
			data->lb = rb(data);
			lit--;
		}
	}
	return (0);
}
*/
