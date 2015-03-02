#include "neural_network_1.h"

/*
**	Faire une interface complète :
**		1 - lancement du programme sans paramètre ou sans tenir compte des paramètres
**			(possibilité d'améliorer en prenant en compte les paramètres si valides)
**		2 - demande du nom du fichier nnw :
**			a - si fichier valide et existant -> étape 3
**			b - si fichier valide mais non existant -> création du fichier et passage étape 3a
**			c - si fichier non valide -> retour étape 2
**		3 - choix du mode de travail :
**			a - mode trainning :
**				o. demande du fichier tng jusqu'a fichier valide
**				o. entrainement du réseau avec maj des poids.
**			b - mode lecture seule :
**				o. demande du fichier tng jusqu'a fichier valide et réponse du programme puis fin exec
*/

int				menu(t_data *data)
{
	char		*extension;
	char		*mode;

	data->nnw = NULL;
	data->tng = NULL;
	data->tng_mode = 0;
	data->weight = NULL;
	ft_printf("Please write the name of the working *.nnw file :\n$> ");
	while (1)
	{
		if (get_next_line_2(1, &data->nnw) == -1)
			exit(print_error(MAL_ERR));
		extension = ft_strrchr(line, '.');
		if (extension && !ft_strcmp(extension, ".nnw"))
			break ;
		ft_printf("Bad extension, *.nnw file needed.\n$> ");
		ft_strdel(&data->nnw);
	}
	if (!open_nnw_file(data))
		weight_init(&data->weight);
	if (!data->tng_mode)
	{
		ft_printf("Choose working mode :\n\t[1] : Training mode.\n\t[0] : Read only.\n$> ");
		while (1)
		{
			if (get_next_line_2(1, &mode) = -1)
				exit(print_error(MAL_ERR));
			data->tng_mode = ft_atoi(mode);
			ft_strdel(&mode);
			if (data->tng_mode  == 1 || data->tng_mode == 0)
				break;
			ft_printf("Bad option, please write 1 or 2\n$> ");
		}
	}
	ft_printf("Please write the name of the working *.tng file :\n$> ");
	while (1)
	{
		if (get_next_line_2(1, &data->tng) == -1)
			exit(print_error(MAL_ERR));
		extension = ft_strrchr(line, '.');
		if (extension && !ft_strcmp(extension, ".tng"))
			break ;
		ft_printf("Bad extension, *.tng file needed.\n$> ");
		ft_strdel(&data->tng);
	}
	return (1);
}

int				main(int ac, char **av)
{
	t_data		data;

	menu(&data);
}