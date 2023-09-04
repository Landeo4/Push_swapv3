/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:14:19 by tpotilli@st       #+#    #+#             */
/*   Updated: 2023/09/04 07:49:23 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_struct	data;

	ft_init_struct(&data);
	if (argc == 1)
		return (pr_error("Not enough arguments."));
	else if (!args_handler(argc, argv, &data))
		return (0);
	else if (ft_len_lista(&data) == 1)
		return (pr_error("Not enough arguments."));
	// ft_algo_manager(&data, argc - 1);
	// ft_print_lista(&data);
	ft_free_lista(&data);
	ft_free_listb(&data);
}


// REPARER SA!!!!!!!
// courage beau gosse tu va le faire
// COME ON!