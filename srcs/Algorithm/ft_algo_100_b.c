/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_100_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:29:41 by tpotilli          #+#    #+#             */
/*   Updated: 2023/06/13 10:49:40 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_trie_100(t_struct *data, int little)
{
	t_list_b	*lb;
	int			lit1;
	int			lit2;

	lb = data->lb->next;
	ft_printf("================on passe a l'algo dans B================\ndata->lb->next = %d et mon little est de -> %d\n", lb->num, little);
	lit1 = ft_trie_100_b_little(data, little);
	lit2 = ft_trie_100_b_biggest(data, little);
	ft_printf("================les deux tries donne================\nlittle =  %d et mon little little2 = %d\n", lit1, lit2);
	return (0);
}

int		ft_found_best_place100(t_struct *data, t_list_b *lb)
{
	int			nb;
	int			cpt;

	nb = data->la->next->num;
	cpt = 0;
	lb = data->lb->next;
	ft_printf("mon nb est de %d dans le found best place\n", nb);
	while (lb && lb->next)
	{
		if (lb->num > nb && nb > lb->next->num)
			return (cpt);
		cpt++;
		lb = lb->next;
	}
	ft_printf("mon cpt dans best place est de %d \n", cpt);
	return (-1);
}

void	ft_sort_b100(t_struct *data, int i)
{
	int		len;

	len = ft_len_listb(data);
	len = len / 2;
	if (i > len)
	{
		while (i >= len)
		{
			rrb(data);
			i--;
		}
	}
	else if (i < len)
	{
		while (i <= len)
		{
			rb(data);
			i++;
		}
	}
}

/*
int		ft_take_best_place100(t_struct *data, int cpt)
{
	int			nb;
	int			len;

	nb = data->la->next->num;
	len = ft_len_listb(data);
	len = len / 2;
	ft_printf("dans ma fonction take best place mon cpt est de %d et mon nb est de %d\n", cpt, nb);
	ft_printf("et ma len est de %d\n", len);
	if (cpt > len)
	{
		len = ft_len_listb(data);
		while (len > cpt)
		{
			data->lb = rrb(data);
			cpt++;
		}
	}
	else if (cpt < len)
	{
		if (cpt == 0)
		{
			data->lb = rb(data);
			return (0);
		}
		while (cpt > len)
		{
			data->lb = rb(data);
			len++;
		}
	}
	return (0);
}
*/

int	ft_take_best_place100(t_struct *data, int cpt)
{
	int			nb;
	int			len;

	nb = data->la->next->num;
	len = ft_len_listb(data);
	len = len / 2;
	ft_printf("dans ma fonction take best place mon cpt est de %d et mon nb est de %d\n", cpt, nb);
	ft_printf("et ma len est de %d\n", len);
	if (cpt > len)
	{
		len = ft_len_listb(data);
		while (len > cpt)
		{
			data->lb = rrb(data);
			cpt++;
		}
	}
	else if (cpt < len)
	{
		if (cpt == 0)
		{
			data->lb = rb(data);
			return (0);
		}
		cpt++;
		while (cpt > 0)
		{
			data->lb = rb(data);
			cpt--;
		}
	}
	return (0);
}

int	ft_take_best_place102(t_struct *data, int nb)
{
	int			len;
	t_list_b	*lb;
	int			i;

	i = 0;
	lb = data->lb->next;
	len = ft_len_listb(data);
	len = len / 2;
	while (lb->num != nb)
	{
		i++;
		lb = lb->next;
		ft_printf("mon i est de %d et mon lb est de %d\n", i, lb->num);
	}
	lb = data->lb->next;
	ft_printf("mon i dans take best place est de %i et ma len de %d\n", i, len);
	if (i == 0)
		data->lb = rb(data);
	else if (i == len)
	{
		len = ft_len_listb(data);
		while (i < len)
		{
			data->lb = rb(data);
			i++;
		}
	}
	else if (i > len)
	{
		ft_printf("salut je suis dans la boucle des rrb\n", i);
		len = ft_len_listb(data);
		while (i < len)
		{
			data->lb = rrb(data);
			i++;
		}
	}
	else if (i < len)
	{
		ft_printf("salut je suis dans la boucle des rb ^^\n", i);
		while (i < len)
		{
			data->lb = rb(data);
			i++;
		}
	}
	return (0);
}

