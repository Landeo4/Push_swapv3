/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: landeo <landeo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:14:19 by tpotilli@st       #+#    #+#             */
/*   Updated: 2023/06/07 15:32:21 by landeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
int main(int argc, char **argv)
{
	ft_parsing_manager(argc, argv);
	return (0);
}
*/

/*
sa sb ss
int main(int argc, char **argv)
{
	(void)argc;
	int i;
	t_list_b *lb;
	t_list_a *la;

	la = NULL;
	la = ft_first_la(la);
	lb = NULL;
	lb = ft_first_lb(lb);
	i = 1;
	while (argv[i])
	{
		la = ft_addAt(la, ft_atoi(argv[i]), 1);
		lb = ft_addAtb(lb, ft_atoi(argv[i]), 1);
		i++;
	}
	ft_print_both(la, lb);
	printf("\n");
	sa(la);
	sb(lb);
	ft_print_both(la, lb);
	ft_free_lista(la);
	ft_free_listb(lb);
	return (0);
}
*/

/*
pb pa
int main(int argc, char **argv)
{
	(void)argc;
	int i;
	t_list_b *lb;
	t_list_a *la;

	la = NULL;
	lb = NULL;
	la = ft_first_la(la);
	lb = ft_first_lb(lb);
	i = 1;
	while (argv[i])
	{
		la = ft_addAt(la, ft_atoi(argv[i]), 1);
		i++;
	}
	ft_print_lista(la);
	sa(la);
	pb(la, lb);
	pb(la, lb);
	pb(la, lb);
	printf("\napres le passage de pb :\n");
	ft_print_lista(la);
	ft_print_listb(lb);
	pa(la, lb);
	pa(la, lb);
	pa(la, lb);
	ft_print_lista(la);
	ft_print_listb(lb);
	ft_free_both(la, lb);
	return (0);
}
*/

/*int main(int argc, char **argv)
{
	(void)argc;
	int i;
	//t_list_b *lb;
	t_list_a *la;

	la = NULL;
	//lb = NULL;
	la = ft_first_la(la);
	//lb = ft_first_lb(lb);
	i = 1;
	while (argv[i])
	{
		la = ft_addAt(la, ft_atoi(argv[i]), 1);
		i++;
	}
	ft_print_lista(la);
	ra(la);
	printf("apres ra\n");
	ft_print_lista(la);
	return (0);
}*/

/*
int main(int argc, char *argv[])
{
	(void)argc;
	t_list_a *la = NULL;
	t_list_b *lb = NULL;
	la = ft_first_la(la);
	lb = ft_first_lb(lb);

	int i = 1;
	while (argv[i])
	{
		la = ft_addAt(la, ft_atoi(argv[i]), 1);
		lb = ft_addAtb(lb, ft_atoi(argv[i]), 1);
		i++;
	}
	ft_print_lista(la);
	ft_print_listb(lb);
	lb = rb(lb);
	printf("\n");
	la = ra(la);
	ft_print_lista(la);
	ft_print_listb(lb);
	return 0;
}
*/

/*
int main(int argc, char *argv[])
{
	(void)argc;
	t_list_b *lb;
	int i;

	lb = NULL;
	lb = ft_first_lb(lb);
	i = 1;
	while (argv[i])
	{
		lb = ft_addAtb(lb, ft_atoi(argv[i]), 1);
		i++;
	}
	ft_print_listb(lb);
	rb(lb);
	printf("\n\n\n");
	ft_print_listb(lb);
	ft_free_listb(lb);
	return 0;
}
*/
/*
void	ft_init_struct(t_struct *data)
{
	data->la = NULL;
	data->lb = NULL;
	data->la = ft_first_la(data->la);
	data->lb = ft_first_lb(data->lb);
}
*/
/*int main(int argc, char **argv)
{
	(void)argc;
	//ft_parsing_manager(argc, argv);
	
	t_struct data;
	ft_init_struct(&data);
	int i = 1;
	while (argv[i])
	{
		ft_addAt(&data, ft_atoi(argv[i]), 1);
		i++;
	}
	ft_print_lista(la);
	ft_algo_manager(la, lb);
	printf("\n");
	ft_print_lista(la);
	return (0);
}*/
 /*
int main(int argc, char **argv)
{
	(void)argc;
	//ft_parsing_manager(argc, argv);
	
	t_struct data;
	ft_init_struct(&data);
	int i = 1;
	while (argv[i])
	{
		ft_addAt_a(&data, ft_atoi(argv[i]), 1);
		i++;
	}
	ft_print_lista(data.la);
}
*/

/*
int main(int argc, char **argv)
{
	t_struct data;
	int	i;

	i = 1;
	if (ft_parsing_manager(argc, argv) == 0)
		return (0);
	ft_printf("c'est bon pour les guillemet");
	ft_init_struct(&data);
	while (argv[i])
	{
		ft_addata(&data, ft_atoi(argv[i]), 1);
		i++;
	}
	ft_print_lista(&data);
	ft_algo_manager(&data, argc - 1);
	//ft_printf("ypo");
	ft_print_lista(&data);
	ft_free_lista(&data);
	ft_free_listb(&data);
}*/

int main(int argc, char **argv)
{
	t_struct data;
	int	i;
	//int pos;

	i = argc - 1;
	/*if (ft_parsing_manager(argc, argv) == 0)
		return (0);
	ft_printf("c'est bon pour les guillemet");*/
	ft_init_struct(&data);
	while (i > 0)
	{
		ft_addata(&data, ft_atoi(argv[i]), 1);
		i--;
	}
	//ft_print_lista(&data);
	ft_algo_manager(&data, argc - 1);
	/*nb = ft_get_min_100(&data);
	ft_printf("\nle cpt vaut a la fin%d", nb);
	pos = ft_get_cpt_100(&data);
	ft_printf("\nla position vaut bien a la fin %d", pos);
	ft_algo_100_manager(&data);
	ft_printf("ypo");
	ft_print_lista(&data);
	data.la = ra(&data);
	ft_printf("\nliste a =\n");
	ft_print_lista(&data);
	data.la = ra(&data);*/
	//ft_printf("\nliste a =\n");
	/*data.la = ft_addata(&data, 13, 1);
	data.la = ft_addata(&data, 2, 1);
	data.la = ft_addata(&data, 3, 1);
	data.la = pb(&data);
	data.la = pb(&data);
	data.lb = rb(&data);
	data.lb = rrb(&data);
	data.lb = sb(data.lb, &data);
	data.lb = sb(data.lb, &data);*/
	ft_print_lista(&data);
	ft_printf("\nliste b =\n");
	ft_print_listb(&data);
	ft_free_lista(&data);
	ft_free_listb(&data);
}

/*
valgrind ./Push_Swap 7 86 20 78 61 30 18 50 15 70 39 54 63 3 90 92 71 25 77 43 29 14 54 67 33 27 55 42 91 44 11 16 31 2 48 68 19 76 87 97 75 59 9 23 98 85 22 89 72 84 64 58 52 66 36 62 94 69 46 37 53 40 10 96 60 21 24 6 57 35 83 73 45 95 12 47 49 81 32 65 5 99 89 8 56 80 34 41 28 93 1 74 17 38 88 0 82 13 26 4
*/
