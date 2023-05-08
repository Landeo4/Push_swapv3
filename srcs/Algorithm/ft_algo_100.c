/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_100.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:19:06 by tpotilli          #+#    #+#             */
/*   Updated: 2023/05/08 22:31:00 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	This function takes as parameter: 
**
**	data
**
** =====================================================
** =====================================================
**
** ft_algo_50 will sort all input under 100 except 10 and less
*/

void	ft_algo_100_manager(t_struct *data, int argc)
{
	int			moyenne;

	moyenne = ft_somme_algo_100(data, argc);
	ft_take_25_algo100(data, moyenne);
	ft_algo_100_helper(data);
}

//Créer une nouvelle liste chaînée vide, qui sera la liste triée.
//Prendre le premier élément de la liste d'origine.
//Insérer cet élément dans la nouvelle liste triée, en cherchant sa position fait 
//dans la liste triée et en déplaçant les éléments existants pour faire de la place si nécessaire.
//Répéter les étapes 2 et 3 pour chaque élément de la liste d'origine.

// recup plusieurs chiffre a mettre dans le b
/*
void	ft_take_25_algo100(t_struct *data, int moyenne)
{
	int			len;
	t_list_a	*tmp;

	tmp = data->la->next;
	len = ft_len_lista(data);
	len = len / 4;
	len += 4;
	ft_printf("len = %d\n", len);
	moyenne = moyenne / 2;
	if (tmp->num < moyenne)
		tmp = pb(data);
	while (len > 0)
	{
		tmp = ra(data);
		tmp = data->la->next;
		while (tmp->num < moyenne)
		{
			ft_printf("debut de la boucle pb");
			ft_print_listb(data);
			len--;
			tmp = pb(data);
			tmp = data->la->next;
		}
		len--;
	}
}
*/

