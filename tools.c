/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vame <vame@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 15:53:59 by vame              #+#    #+#             */
/*   Updated: 2015/03/02 16:15:45 by vame             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "neural_network_1.h"

int					print_error(int err)
{
	if (err == MAL_ERR)
		ft_printf("{red}Malloc error.{eoc}\n");
	if (err == OPN_ERR)
		ft_printf("{red}Open error: file not found.{eoc}\n");
	if (err == RED_ERR)
		ft_printf("{red}Read error.{eoc}\n");
	if (err == CLS_ERR)
		ft_printf("{red}Close error.{eoc}\n");
	if (err == GNL_ERR)
		ft_printf("{red}Get_next_line error.{eoc}\n");
	if (err == FMT_ERR)
		ft_printf("{red}Bad number's format in .nnw or .tng file.{eoc}\n");
	if (err == TNG_ERR)
		ft_printf("{red}.tng file not found.{eoc}\n");
	return (-1);
}
