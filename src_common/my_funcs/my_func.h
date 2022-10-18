/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_func.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:04:50 by sesim             #+#    #+#             */
/*   Updated: 2022/10/18 12:15:42 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_FUNC
# define MY_FUNC

# include "libft.h"

/*****  my open funcs  *****/
int		my_open_rt(const char *path, int oflag);

/*****  my alloc funcs  *****/
void	*my_calloc(size_t count, size_t size);
char	**my_split(char *line, char c);

/*****  my free funcs  *****/
void	split_free(char **split);

/*****  my error funcs  *****/
void	ft_strerror(char *err);

#endif