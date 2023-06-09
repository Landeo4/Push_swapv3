/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: landeo <landeo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:14:19 by tpotilli@st       #+#    #+#             */
/*   Updated: 2023/07/05 18:44:43 by landeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_algo_manager(&data, argc - 1);
	ft_print_lista(&data);
	ft_free_lista(&data);
	ft_free_listb(&data);
}
