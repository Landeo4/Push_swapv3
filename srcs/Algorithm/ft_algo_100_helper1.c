/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_100_helper1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:59:10 by tpotilli          #+#    #+#             */
/*   Updated: 2023/06/13 10:50:24 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//voir idee sur cailler
// la somme est good

int	ft_found_pos_little_first_part(t_struct *data, int chunk, t_list_a *la)
{
	int			i;
	t_list_a	*tab;
	int			nb;
	int			len;

	len = ft_len_lista(data);
	len = len / 5;
	i = 1;
	tab = la;
	nb = la->num;
	while (tab && len > 0)
	{
		ft_printf("data->la->num = %d et la moyenne est de %d\n", nb, chunk);
		if (nb <= chunk)
		{
			ft_printf("nb est inferieur car nb est egal a %d\n", nb);
			return (i);
		}
		i++;
		len--;
		tab = tab->next;
		nb = tab->num;
	}
	return (-1);
}

int	ft_found_pos_little_last_part(t_struct *data, int chunk, t_list_a *la)
{
	int			i;
	t_list_a	*tab;
	int			len;
	int			len2;
	
	len2 = 1;
	len = ft_len_lista(data);
	len = len * 0.75;
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
	printf(" mon i a la sortie de last part est egale a %i\n", i);
	return (i);
}

int	ft_found_little_100_25(t_struct *data, int pos)
{
	t_list_a	*tab;
	int			nb;

	tab = data->la->next;
	nb = ft_found_little(data);
	while (pos != 0)
	{
		nb = tab->num;
		tab = tab->next;
		pos--;
	}
	ft_printf("du coup mon premier chiffre est de %d\n", nb);
	return (nb);
}

int	ft_found_little_100_75(t_struct *data, int pos, t_list_a *la)
{
	t_list_a	*tab;
	int			nb;
	int			ch;
	int			len;

	ch = ft_len_lista(data);
	ch = ch - pos;
	len = 0;
	tab = la;
	while (len != ch)
	{
		tab = tab->next;
		nb = tab->num;
		len++;
	}
	return (nb);
}

/*
int	ft_found_pos_little_chunk1(t_struct *data, int chunk, t_list_a *la)
{
	int			i;
	t_list_a	*tab;(double)yenne est de %d\n", nb, chunk);
	while (tab && len > 0)
	{
		ft_printf("data->la->num = %d et la moyenne est de %d\n", nb, chunk);
		if (nb <= chunk)
		{
			ft_printf("data->la->num = %d et la moyenne est de %d\n", nb, chunk);
			ft_printf("nb est inferieur car nb est egal a %d\n", nb);
			return (i);
		}
		i++;
		len--;
		tab = tab->next;
		nb = tab->num;
	}
	return (-1);
}

int	ft_found_pos_little_chunk5(t_struct *data, int chunk, t_list_a *la)
{
	int			i;
	t_list_a	*tab;
	int			len;
	int			len2;

	len2 = 1;
	len = ft_len_lista(data);
	len = len * 0.75;
	i = len / 5;
	tab = la->next;
	while (len2 < len)
	{
		tab = tab->next;
		len2++;
	}
	len = ft_len_lista(data);
	while (len2 < len)
	{
		if (tab->num < chunk)
		{
			i = 0;
		}
		tab = tab->next;
		len2++;
		i++;
	}
	ft_printf("ma position pour la fin de la liste est a %d\n", i);
	return (-1);
}
*/


/*
int	ft_found_pos_little_chunk1(t_struct *data)
{
	int			i;
	t_list_a	*tab;
	int			nb;
	int			len;

	len = ft_len_lista(data);
	len = len / 5;
	i = 1;
	tab = data->la->next;
	nb = ft_found_little(data);
	while (tab && len > 0)
	{
		if (nb != tab->num)
			tab = tab->next;
		i++;
		len--;
	}
	return (i);
}

int	ft_found_pos_little_chunk5(t_struct *data)
{
	int			i;
	t_list_a	*tab;
	int			nb;
	int			len;
	int			len2;

	len2 = 1;
	len = ft_len_lista(data);
	len = len * 0.75;
	i = 100;
	tab = data->la->next;
	nb = tab->num;
	while (len2 != len)
	{
		tab = tab->next;
		len2++;
	}
	len = ft_len_lista(data);
	while (tab && len2 < len)
	{
		if (nb != tab->num)
			tab = tab->next;
		else
			break ;
		i--;
		len++;
	}
	return (i);
}

int	ft_found_little_100_25(t_struct *data)
{
	int			i;
	t_list_a	*tab;
	int			nb;
	int			len;

	len = ft_len_lista(data);
	len = len / 5;
	i = 1;
	tab = data->la->next;
	nb = ft_found_little(data);
	while (tab && len > 0)
	{
		if (nb != tab->num)
			tab = tab->next;
		i++;
		len--;
	}
	return (nb);
}

int	ft_found_little_100_75(t_struct *data)
{
	int			i;
	t_list_a	*tab;
	int			nb;
	int			len;
	int			len2;

	len2 = 1;
	len = ft_len_lista(data);
	len = len * 0.75;
	i = 100;
	tab = data->la->next;
	nb = tab->num;
	while (len2 != len)
	{
		tab = tab->next;
		len2++;
	}
	len = ft_len_lista(data);
	while (tab && len2 < len)
	{
		if (nb > tab->num)
			nb = tab->num;
		tab = tab->next;
		i--;
		len++;
	}
	return (nb);
}
*/

