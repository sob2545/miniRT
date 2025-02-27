/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_func.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:04:50 by sesim             #+#    #+#             */
/*   Updated: 2022/10/26 12:14:35 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_FUNC_H
# define MY_FUNC_H

# include "libft.h"

/*****  my open funcs  *****/
int			my_open_rt(const char *path, int oflag);

/*****  my alloc funcs  *****/
void		*my_calloc(size_t count, size_t size);
char		**my_split(char *line, char c);

/*****  my free funcs  *****/
void		split_free(char **split);
void		info_free(t_info *info, t_mlx *mlx);

/*****  my error funcs  *****/
void		ft_strerror(char *err);

/***** my parse funcs *****/
double		ft_atod(char *str);
int			ft_atoi_exit(const char *str);
t_vector	ft_atovec(char *str, int flag);

#endif
