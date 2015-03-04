/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   neural_network_1.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vame <vame@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 15:40:25 by vame              #+#    #+#             */
/*   Updated: 2015/03/04 16:01:39 by vame             ###   ########.fr       */
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
# define RMV_ERR 8

typedef struct 		s_data
{
	int				fd;
	int				tng_nb;
	int				tng_mode;
	int				**tng_array;
	char			*nnw;
	char			*tng;
	float			**weight;
}					t_data;

/*
**	fonctions de gestion des poids
*/

void				weight_init(t_data *data);
int					calcul(int j, int k, t_data *data);
float				weight_calc(float value, int wanted_v, int out_v, int in_v);

/*
**	fonctions du menu
*/

void				menu_nnw(t_data *data);
void				menu_tng(t_data *data);
void				menu_tng_mode(t_data *data);

/*
**	fonctions de gestion des fichier .nnw et .tng
*/

int					open_nnw_file(t_data *data);
int					open_tng_file(t_data *data);
int					update_nnw_file(t_data *data);

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

/*
**	fonctions de traitement des donnees
*/

void				work(t_data *data);
void				learn(t_data *data, int j, int k, int res);
void				print_tab(int *tab);

#endif