/*
int ft_somme_algo_100(t_struct *data, int argc)
{
	t_list_a	*la;
	int			somme;

	argc--;
	la = data->la->next;
	somme = 0;
	while (la)
	{
		somme += la->num;
		la = la->next;
	}
	somme = somme / argc;
	return (somme);
}

bool	ft_tri_100_done(t_struct *data)
{
	t_list_b	*lb;
	int			len;

	len = ft_len_listb(data);
	lb = data->lb->next;
	while (lb->next && len > 0)
	{
		if (lb->num < lb->next->num)
			return (0);
		lb = lb->next;
		len--;
	}
	return (1);
}
*/

/*
ce que je pense faire c'est cree un tableau 
qui sera exactement comme ma liste
Ensuite je fais le radix dans mon tableau
into je cree une variable de position qui va prendre 
la position du plus petit nombre de mon tableau 
(je recup aussi le nb pour etre sur)
et je tri sur ma vrai liste en comparant les deux
je pense que comme ca fera un nombre d'action "ok"
tout en mettant en place un systheme un peux plus opti 
sur mes actions a base de si la len/2 et len/3
*/

/*
maintenant j'ai reussis a trier la liste suivant l'uniter
maintenant il faut faire en sorte que ma liste d'origine 
puisse avoir le meme classement
*/

/*
la division permet d'avoir les dizaines
*/

/*
int	*ft_100_tab_manager(t_struct *data)
{
	int			*tab;
	t_list_a	*la;

	la = data->la->next;
	tab = ft_100_tab(la, data);
	tab = ft_get_first_unit(tab, la, data);
	return (tab);
}

//la m'a liste est dans le tableau
int	*ft_100_tab(t_list_a *la, t_struct *data)
{
	int		*tab;
	int		i;

	i = 0;
	tab = malloc(sizeof(int) * ft_len_lista(data));
	if (tab == NULL)
		return (0);
	("\n----debut des valeurs du tableau----");
	while (la)
	{
		tab[i] = la->num;
		("\n%i", tab[i]);
		i++;
		la = la->next;
	}
	("\n----fin des valeurs du tableau----");
	return (tab);
}

int	*ft_get_first_unit(int *tab, t_list_a *la, t_struct *data)
{
	int		i;
	int		*tmp;
	int		len;

	len = ft_len_lista(data);
	tmp = ft_100_tab(la, data);
	i = 0;
	while (len != 0)
	{
		if (tab[i] >= 10)
			tmp[i] %= 10;
		//("\nle nouveau modulo est de (%d)%d", tab[i], tmp[i]);
		len--;
		i++;
	}
	i = 0;
	tmp = ft_tri_100(tmp, data);
	len = ft_len_lista(data);
	while (i < len)
	{
		("\nle tableau au complet = (%d)%d",tab[i], tmp[i]);
		i++;
	}
	//tmp = ft_essaie(tmp, data, tab);
	return (tmp);
}

int	*ft_tri_100(int	*tmp, t_struct *data)
{
	int	i;
	int	a;
	int	b;
	int	j;
	int	size;

	size = ft_len_lista(data);
	j = 1;
	i = 0;
	while (ft_tab_checker(tmp, data) == 0)
	{
		while (i < size)
		{
			a = tmp[i];
			b = tmp[j];
			if (tmp[i] > tmp[j])
			{
				tmp[i] = b;
				tmp[j] = a;
			}
			i++;
			j++;
			//("\nla valeur est %d et i = %d", tmp[i], i);
		}
		size = ft_len_lista(data);
		i = 0;
		j = i + 1;
	}
	return (tmp);
}

bool	ft_tab_checker(int *tmp, t_struct *data)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 1;
	len = ft_len_lista(data);
	while (i < len)
	{
		if (tmp[i] > tmp[j])
			return (0);
		i++;
		j++;
	}
	return (1);
}

int	*ft_essaie(int *tmp, t_struct *data, int *tab)
{
	int	i;
	int	j;
	(void)data;
	(void)tmp;
	(void)j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		i++;
	}
	return (tmp);
}
*/

/*
int		*ft_get_first_unit(int *tab, t_list_a *la, t_struct *data)
{
	int		i;
	int		*tmp;
	int		len;

	len = ft_len_lista(data);
	tmp = ft_100_tab(la, data);
	i = 0;
	while (len != 0)
	{
		//("\navant le modulo = %d", tmp[i]);
		if (tab[i] >= 10)
			tmp[i] %= 10;
		//(" ->  %d", tmp[i]);
		i++;
		len--;
	}
	i = 0;
	len = ft_len_lista(data);
	while (ft_tab_checker(tmp, data) != 1)
	{
		while (tmp[i])
		{
			tmp = ft_swap(tmp, i, (i + 1));
			i++;
			("\napres le swap %d", tmp[i]);
			i++;
		}
		i = 0;
	}
	i = 0;
	while (len)
	{
		("\nle tableau au complet = %d", tmp[i]);
		len--;
		i++;
	}
	return (tab);
}

bool	ft_tab_checker(int *tmp, t_struct *data)
{
	int	i;
	int	len;

	len = ft_len_lista(data);
	i = 0;
	while (tmp[i] < tmp[i + 1])
		i++;
	if (i == len)
		return (1);
	return (0);
}
*/