//trouver s'il y a des chiffres superieur
int	ft_trie_100_b_biggest(t_struct *data, int little)
{
	t_list_b	*lb;
	int			i;

	i = 0;
	lb = data->lb->next;
	while (lb)
	{
		if (little <= lb->num)
			return (i);
		lb = lb->next;
		i++;
	}
	return (-1);
}

//trouver si il y a des chiffres inferieur
int		ft_trie_100_b_little(t_struct *data, int little)
{
	t_list_b	*lb;
	int			i;

	i = 0;
	lb = data->lb->next;
	while (lb)
	{
		if (little >= lb->num) //mon lit est supeiruer a une position
			return (i);
		lb = lb->next;
		i++;
	}
	return (-1);
}


//mettre a la bonne place le lit dans lb
int		ft_take_b_100(t_struct *data, int lit, int token)
{
	ft_printf("VOICI LA LISTE AVANT L'AJOUT\n");
	ft_printf("HAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n");
	ft_print_listb(data);
	ft_printf("il faut donc faire %d d'action dans b\n", lit);
	if (token == 1)
	{
		while (lit > 0)
		{
			data->lb = rb(data);
			lit--;
		}
	}
	else if (token == 0)
	{
		while (lit > 0)
		{
			data->lb = rrb(data);
			lit--;
		}
	}
	return (0);
}

