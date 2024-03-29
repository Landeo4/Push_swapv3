/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_writer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 07:38:41 by vsozonof          #+#    #+#             */
/*   Updated: 2023/09/04 07:07:12 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pr_error(char *error)
{
	ft_printf("\033[1;31m");
	ft_printf("Error: %s\n", error);
	ft_printf("\033[0;37m");
	return (0);
}
