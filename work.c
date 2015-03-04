/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vame <vame@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 15:38:50 by vame              #+#    #+#             */
/*   Updated: 2015/03/02 16:51:11 by vame             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "neural_network_1.h"

void			just_print_res(float *tng_array, t_data *data)
{
	
}

void			work(t_data *data)
{
	int			j;

	j = 0;
	while (j < data->tng_nb)
	{
		if (data->tng_mode == 1)
			learn(data->tng_array[j], data);
		else
			just_print_res(data->tng_array[j], data);
		free(data->tng_array[j]);
		data->tng_array[j++] = NULL;
	}
	free(data->tng_array);
	data->tng_array = NULL;
}