void	ft_take_25_algo100(t_struct *data, int moyenne)
{
	int			len;
	t_list_a	*tmp;

	tmp = data->la->next;
	len = ft_len_lista(data);
	len = len / 4;
	len += 3;
	ft_printf("len = %d\n", len);
	moyenne = moyenne / 2;
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

void	ft_tri_25_algo100(t_struct *data)
{
	t_list_b	*lb;
	int			len;

	len = ft_len_listb(data);
	lb = data->lb->next;
	ft_printf("helllllllllo");
	while (ft_verif_25(data, len) == 0)
	{
		ft_printf("hry");
		while (lb)
		{
			if (lb->num > lb->next->num)
			{
				sb(data->lb);
				rra(data);
			}
		}
		lb = data->lb->next;
	}
}

bool	ft_verif_25(t_struct *data, int len)
{
	t_list_b	*lb;

	lb = data->lb->next;
	while (lb && len > 0)
	{
		if (lb->num > 25)
			return (0);
		lb = lb->next;
		len--;
	}
	return (1);
}

// cette fonction check si il y a bien des nb plus
// petit que 25 a partir de la len

/*
void	ft_algo_100_manager(t_struct *data)
{
	//int			i;
	t_list_b	*lb;

	lb = data->lb->next;
	ft_take_25_algo100(data);
	ft_trie_25_algo_100(data, lb);
	//ft_trie_50_algo_100(data, la);
}

//Créer une nouvelle liste chaînée vide, qui sera la liste triée.
//Prendre le premier élément de la liste d'origine.
//Insérer cet élément dans la nouvelle liste triée, en cherchant sa position fait 
//dans la liste triée et en déplaçant les éléments existants pour faire de la place si nécessaire.
//Répéter les étapes 2 et 3 pour chaque élément de la liste d'origine.

void	ft_trie_25_algo_100(t_struct *data, t_list_b *lb)
{
	//int nb;

	if (lb->num < lb->next->num)
		sb(lb);
	while (lb)
	{
		ft_search_min25_100(data, lb);
		("YOOOOOOOOOOOOOOO");
		if (lb->num > lb->next->num)
		{
			ft_freeatb(data, )
			ft_addatb(data, )
		}
		lb = lb->next;
	}
}

int		ft_search_min25_100(t_struct *data, t_list_b *lb)
{
	int			nb;
	int			cpt;

	nb = ft_get_min_100_25(data);
	("YOOOOOOOOOOOOOOO");
	cpt = 1;
	while (lb->num != nb)
	{
		lb = lb->next;
		cpt++;
	}
	("\n cpt = %d", cpt);
	return (cpt);
}

int	ft_get_min_100_25(t_struct *data)
{
	int			nb;
	t_list_b	*lb;

	lb = data->lb->next;
	nb = lb->next->num;
	while (lb)
	{
		if (lb->num < nb)
			nb = lb->num;
		lb = lb->next;
	}
	("\nnb = %d", nb);
	("YOOOOOOOOOOOOOOO");
	return (nb);
}


void	ft_trie_50_algo_100(t_struct *data, t_list_a *la)
{
	
}

// recup plusieurs chiffre a mettre dans le b

void	ft_take_25_algo100(t_struct *data)
{
	int	len;
	t_list_a	*la;

	len = ft_len_lista(data) / 4;
	la = data->la->next;
	while (la && len > 0)
	{
		pb(data);
		len--;
		la = la->next;
	}
}
*/

/*
void	ft_algo_100_manager(t_struct *data)
{
	//int			i;
	t_list_a	*la;
	int			len;
	//int	cpt;
	//int	nb;

	len = ft_len_lista(data);
	len = 0;
	la = data->la->next;
	(void)la;
	while (len < 25)
	{
		ft_take_25_algo100(data);
		len++;
	}
}

//Créer une nouvelle liste chaînée vide, qui sera la liste triée.
//Prendre le premier élément de la liste d'origine.
//Insérer cet élément dans la nouvelle liste triée, en cherchant sa position fait 
//dans la liste triée et en déplaçant les éléments existants pour faire de la place si nécessaire.
//Répéter les étapes 2 et 3 pour chaque élément de la liste d'origine.

// recup plusieurs chiffre a mettre dans le b
void	ft_take_25_algo100(t_struct *data)
{
	int	cpt;
	int	nb;
	int	len;

	len = ft_len_lista(data);
	len = len * 4;
	cpt = ft_get_cpt_100(data);
	while (len > 0)
	{
		if (ft)
	}
}
// cette fonction check si il y a bien des nb plus
// petit que 25 a partir de la len
bool	ft_100_check(t_struct *data, int len)
{
	t_list_a	*la;
	int			i;

	la = data->la->next;
	while (la && len > 0)
	{
		if (la->num > 25)
			return (0);
		la = la->next;
		i++;
		len--;
	}
	return (1);
}

// cette fonction sert a recup le plus
//petit chiffre de la liste

int	ft_get_min_100_25(t_struct *data, int len)
{
	int			nb;
	t_list_a	*la;
	(void)len;

	la = data->la->next;
	nb = la->next->num;
	while (la)
	{
		if (la->num < nb)
			nb = la->num;
		la = la->next;
	}
	return (nb);
}

int	ft_get_min_100_75(t_struct *data, int len)
{
	int			nb;
	t_list_a	*la;
	(void)len;

	la = data->la->next;
	nb = la->next->num;
	while (la)
	{
		if (la->num < nb)
			nb = la->num;
		la = la->next;
	}
	return (nb);
}
// cette fonction sert a recup la pos
// de la liste
// cette fonction sert a recup la pos
// de la liste
int		ft_get_cpt_100(t_struct *data)
{
	int			nb;
	t_list_a	*la;
	int			cpt;

	cpt = 0;
	la = data->la->next;
	nb = la->next->num;
	while (la->next)
	{
		if (la->num < nb)
			nb = la->num;
		cpt++;
		la = la->next;
	}
	return (cpt);
}
*/

/*
void	ft_algo_100_manager(t_struct *data)
{
	//int			i;
	t_list_a	*la;
	int			len;
	//int	cpt;
	//int	nb;

	len = ft_len_lista(data);
	len = 0;
	la = data->la->next;
	(void)la;
	while (len < 25)
	{
		ft_take_25_algo100(data);
		len++;
	}
}

//Créer une nouvelle liste chaînée vide, qui sera la liste triée.
//Prendre le premier élément de la liste d'origine.
//Insérer cet élément dans la nouvelle liste triée, en cherchant sa position fait 
//dans la liste triée et en déplaçant les éléments existants pour faire de la place si nécessaire.
//Répéter les étapes 2 et 3 pour chaque élément de la liste d'origine.

// recup plusieurs chiffre a mettre dans le b
void	ft_take_25_algo100(t_struct *data)
{
	int	cpt;
	int	nb;
	int	len;

	len = ft_len_lista(data);
	len = len * 4;
	cpt = ft_get_cpt_100(data);
	nb = ft_get_min_100_25(data, len);
	if (cpt < len)
	{
		while (nb != data->la->next->num)
			ra(data);
		pb(data);
		return ;
	}
	//len = len * 0.75;
	if (cpt > len)
	{
		while (nb != data->la->next->num)
		{
			("cpt = %d et nb = %d et data = %d", cpt, nb,  data->la->next->num);
			rra(data);
		}
		pb(data);
		return ;
	}
}
// cette fonction sert a recup le plus
//petit chiffre de la liste
// cette fonction renvois bien pour la len donner
int	ft_get_min_100_25(t_struct *data, int len)
{
	int			nb;
	t_list_a	*la;
	(void)len;

	la = data->la->next;
	nb = la->next->num;
	while (la)
	{
		if (la->num < nb)
			nb = la->num;
		la = la->next;
	}
	return (nb);
}

int	ft_get_min_100_75(t_struct *data, int len)
{
	int			nb;
	t_list_a	*la;
	(void)len;

	la = data->la->next;
	nb = la->next->num;
	while (la)
	{
		if (la->num < nb)
			nb = la->num;
		la = la->next;
	}
	return (nb);
}
// cette fonction sert a recup la pos
// de la liste
// cette fonction sert a recup la pos
// de la liste
int		ft_get_cpt_100(t_struct *data)
{
	int			nb;
	t_list_a	*la;
	int			cpt;

	cpt = 0;
	la = data->la->next;
	while (la)
	{
		if (la->num < nb)
			nb = la->num;
		cpt++;
		la = la->next;
	}
	return (cpt);
}
*/

/*
void	ft_algo_100_manager(t_struct *data)
{
	//int			i;
	t_list_a	*la;
	int			len;
	//int	cpt;
	//int	nb;

	len = ft_len_lista(data);
	len = len / 4;
	la = data->la->next;
	(void)la;
	while (len < 25)
	{
		ft_take_25_algo100(data);
		len++;
	}
}

Créer une nouvelle liste chaînée vide, qui sera la liste triée.
Prendre le premier élément de la liste d'origine.
Insérer cet élément dans la nouvelle liste triée, en cherchant sa position fait 
dans la liste triée et en déplaçant les éléments existants pour faire de la place si nécessaire.
Répéter les étapes 2 et 3 pour chaque élément de la liste d'origine.

// recup plusieurs chiffre a mettre dans le b
void	ft_take_25_algo100(t_struct *data)
{
	int	cpt;
	int	nb;
	int	len;

	len = ft_len_lista(data);
	len = len / 4;
	cpt = ft_get_cpt_100(data);
	nb = ft_get_min_100(data);
	//("\ndans ra cpt = %d et nb = %d et data = %d et len = %d la len max est %d", cpt, nb,  data->la->next->num, len, ft_len_lista(data));
	if ((nb >= 0 && nb <= 25) || (nb > 75 && nb <= 99))
	{
		if (cpt < len)
		{
			while (nb != data->la->next->num)
			{
				//("dans ra cpt = %d et nb = %d et data = %d", cpt, nb,  data->la->next->num);
				ra(data);
			}
			pb(data);
			return ;
		}
		else if (cpt > 3 * len)
		{
				//("dans la deuxieme boucle %d et nb = %d et data = %d", cpt, nb,  data->la->next->num);
			while (nb != data->la->next->num)
			{
				//("dans rra cpt = %d et nb = %d et data = %d", cpt, nb,  data->la->next->num);
				rra(data);
			}
			pb(data);
			return ;
		}
	}
}
// cette fonction sert a recup le plus
//petit chiffre de la liste
int	ft_get_min_100(t_struct *data)
{
	int			nb;
	t_list_a	*la;

	la = data->la->next;
	nb = la->next->num;
	if ((nb >= 0 && nb <= 25) || (nb > 75 && nb <= 99))
	{
		while (la)
		{
			if (la->num < nb)
				nb = la->num;
			la = la->next;
		}
	}
	return (nb);
}
// cette fonction sert a recup la pos
// de la liste
int		ft_get_cpt_100(t_struct *data)
{
	int			nb;
	t_list_a	*la;
	int			cpt;

	cpt = 1;
	la = data->la->next;
	nb = ft_get_min_100(data);
	while (la->num != nb)
	{
		la = la->next;
		cpt++;
	}
	return (cpt);
}

*/

/*
void	ft_algo_100_manager(t_struct *data)
{
	//int			i;
	t_list_a	*la;
	int			len;
	//int	cpt;
	//int	nb;

	len = ft_len_lista(data);
	len = len / 4;
	la = data->la->next;
	(void)la;
	ft_take_25_algo100(data);
	ft_take_25_algo100(data);
	ft_take_25_algo100(data);
	while (len < 25)
	{
		ft_take_25_algo100(data);
		len++;
	}
}

Créer une nouvelle liste chaînée vide, qui sera la liste triée.
Prendre le premier élément de la liste d'origine.
Insérer cet élément dans la nouvelle liste triée, en cherchant sa position fait 
dans la liste triée et en déplaçant les éléments existants pour faire de la place si nécessaire.
Répéter les étapes 2 et 3 pour chaque élément de la liste d'origine.

// recup plusieurs chiffre a mettre dans le b
void	ft_take_25_algo100(t_struct *data)
{
	int	cpt;
	int	nb;
	int	len;

	len = ft_len_lista(data);
	cpt = ft_get_cpt_100(data);
	nb = ft_get_min_100(data);
	len = len / 4;
	if (cpt < len)
	{
		while (nb != data->la->next->num)
			ra(data);
		pb(data);
		return ;
	}
	len = len / 2;
	if (cpt > len)
	{
		while (nb != data->la->next->num)
		{
			("cpt = %d et nb = %d et data = %d", cpt, nb,  data->la->next->num);
			rra(data);
		}
		pb(data);
		return ;
	}
}
// cette fonction sert a recup le plus
//petit chiffre de la liste
int	ft_get_min_100(t_struct *data)
{
	int			nb;
	t_list_a	*la;

	la = data->la->next;
	nb = la->next->num;
	while (la)
	{
		if (la->num < nb)
			nb = la->num;
		la = la->next;
	}
	return (nb);
}
// cette fonction sert a recup la pos
// de la liste
int		ft_get_cpt_100(t_struct *data)
{
	int			nb;
	t_list_a	*la;
	int			cpt;

	cpt = 0;
	la = data->la->next;
	while (la)
	{
		if (la->num < nb)
			nb = la->num;
		cpt++;
		la = la->next;
	}
	return (cpt);
}

*/

/*
void	ft_change_one_place(t_struct *data, t_list_a *la)
{
	int	i;

	i = 1;
	while (la)
	{
		
	}
}

void	ft_check_little(t_struct *data, t_list_a *la)
{
	
}
*/