/*void	ft_trie_100(t_struct *data, int little)
{
	t_list_b	*lb;
	int			lit1;
	int			lit2;
	int			i;

	lb = data->lb->next;
	ft_printf("================on passe a l'algo dans B================\ndata->lb->next = %d et mon little est de -> %d\n", lb->num, little);
	lit1 = ft_trie_100_b_little(data, little); // trouver s'il y a un chiffre sup
	lit2 = ft_trie_100_b_biggest(data, little);// trouver s'il y a un chiffre inf
	ft_printf("================les deux tries donne================\nlittle =  %d et mon little little2 = %d\n", lit1, lit2);
	if (lit1 != -1 && lit2 != -1)
	{
		i = ft_found_best_place100(data, lb);
		ft_printf("le i de ma pos est %d\n", i);
		ft_sort_b100(data, i);
	}
	else if (lit1 == -1) //donc s'il n'y a aucun nombre superieur a mon nb
		return ;
	else if (lit2 == -1) //donc s'il n'y a aucun nombre inferieur a mon nb
		rrb(data);
}

int		ft_found_best_place100(t_struct *data, t_list_b *lb)
{
	int			i;
	int			nb;

	nb = data->la->next->num;
	while (lb && lb->next)
	{
		if (lb->num > nb && nb > lb->next->num)
			return (i);
		i++;
		lb = lb->next;
	}
	return (-1);
}

void	ft_sort_b100(t_struct *data, int i)
{
	int		len;

	len = ft_len_listb(data);
	len = len / 2;
	if (i > len)
	{
		while (i >= len)
		{
			rrb(data);
			i--;
		}
	}
	else if (i < len)
	{
		while (i <= len)
		{
			rb(data);
			i++;
		}
	}
}

int		ft_take_best_place100(t_struct *data, int i)
{
	t_list_b	*lb;

	lb = data->lb->next;
	while (lb && lb->next)
	{
		if (data->la->next->num > lb->num && data->la->next->num < lb->next->num)
			break ;
		i++;
		lb = lb->next;
	}
	return (0);
}

//trouver s'il y a des chiffres inferieur
int		ft_trie_100_b_little(t_struct *data, int little)
{
	t_list_b	*lb;
	int			nb;
	(void)little;

	lb = data->lb->next;
	nb = data->la->next->num;
	while (lb)
	{
		if (lb->num < nb)
			return (-1);
		lb = lb->next;
	}
	return (-1);
}

//trouver si il y a des chiffres superieur
int		ft_trie_100_b_biggest(t_struct *data, int little)
{
	t_list_b	*lb;
	int			nb;
	(void)little;

	lb = data->lb->next;
	nb = data->la->next->num;
	while (lb)
	{
		if (lb->num > nb)
			return (-1);
		lb = lb->next;
	}
	return (-1);
}


//mettre a la bonne place le lit dans lb
int		ft_take_b_100(t_struct *data, int lit, int token)
{
	ft_printf("VOICI LA LISTE AVANT L'AJOUT\n");
	ft_printf("HAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n");
	ft_print_listb(data);
	ft_printf("il faut donc faire %d d'action dans b\n", lit);
	if (token == 1)
	{
		while (lit > 0)
		{
			data->lb = rb(data);
			lit--;
		}
	}
	else if (token == 0)
	{
		while (lit > 0)
		{
			data->lb = rrb(data);
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
	lit1 = ft_trie_100_b_little(data, little); // trouver un chiffre superieur
	lit2 = ft_trie_100_b_biggest(data, little);// trouver un chiffre inferieur
	ft_printf("================les deux tries donne================\nlittle =  %d et mon little little2 = %d\n", lit1, lit2);
	if (lit1 != -1 && lit2 != -1)
	{
		i = ft_found_best_place100(data, lb);
		ft_sort_b100(data, i);
	}
	else if (lit1 == -1)
		ft_take_b_100(data, lit2, 1);
	else if (lit2 == -1)
		ft_take_b_100(data, lit1, 0);
}

int		ft_found_best_place100(t_struct *data, t_list_b *lb)
{
	int			big;
	int			lit;
	int			i;

	big = lb->num;
	lit = lb->num;
	i = 0;
	while (lb->next && lb)
	{
		if (lb->num < lb->next->num)
			big = lb->next->num;
		else if (lb->num > lb->next->num)
			lit = lb->next->num;
		lb = lb->next;
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
	if (i > len)
	{
		while (i > len)
		{
			rrb(data);
			i--;
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

int		ft_take_best_place100(t_struct *data, int i, int big, int little)
{
	t_list_b	*lb;
	(void)little;
	(void)big;

	lb = data->lb->next;
	while (lb && lb->next)
	{
		if (data->la->next->num > lb->num && data->la->next->num < lb->next->num)
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
	(void)little;

	i = 0;
	lb = data->lb->next;
	nb = data->la->next->num;
	ft_printf("================on passe a la partie des chiffre inferieur================\ndata->lb->next = %d et mon little est de -> %d\n", lb->num, nb);
	while (lb)
	{
		if (nb < lb->num)
		{
			ft_printf("le little fonctionne donc il y a un chiffre superieur au chiffre de ma liste a, mon nb est egal a %d et mon num %d et le i %d\n", nb, lb->num, i);
			return (-1);
		}
		i++;
		lb = lb->next;
	}
	ft_printf("aucun chiffre superieur trouver\n");
	return (i);
}

//trouver si il y a des chiffres superieur
int		ft_trie_100_b_biggest(t_struct *data, int little)
{
	t_list_b	*lb;
	int			i;
	int			nb;

	i = 0;
	lb = data->lb->next;
	nb = data->la->next->num;
	ft_printf("================on passe a la partie des chiffre superieur================\ndata->lb->next = %d et mon little est de superieur-> %d\n", lb->num, little);
	while (lb)
	{
		if (nb > lb->num)
		{
			ft_printf("le little fonctionne donc il y a un chiffre inferieur a ma liste a, mon nb est egal a %d et mon num %d et le i %d\n", nb, lb->num, i);
			return (-1);
		}
		i++;
		lb = lb->next;
	}
	ft_printf("aucun chiffre inferieur trouver\n");
	return (i);
}

//mettre a la bonne place le lit dans lb
int		ft_take_b_100(t_struct *data, int lit, int token)
{
	t_list_b	*lb;
	(void)lb;

	lb = data->lb->next;
	ft_printf("VOICI LA LISTE AVANT L'AJOUT\n");
	ft_print_listb(data);
	ft_printf("il faut donc faire %d d'action dans b\n", lit);
	if (token == 1)
	{
		while (lit > 0)
		{
			data->lb = rb(data);
			lit--;
		}
	}
	else if (token == 0)
	{
		while (lit > 0)
		{
			data->lb = rrb(data);
			lit--;
		}
	}
	return (0);
}
*/

/*
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
