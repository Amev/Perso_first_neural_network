/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vame <vame@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 15:38:50 by vame              #+#    #+#             */
/*   Updated: 2015/03/04 16:47:16 by vame             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "neural_network_1.h"

void			menu_nnw(t_data * data)
{
	char		*extension;

	data->nnw = NULL;
	data->tng = NULL;
	data->tng_mode = 0;
	data->weight = NULL;
	ft_printf("{grn}Please write the name of the working *.nnw file :\n$>{eoc} {wht}");
	while (1)
	{
		if (get_next_line_2(1, &data->nnw) == -1)
			exit(print_error(MAL_ERR));
		if (!ft_strcmp("exit", data->nnw))
			exit(1);
		extension = ft_strrchr(data->nnw, '.');
		if (extension && !ft_strcmp(extension, ".nnw"))
			break ;
		ft_printf("{eoc} {red}Bad extension, *.nnw file needed.{eoc}\n{grn}$>{eoc} {wht}");
		ft_strdel(&data->nnw);
	}
	if (!open_nnw_file(data))
		weight_init(data);
}

void			menu_tng_mode(t_data *data)
{
	char		*mode;

	if (!data->tng_mode)
	{
		ft_printf("{grn}Choose working mode :\n\t[1] : Training mode.\n\t[0] : Read only.\n$>{eoc} {wht}");
		while (1)
		{
			if (get_next_line_2(1, &mode) == -1)
				exit(print_error(MAL_ERR));
			if (!ft_strcmp("exit", mode))
				exit(1);
			data->tng_mode = ft_atoi(mode);
			ft_strdel(&mode);
			if (data->tng_mode  == 1 || data->tng_mode == 0)
				break;
			ft_printf("{eoc} {red}Bad option, please write 1 or 2{eoc}\n{grn}$>{eoc} {wht}");
		}
	}
}

void			menu_tng(t_data *data)
{
	char		*extension;

	ft_printf("{grn}Please write the name of the working *.tng file :\n$>{eoc} {wht}");
	while (1)
	{
		if (get_next_line_2(1, &data->tng) == -1)
			exit(print_error(MAL_ERR));
		if (!ft_strcmp("exit", data->tng))
			exit(1);
		extension = ft_strrchr(data->tng, '.');
		if (extension && !ft_strcmp(extension, ".tng"))
			break ;
		ft_printf("{eoc} {red}Bad extension, *.tng file needed.{eoc}\n{grn}$>{eoc} {wht}");
		ft_strdel(&data->tng);
	}
	open_tng_file(data);
}

int				main(void)
{
	t_data		data;

	menu_nnw(&data);
	menu_tng_mode(&data);
	while (1)
	{
		menu_tng(&data);
		work(&data);
		update_nnw_file(&data);
	}
	return (0);
}