/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   neural_network_1.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vame <vame@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 15:40:25 by vame              #+#    #+#             */
/*   Updated: 2015/03/02 17:07:24 by vame             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEURAL_NETWORK_1
# define NEURAL_NETWORK_1

# include "libft/libft_ext.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/uio.h>
# include <sys/types.h>
# include <fcntl.h>

# define MAL_ERR 1
# define OPN_ERR 2
# define RED_ERR 3
# define CLS_ERR 4
# define GNL_ERR 5
# define FMT_ERR 6
# define TNG_ERR 7

typedef struct 		s_data
{
	int				fd;
	int				tng_mode;
	int				tng_array;
	char			*nnw;
	char			*tng;
	float			**weight;
}					t_data;

/*
**	fonctions de gestion des poids
*/

void				weight_init(float ***weight);

/*
**	fonctions du menu
*/

int					menu(t_data *data);

/*
**	fonctions de gestion du fichier .nnw
*/

int					open_nnw_file(t_data *data);

/*
**	outils pour les fichiers
*/

float				**create_array(int x, int y);
char				**join_line(char **line, char ***read);
char				**read_file(char *path);

/*
**	fonctions outils
*/

int					print_error(int err);

#endif
